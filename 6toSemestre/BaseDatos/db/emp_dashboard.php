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
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f4;
            margin: 0;
            padding: 20px;
            text-align: center;
        }

        h2 {
            color: #333;
        }

        p {
            color: #555;
        }

        .container {
            border: 1px solid #ccc;
            border-radius: 5px;
            padding: 20px;
            display: inline-block;
        }

        .options-box {
            border: 1px solid #ccc;
            border-radius: 5px;
            padding: 20px;
            display: inline-block;
        }

        button {
            padding: 10px 20px;
            margin: 10px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            background-color: #18B1E1;
            color: white;
            font-size: 16px;
            transition: background-color 0.3s ease;
        }

        button:hover {
            background-color: #0198C8;
        }

        a {
            display: block;
            margin-top: 20px;
            text-decoration: none;
            color: #333;
        }

        a:hover {
            color: #000;
        }
    </style>
</head>
<body>
    <div class="container">
        <h2>Bienvenido, <?php echo $_SESSION['username']; ?>!</h2>
        <p>¿Qué acción desea realizar?</p>
        <div class="options-box">
            <button onclick="window.location.href='/bd/Select/select.php'">Buscar</button>
            <button onclick="window.location.href='/bd/Update/update.php'">Vender</button>
        </div>
    </div>
    
    <br><br>
    <a href="/bd/logs/logout.php">Cerrar Sesión</a>
</body>
</html>