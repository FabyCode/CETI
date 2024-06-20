<?php
session_start();
include '../../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

$result = null;

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['search_name'])) {
        $nombre = $_POST['Talla'];

        $sql = "SELECT * FROM pieza WHERE Talla LIKE '%$nombre%'";
        $result = $conn->query($sql);

        if (!$result) {
            echo "Error en la consulta: " . $conn->error;
        }
    } else {
        $sql = "SELECT * FROM departamento";
        $result = $conn->query($sql);

        if (!$result) {
            echo "Error en la consulta: " . $conn->error;
        }
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Mostrar Pieza</title>
</head>
<body>
    <h2>Pieza</h2>
    <form method="post" action="">
        <label for="Talla">Buscar por Talla:</label>
        <input type="text" id="Talla" name="Talla">
        <input type="submit" name="search_name" value="Buscar">
    </form>
    
    <br>
    
    <table border="1">
        <tr>
            <th>ID</th>
            <th>Talla</th>
            <th>Pieza</th>
        </tr>
        <?php 
        if ($result && $result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) { ?>
                <tr>
                    <td><?php echo $row['PK_Pieza']; ?></td>
                    <td><?php echo $row['Talla']; ?></td>
                    <td><?php echo $row['Pieza']; ?></td>
                </tr>
            <?php }
        } else {
            echo "No se encontraron resultados.";
        }
        ?>
    </table>
    
    <br><br>
    
    <a href="/bd/Select/select.php">Volver</a>
</body>
</html>