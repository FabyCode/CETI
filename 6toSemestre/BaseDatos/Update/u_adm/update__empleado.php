<?php
session_start();
include '../../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['submit'])) {
        $nomina = $_POST['nomina'];
        $nombre = $_POST['nombre'];
        $apellido_paterno = $_POST['apellido_paterno'];
        $apellido_materno = $_POST['apellido_materno'];
        $anios_trabajado = $_POST['anios_trabajado'];

        if (empty($nomina) || empty($nombre) || empty($apellido_paterno) || empty($apellido_materno) || empty($anios_trabajado)) {
            echo "Por favor, completa todos los campos";
        } else {
            $nomina = mysqli_real_escape_string($conn, $nomina);
            $nombre = mysqli_real_escape_string($conn, $nombre);
            $apellido_paterno = mysqli_real_escape_string($conn, $apellido_paterno);
            $apellido_materno = mysqli_real_escape_string($conn, $apellido_materno);
            $anios_trabajado = mysqli_real_escape_string($conn, $anios_trabajado);

            $sql = "UPDATE empleado SET Nombre = '$nombre', Apep = '$apellido_paterno', Apem = '$apellido_materno', AniosTrabajado = '$anios_trabajado' WHERE Nomina = '$nomina'";

            if ($conn->query($sql) === TRUE) {
                echo "Registro de empleado actualizado correctamente";
            } else {
                echo "Error al actualizar el registro: " . $conn->error;
            }
        }
    }
}
$conn->close();
?>
<!DOCTYPE html>
<html>
<head>
    <title>Modificar Empleado</title>
</head>
<body>
    <h2>Modificar Registro de Empleado</h2>
    <form method="post" action="">
        <label for="nomina">Nómina del Empleado:</label><br>
        <input type="text" id="nomina" name="nomina"><br>
        <label for="nombre">Nombre:</label><br>
        <input type="text" id="nombre" name="nombre"><br>
        <label for="apellido_paterno">Apellido Paterno:</label><br>
        <input type="text" id="apellido_paterno" name="apellido_paterno"><br>
        <label for="apellido_materno">Apellido Materno:</label><br>
        <input type="text" id="apellido_materno" name="apellido_materno"><br>
        <label for="anios_trabajados">Años Trabajados:</label><br>
        <input type="text" id="anios_trabajado" name="anios_trabajado"><br><br>
        <input type="submit" name="submit" value="Actualizar">
    </form>
    
    <br><br>
    
    <a href="/bd/Update/update_ad.php">Volver</a>
</body>
</html>