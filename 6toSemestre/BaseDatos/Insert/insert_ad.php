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
    <title>Insert</title>
</head>
<body>
    <h2>Insertar Datos</h2>
    <button onclick="window.location.href='insert_departamento.php'">Departamento</button>
    <button onclick="window.location.href='insert_empleado.php'">Empleado</button>
    <button onclick="window.location.href='insert_marca.php'">Marca</button>
    <button onclick="window.location.href='insert_pieza.php'">Pieza</button>
    <button onclick="window.location.href='insert_ropa.php'">Ropa</button>
    
    <br><br>
    
    <a href="/bd/db/admin_dashboard.php">Volver</a>
</body>
</html>