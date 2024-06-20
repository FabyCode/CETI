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
    <title>Buscar</title>
</head>
<body>
    <h2>Buscar</h2>
    <button onclick="window.location.href='s_emp/select_departamento.php'">Departamento</button>
    <button onclick="window.location.href='s_emp/select_marca.php'">Marca</button>
    <button onclick="window.location.href='s_emp/select_pieza.php'">Pieza</button>
    <button onclick="window.location.href='s_emp/select_ropa.php'">Ropa</button>
    <button onclick="window.location.href='s_emp/select_registros.php'">Registros</button>
    
    <br>

    <h2>Vistas</h2>
    <button onclick="window.location.href='s_emp/select_v_encargados.php'">Encargados</button>
    <button onclick="window.location.href='s_emp/select_v_prendas.php'">Prendas</button>

    <br>
    <h2>Procedimiento</h2>
    <button onclick="window.location.href='s_emp/procedure_agotandose.php'">Agotandose</button>

    <br><br>
    
    <a href="/bd/db/emp_dashboard.php">Volver</a>
</body>
</html>