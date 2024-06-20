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
    <title>Delete</title>
</head>
<body>
    <h2>Eliminar Datos</h2>
    <button onclick="window.location.href='delete_departamento.php'">Departamento</button>
    <button onclick="window.location.href='delete_empleado.php'">Empleado</button>
    <button onclick="window.location.href='delete_marca.php'">Marca</button>
    <button onclick="window.location.href='delete_pieza.php'">Pieza</button>
    <button onclick="window.location.href='delete_ropa.php'">Ropa</button>
    
    <br><br>
    
    <a href="/bd/db/admin_dashboard.php">Volver</a>
</body>
</html>