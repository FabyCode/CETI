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
        $nombre = $_POST['Marca'];

        $sql = "SELECT * FROM marca WHERE marca LIKE '%$nombre%'";
        $result = $conn->query($sql);

        if (!$result) {
            echo "Error en la consulta: " . $conn->error;
        }
    } else {
        $sql = "SELECT * FROM marca";
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
    <title>Mostrar Marca</title>
</head>
<body>
    <h2>Marca</h2>
    <form method="post" action="">
        <label for="Marca">Buscar:</label>
        <input type="text" id="Marca" name="Marca">
        <input type="submit" name="search_name" value="Buscar">
    </form>
    
    <br>
    
    <table border="1">
        <tr>
            <th>ID</th>
            <th>Marca</th>
        </tr>
        <?php 
        if ($result && $result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) { ?>
                <tr>
                    <td><?php echo $row['PK_Marca']; ?></td>
                    <td><?php echo $row['Marca']; ?></td>
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