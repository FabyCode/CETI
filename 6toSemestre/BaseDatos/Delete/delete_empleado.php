<?php
session_start();
include '../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

$result = null;

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['delete_empleado'])) {
        $nombre = $_POST['nombre'];
        $apellido_paterno = $_POST['apellido_paterno'];

        $check_sql = "SELECT * FROM empleado WHERE Nombre = '$nombre' AND Apep = '$apellido_paterno'";
        $check_result = $conn->query($check_sql);

        if ($check_result->num_rows > 0) {
            $sql = "DELETE FROM empleado WHERE Nombre = '$nombre' AND Apep = '$apellido_paterno'";
            $result = $conn->query($sql);

            if ($result) {
                echo "Registro de empleado eliminado exitosamente.";
            } else {
                echo "Error al eliminar el registro: " . $conn->error;
            }
        } else {
            echo "No se encontró ninguna fila con ese nombre y apellido.";
        }
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Eliminar Empleado</title>
</head>
<body>
    <h2>Eliminar Empleado</h2>
    <form method="post" action="">
        <label for="nombre">Nombre del Empleado:</label>
        <input type="text" id="nombre" name="nombre">
        <label for="apellido_paterno">Apellido Paterno:</label>
        <input type="text" id="apellido_paterno" name="apellido_paterno">
        <input type="submit" name="delete_empleado" value="Eliminar">
    </form>
    
    <br><br>

    <?php
    $sql = "SELECT Nomina, Nombre, ApeP, ApeM FROM empleado";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        echo "<table border='1'>
        <tr>
        <th>Nomina</th>
        <th>Nombre</th>
        <th>Apellidos</th>
        <th></th>
        </tr>";
        while ($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>" . $row['Nomina'] . "</td>";
            echo "<td>" . $row['Nombre'] . "</td>";
            echo "<td>" . $row['ApeP'] . "</td>";
            echo "<td>" . $row['ApeM'] . "</td>";
            echo "</tr>";
        }
        echo "</table>";
    } else {
        echo "0 resultados";
    }
    ?>
    
    <br><br>
    
    <a href="delete_ad.php">Volver</a>
</body>
</html>