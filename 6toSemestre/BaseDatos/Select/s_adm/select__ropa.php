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
        $nombre = $_POST['Precio'];

        $sql = "SELECT * FROM ropa WHERE precio < $nombre";
        $result = $conn->query($sql);

        if (!$result) {
            echo "Error en la consulta: " . $conn->error;
        }
    } else {
        $sql = "SELECT * FROM ropa";
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
    <title>Mostrar Ropa</title>
</head>
<body>
    <h2>Ropa</h2>
    <form method="post" action="">
        <label for="Precio">Buscar por Precio menor a:</label>
        <input type="number" id="Precio" name="Precio">
        <input type="submit" name="search_name" value="Buscar">
    </form>
    
    <br>
    
    <table border="1">
        <tr>
            <th>ID</th>
            <th>Pieza</th>
            <th>Precio</th>
            <th>Existencia</th>
            <th>Marca</th>
            <th>Departamento</th>
        </tr>
        <?php 
        if ($result && $result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) { ?>
                <tr>
                    <td><?php echo $row['PK_Ropa']; ?></td>
                    <td><?php echo $row['Pieza']; ?></td>
                    <td><?php echo $row['precio']; ?></td>
                    <td><?php echo $row['Existencia']; ?></td>
                    <td><?php echo $row['Marca']; ?></td>
                    <td><?php echo $row['Departamento']; ?></td>
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