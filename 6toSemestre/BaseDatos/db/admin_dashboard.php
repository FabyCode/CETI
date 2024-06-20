<?php
session_start();

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Panel de Control</title>
</head>
<body>
    <h2>Bienvenido, <?php echo $_SESSION['username']; ?>!</h2>
    <button onclick="window.location.href='/bd/Insert/insert_ad.php'">Insertar</button>
    <button onclick="window.location.href='/bd/Select/select_ad.php'">Seleccionar</button>
    <button onclick="window.location.href='/bd/Update/update_ad.php'">Actualizar</button>
    <button onclick="window.location.href='/bd/Delete/delete_ad.php'">Eliminar</button>
    
    <br><br>
    
    <p>Esta es tu página de control. Tienes el poder del administrador.</p>
    <a href="/bd/logs/logout.php">Cerrar Sesión</a>
</body>
</html>