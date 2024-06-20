<?php
session_start();
include '../../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['submit'])) {
        $id_marca = $_POST['id_marca'];
        $nombre_marca = $_POST['nombre_marca'];

        if (empty($id_marca) || empty($nombre_marca)) {
            echo "Por favor, complete todos los campos";
        } else {
            $id_marca = mysqli_real_escape_string($conn, $id_marca);
            $nombre_marca = mysqli_real_escape_string($conn, $nombre_marca);

            $sql = "UPDATE marca SET Nombre = '$nombre_marca' WHERE ID_Marca = '$id_marca'";

            if ($conn->query($sql) === TRUE) {
                echo "Registro de marca actualizado correctamente";
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
    <title>Modificar Marca</title>
</head>
<body>
    <h2>Modificar Registro de Marca</h2>
    <form method="post" action="">
        <label for="id_marca">ID de Marca:</label><br>
        <input type="text" id="id_marca" name="id_marca"><br>
        <label for="nombre_marca">Nombre de Marca:</label><br>
        <input type="text" id="nombre_marca" name="nombre_marca"><br><br>
        <input type="submit" name="submit" value="Actualizar">
    </form>
    
    <br><br>
    
    <a href="/bd/Update/update_ad.php">Volver</a>
</body>
</html>