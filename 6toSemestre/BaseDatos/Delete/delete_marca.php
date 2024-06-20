<?php
session_start();
include '../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

$result = null;

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['delete_marca'])) {
        $marca = $_POST['marca'];

        $check_sql = "SELECT * FROM marca WHERE Marca = '$marca'";
        $check_result = $conn->query($check_sql);

        if ($check_result->num_rows > 0) {
            $sql = "DELETE FROM marca WHERE Marca = '$marca'";
            $result = $conn->query($sql);

            if ($result) {
                echo "Registro de marca eliminado exitosamente.";
            } else {
                echo "Error al eliminar el registro: " . $conn->error;
            }
        } else {
            echo "No se encontró ninguna fila con esa marca.";
        }
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Eliminar Marca</title>
</head>
<body>
    <h2>Eliminar Marca</h2>
    <form method="post" action="">
        <label for="marca">Nombre de Marca a Eliminar:</label>
        <input type="text" id="marca" name="marca">
        <input type="submit" name="delete_marca" value="Eliminar">
    </form>
    
    <br><br>

    <?php
    $sql = "SELECT * FROM marca";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        echo "<table border='1'>
        <tr>
        <th>ID</th>
        <th>Marca</th>
        </tr>";
        while ($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>" . $row['PK_Marca'] . "</td>";
            echo "<td>" . $row['Marca'] . "</td>";
            echo "</tr>";
        }
        echo "</table>";
    } else {
        echo "0 resultados";
    }
    ?>
    
    <br><br>
    
    <a href="delete_ad.php">Volver</a>
</body>
</html>