<?php
session_start();
include '../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $nombre = $_POST['nombre'];
    $apeP = $_POST['apeP'];
    $apeM = $_POST['apeM'];
    $aniosTrabajado = $_POST['aniosTrabajado'];
    if (empty($nombre) || empty($apeP) || empty($apeM) || empty($aniosTrabajado)) {
        $error = "Llene todos los campos.";
    } else {
    $nombre = mysqli_real_escape_string($conn, $nombre);
    $apeP = mysqli_real_escape_string($conn, $apeP);
    $apeM = mysqli_real_escape_string($conn, $apeM);
    $aniosTrabajado = mysqli_real_escape_string($conn, $aniosTrabajado);

    $sql = "INSERT INTO empleado (Nombre, ApeP, ApeM, AniosTrabajado) 
            VALUES ('$nombre', '$apeP', '$apeM', '$aniosTrabajado')";
    
    if ($conn->query($sql) === TRUE) {
        echo "Nuevo registro de empleado insertado exitosamente";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
    }
}

$conn->close();
?>

<!DOCTYPE html>
<html>
<head>
    <title>Insertar Empleado</title>
</head>
<body>
    <h2>Insertar Empleado</h2>
    <form method="post" action="">
        <label for="nombre">Nombre:</label><br>
        <input type="text" id="nombre" name="nombre"><br>
        <label for="apeP">Apellido Paterno:</label><br>
        <input type="text" id="apeP" name="apeP"><br>
        <label for="apeM">Apellido Materno:</label><br>
        <input type="text" id="apeM" name="apeM"><br>
        <label for="aniosTrabajado">Años Trabajados:</label><br>
        <input type="text" id="aniosTrabajado" name="aniosTrabajado"><br><br>
        <input type="submit" value="Insertar">
    </form>
    
    <?php if (!empty($error)) { ?>
        <p><?php echo $error; ?></p>
    <?php } ?>

    <br><br>
    
    <a href="/bd/Insert/insert_ad.php">Volver</a>
</body>
</html>