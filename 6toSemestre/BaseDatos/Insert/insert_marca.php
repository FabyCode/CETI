<?php
session_start();
include '../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

$error = '';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $marca = $_POST['marca'];

    if (empty($marca)) {
        $error = "Llene el único campo";
    } else {
        $marca = mysqli_real_escape_string($conn, $marca);

        $sql = "INSERT INTO marca (Marca) 
                VALUES ('$marca')";
        
        if ($conn->query($sql) === TRUE) {
            echo "Nuevo registro de marca insertado exitosamente";
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
    <title>Insertar Marca</title>
</head>
<body>
    <h2>Insertar Marca</h2>
    <form method="post" action="">
        <label for="marca">Marca:</label><br>
        <input type="text" id="marca" name="marca"><br><br>
        <input type="submit" value="Insertar">
    </form>

    <?php if (!empty($error)) { ?>
        <p><?php echo $error; ?></p>
    <?php } ?>
    
    <br><br>
    
    <a href="/bd/Insert/insert_ad.php">Volver</a>
</body>
</html>