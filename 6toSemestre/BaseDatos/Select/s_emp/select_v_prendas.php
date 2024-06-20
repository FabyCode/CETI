<?php
session_start();
include '../../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

$result = null;

        $sql = "SELECT * FROM v_prenda";
        $result = $conn->query($sql);

        if (!$result) {
            echo "Error en la consulta: " . $conn->error;
        }
?>

<!DOCTYPE html>
<html>
<head>
    <title>Vista Prendas</title>
</head>
<body>
    <h2>Prenda</h2>
    
    <table border="1">
        <tr>
            <th>Pieza</th>
            <th>Talla</th>
            <th>Existencia</th>
            <th>Precio</th>
        </tr>
        <?php 
        if ($result && $result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) { ?>
                <tr>
                    <td><?php echo $row['pieza']; ?></td>
                    <td><?php echo $row['talla']; ?></td>
                    <td><?php echo $row['existencia']; ?></td>
                    <td><?php echo $row['Precio']; ?></td>
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