<?php
session_start();
include '../../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

$result = null;

        $sql = "SELECT * FROM v_encargados";
        $result = $conn->query($sql);

        if (!$result) {
            echo "Error en la consulta: " . $conn->error;
        }
?>

<!DOCTYPE html>
<html>
<head>
    <title>Vista Encargados</title>
</head>
<body>
    <h2>Encargados</h2>
    
    <table border="1">
        <tr>
            <th>Departamento</th>
            <th>Nombre</th>
            <th>A_Paterno</th>
            <th>A_Materno</th>
            <th>Nomina</th>
        </tr>
        <?php 
        if ($result && $result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) { ?>
                <tr>
                    <td><?php echo $row['Dpto']; ?></td>
                    <td><?php echo $row['Nombre']; ?></td>
                    <td><?php echo $row['ApeP']; ?></td>
                    <td><?php echo $row['ApeM']; ?></td>
                    <td><?php echo $row['nomina']; ?></td>
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