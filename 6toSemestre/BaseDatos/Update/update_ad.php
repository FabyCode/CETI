<?php
session_start();
include '../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Actualizar</title>
</head>
<body>
    <h2>Actualizar</h2>
    <button onclick="window.location.href='u_adm/update__departamento.php'">Departamento</button>
    <button onclick="window.location.href='u_adm/update__empleado.php'">Empleado</button>
    <button onclick="window.location.href='u_adm/update__marca.php'">Marca</button>
    <button onclick="window.location.href='u_adm/update__pieza.php'">Pieza</button>
    <button onclick="window.location.href='u_adm/update__ropa.php'">Ropa</button>

    <br><br>
    
    <a href="/bd/db/admin_dashboard.php">Volver</a>
</body>
</html>