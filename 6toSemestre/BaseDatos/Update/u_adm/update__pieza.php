<?php
session_start();
include '../../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['submit'])) {
        $pk_pieza = $_POST['pk_pieza'];
        $talla = $_POST['talla'];
        $pieza = $_POST['pieza'];

        if (empty($pk_pieza) || empty($talla) || empty($pieza)) {
            echo "Por favor, complete todos los campos";
        } else {
            $pk_pieza = mysqli_real_escape_string($conn, $pk_pieza);
            $talla = mysqli_real_escape_string($conn, $talla);
            $pieza = mysqli_real_escape_string($conn, $pieza);

            $sql = "UPDATE pieza SET Talla = '$talla', Pieza = '$pieza' WHERE PK_Pieza = '$pk_pieza'";

            if ($conn->query($sql) === TRUE) {
                echo "Registro de pieza actualizado correctamente";
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
    <title>Modificar Pieza</title>
</head>
<body>
    <h2>Modificar Registro de Pieza</h2>
    <form method="post" action="">
        <label for="pk_pieza">ID de Pieza:</label><br>
        <input type="text" id="pk_pieza" name="pk_pieza"><br>
        <label for="talla">Talla:</label><br>
        <input type="text" id="talla" name="talla"><br>
        <label for="pieza">Pieza:</label><br>
        <input type="text" id="pieza" name="pieza"><br><br>
        <input type="submit" name="submit" value="Actualizar">
    </form>
    
    <br><br>
    
    <a href="/bd/Update/update_ad.php">Volver</a>
</body>
</html>