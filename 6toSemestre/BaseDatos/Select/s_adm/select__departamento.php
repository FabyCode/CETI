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
        $nombre = $_POST['nombre'];

        $sql = "SELECT * FROM departamento WHERE Departamento LIKE '%$nombre%'";
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
    <title>Mostrar Departamento</title>
</head>
<body>
    <h2>Departamento</h2>
    <form method="post" action="">
        <label for="nombre">Buscar por Nombre:</label>
        <input type="text" id="nombre" name="nombre">
        <input type="submit" name="search_name" value="Buscar">
    </form>
    
    <br>
    
    <table border="1">
        <tr>
            <th>ID</th>
            <th>Nombre</th>
            <th>Encargado</th>
        </tr>
        <?php 
        if ($result && $result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) { ?>
                <tr>
                    <td><?php echo $row['PK_dpto']; ?></td>
                    <td><?php echo $row['Departamento']; ?></td>
                    <td><?php echo $row['Encargado']; ?></td>
                </tr>
            <?php }
        } else {
            echo "No se encontraron resultados.";
        }
        ?>
    </table>
    
    <br><br>
    
    <a href="/bd/Select/select_ad.php">Volver</a>
</body>
</html>
