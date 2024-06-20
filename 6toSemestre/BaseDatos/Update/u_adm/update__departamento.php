<?php
session_start();
include '../../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['submit'])) {
        $pk_dpto = $_POST['pk_dpto'];
        $nombre = $_POST['nombre'];
        $encargado = $_POST['encargado'];

        if (empty($pk_dpto) || empty($nombre) || empty($encargado)) {
            echo "Por favor, complete todos los campos";
        } else {
            $pk_dpto = mysqli_real_escape_string($conn, $pk_dpto);
            $nombre = mysqli_real_escape_string($conn, $nombre);
            $encargado = mysqli_real_escape_string($conn, $encargado);

            $sql = "UPDATE departamento SET Departamento = '$nombre', Encargado = '$encargado' WHERE PK_dpto = '$pk_dpto'";

            if ($conn->query($sql) === TRUE) {
                echo "Registro de departamento actualizado correctamente";
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
    <title>Modificar Departamento</title>
</head>
<body>
    <h2>Modificar Registro de Departamento</h2>
    <form method="post" action="">
        <label for="pk_dpto">ID de Departamento:</label><br>
        <input type="text" id="pk_dpto" name="pk_dpto"><br>
        <label for="Departamento">Nombre:</label><br>
        <input type="text" id="nombre" name="nombre"><br>
        <label for="encargado">Encargado:</label><br>
        <input type="text" id="encargado" name="encargado"><br><br>
        <input type="submit" name="submit" value="Actualizar">
    </form>
    
    <br><br>
    
    <a href="/bd/Update/update_ad.php">Volver</a>
</body>
</html>