<?php
session_start();
include '../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $departamento = $_POST['departamento'];
    $encargado = $_POST['encargado'];

    if (empty($departamento) || empty($encargado)) {
        $error = "Llene todos los campos.";
    } else {
        $departamento = mysqli_real_escape_string($conn, $departamento);
        $encargado = mysqli_real_escape_string($conn, $encargado);

        $sql = "INSERT INTO departamento (Departamento, Encargado) 
                VALUES ('$departamento', '$encargado')";

        if ($conn->query($sql) === TRUE) {
            echo "Nuevo registro de departamento insertado exitosamente";
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
    <title>Insertar Departamento</title>
</head>
<body>
    <h2>Insertar Departamento</h2>
    <form method="post" action="">
        <label for="departamento">Nombre del Departamento:</label><br>
        <input type="text" id="departamento" name="departamento"><br>
        <label for="encargado">ID del Encargado:</label><br>
        <input type="text" id="encargado" name="encargado"><br><br>
        <input type="submit" value="Insertar">
    </form>
    
    <?php if (!empty($error)) { ?>
        <p><?php echo $error; ?></p>
    <?php } ?>

    <br><br>
    
    <a href="/bd/Insert/insert_ad.php">Volver</a>
</body>
</html>
