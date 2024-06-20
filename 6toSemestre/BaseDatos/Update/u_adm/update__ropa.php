<?php
session_start();
include '../../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['submit'])) {
        $pk_ropa = $_POST['pk_ropa'];
        $pieza = $_POST['pieza'];
        $precio = $_POST['precio'];
        $existencia = $_POST['existencia'];
        $marca = $_POST['marca'];
        $departamento = $_POST['departamento'];

        if (empty($pk_ropa) || empty($pieza) || empty($precio) || empty($existencia) || empty($marca) || empty($departamento)) {
            echo "Por favor, complete todos los campos";
        } else {
            $pk_ropa = mysqli_real_escape_string($conn, $pk_ropa);
            $pieza = mysqli_real_escape_string($conn, $pieza);
            $precio = mysqli_real_escape_string($conn, $precio);
            $existencia = mysqli_real_escape_string($conn, $existencia);
            $marca = mysqli_real_escape_string($conn, $marca);
            $departamento = mysqli_real_escape_string($conn, $departamento);

            $sql = "UPDATE ropa SET Pieza = '$pieza', Precio = '$precio', Existencia = '$existencia', Marca = '$marca', Departamento = '$departamento' WHERE PK_Ropa = '$pk_ropa'";

            if ($conn->query($sql) === TRUE) {
                echo "Registro de ropa actualizado correctamente";
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
    <title>Modificar Ropa</title>
</head>
<body>
    <h2>Modificar Registro de Ropa</h2>
    <form method="post" action="">
        <label for="pk_ropa">ID de Ropa:</label><br>
        <input type="text" id="pk_ropa" name="pk_ropa"><br>
        <label for="pieza">Pieza:</label><br>
        <input type="text" id="pieza" name="pieza"><br>
        <label for="precio">Precio:</label><br>
        <input type="text" id="precio" name="precio"><br>
        <label for="existencia">Existencia:</label><br>
        <input type="text" id="existencia" name="existencia"><br>
        <label for="marca">Marca:</label><br>
        <input type="text" id="marca" name="marca"><br>
        <label for="departamento">Departamento:</label><br>
        <input type="text" id="departamento" name="departamento"><br><br>
        <input type="submit" name="submit" value="Actualizar">
    </form>
    
    <br><br>
    
    <a href="/bd/Update/update_ad.php">Volver</a>
</body>
</html>