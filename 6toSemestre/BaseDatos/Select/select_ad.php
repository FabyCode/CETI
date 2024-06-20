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
    <title>Mostrar</title>
</head>
<body>
    <h2>Mostrar</h2>
    <button onclick="window.location.href='s_adm/select__departamento.php'">Departamento</button>
    <button onclick="window.location.href='s_adm/select__empleado.php'">Empleado</button>
    <button onclick="window.location.href='s_adm/select__marca.php'">Marca</button>
    <button onclick="window.location.href='s_adm/select__pieza.php'">Pieza</button>
    <button onclick="window.location.href='s_adm/select__ropa.php'">Ropa</button>
    <button onclick="window.location.href='s_adm/select__registros.php'">Registros</button>
    
    <br>

    <h2>Vistas</h2>
    <button onclick="window.location.href='s_adm/select__v_encargados.php'">Encargados</button>
    <button onclick="window.location.href='s_adm/select__v_prendas.php'">Prendas</button>

    <br>
    <h2>Procedimiento</h2>
    <button onclick="window.location.href='s_adm/procedure_agotandose.php'">Agotandose</button>

    <br><br>
    
    <a href="/bd/db/admin_dashboard.php">Volver</a>
</body>
</html>