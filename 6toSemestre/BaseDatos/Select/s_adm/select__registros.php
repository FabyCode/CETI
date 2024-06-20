<?php
session_start();
include '../../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

$result = null;

        $sql = "SELECT * FROM avisos";
        $result = $conn->query($sql);

        if (!$result) {
            echo "Error en la consulta: " . $conn->error;
        }
?>

<!DOCTYPE html>
<html>
<head>
    <title>Avisos</title>
</head>
<body>
    <h2>Notificaciones de Cambio</h2>
    
    <table border="2">
        <tr>
            <th>ID</th>
            <th>Aviso</th>
            <th>Fecha</th>
            <th>Ropa</th>
            <th>E. Anterior</th>
            <th>E. Nueva</th>
        </tr>
        <?php 
        if ($result && $result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) { ?>
                <tr>
                    <td><?php echo $row['PK_Avisos']; ?></td>
                    <td><?php echo $row['Aviso']; ?></td>
                    <td><?php echo $row['Fecha']; ?></td>
                    <td><?php echo $row['Ropa']; ?></td>
                    <td><?php echo $row['existencia_anterior']; ?></td>
                    <td><?php echo $row['existencia_nueva']; ?></td>
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