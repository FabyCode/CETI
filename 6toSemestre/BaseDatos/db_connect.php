<?php
$servername = "127.0.0.1";
$username = "Admin";
$password = "admin123";
$dbname = "integra";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Conexión fallida: " . $conn->connect_error);
}
?>