<?php
session_start();
include '../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

$error = '';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $talla = $_POST['talla'];
    $pieza = $_POST['pieza'];

    if (empty($talla) || empty($pieza)) {
        $error = "Llene todos los campos.";
    } else {
        $talla = mysqli_real_escape_string($conn, $talla);
        $pieza = mysqli_real_escape_string($conn, $pieza);

        $sql = "INSERT INTO pieza (Talla, Pieza) 
                VALUES ('$talla', '$pieza')";
        
        if ($conn->query($sql) === TRUE) {
            echo "Nuevo registro de pieza insertado exitosamente";
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
    <title>Insertar Pieza</title>
</head>
<body>
    <h2>Insertar Pieza</h2>
    <form method="post" action="">
        <label for="talla">Talla:</label><br>
        <input type="text" id="talla" name="talla"><br>
        <label for="pieza">Pieza:</label><br>
        <input type="text" id="pieza" name="pieza"><br><br>
        <input type="submit" value="Insertar">
    </form>

    <?php if (!empty($error)) { ?>
        <p><?php echo $error; ?></p>
    <?php } ?>
    
    <br><br>
    
    <a href="/bd/Insert/insert_ad.php">Volver</a>
</body>
</html>