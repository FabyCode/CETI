<?php
session_start();
include '../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $pieza = $_POST['pieza'];
    $precio = $_POST['precio'];
    $existencia = $_POST['existencia'];
    $marca = $_POST['marca'];
    $departamento = $_POST['departamento'];
    if (empty($pieza) || empty($precio) || empty($existencia) || empty($marca) || empty($departamento)) {
        $error = "Llene todos los campos.";
    } else {
    $pieza = mysqli_real_escape_string($conn, $pieza);
    $precio = mysqli_real_escape_string($conn, $precio);
    $existencia = mysqli_real_escape_string($conn, $existencia);
    $marca = mysqli_real_escape_string($conn, $marca);
    $departamento = mysqli_real_escape_string($conn, $departamento);

    $sql = "INSERT INTO ropa (Pieza, precio, Existencia, Marca, Departamento) 
            VALUES ('$pieza', '$precio', '$existencia', '$marca', '$departamento')";
    
    if ($conn->query($sql) === TRUE) {
        echo "Nuevo registro de ropa insertado exitosamente";
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
    <title>Insertar Ropa</title>
</head>
<body>
    <h2>Insertar Ropa</h2>
    <form method="post" action="">
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
        <input type="submit" value="Insertar">
    </form>
    
    <?php if (!empty($error)) { ?>
        <p><?php echo $error; ?></p>
    <?php } ?>

    <br><br>
    
    <a href="/bd/Insert/insert_ad.php">Volver</a>
</body>
</html>
