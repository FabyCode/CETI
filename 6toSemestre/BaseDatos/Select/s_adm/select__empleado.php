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

        $sql = "SELECT * FROM empleado WHERE Nombre LIKE '%$nombre%' OR Apep LIKE '%$nombre%'";
        $result = $conn->query($sql);

        if (!$result) {
            echo "Error en la consulta: " . $conn->error;
        }
    } else {
        $sql = "SELECT * FROM empleado";
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
    <title>Mostrar Empleado</title>
</head>
<body>
    <h2>Empleado</h2>
    <form method="post" action="">
        <label for="nombre">Buscar por Nombre o Apellido Paterno:</label>
        <input type="text" id="nombre" name="nombre">
        <input type="submit" name="search_name" value="Buscar">
    </form>
    
    <br>
    
    <table border="1">
        <tr>
            <th>ID</th>
            <th>Nombre</th>
            <th>Apellido Paterno</th>
            <th>Apellido Materno</th>
            <th>Años Trabajados</th>
        </tr>
        <?php 
        if ($result && $result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) { ?>
                <tr>
                    <td><?php echo $row['Nomina']; ?></td>
                    <td><?php echo $row['Nombre']; ?></td>
                    <td><?php echo $row['ApeP']; ?></td>
                    <td><?php echo $row['ApeM']; ?></td>
                    <td><?php echo $row['AniosTrabajado']; ?></td>
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