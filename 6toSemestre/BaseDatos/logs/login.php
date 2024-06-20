<?php
session_start();
include '../db_connect.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST['username'];
    $password = $_POST['password'];

    $username = mysqli_real_escape_string($conn, $username);
    $password = mysqli_real_escape_string($conn, $password);

    $sql = "SELECT * FROM users WHERE username = '$username' AND password = '$password'";
    $result = $conn->query($sql);

    if ($result->num_rows == 1) {
        $_SESSION['loggedin'] = true;
        $_SESSION['username'] = $username;

        if (strpos($username, 'Admin') !== false) {
            header("Location: /bd/db/admin_dashboard.php");
            exit;
        } else {
            header("Location: /bd/db/emp_dashboard.php");
            exit;
        }
    } else {
        header("Location: login_css.php?error=1");
        exit;
    }
}

$conn->close();
?>