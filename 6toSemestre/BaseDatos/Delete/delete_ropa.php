<?php
session_start();
include '../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

$result = null;

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['delete_ropa'])) {
        $pk_ropa = $_POST['pk_ropa'];

        $check_sql = "SELECT * FROM ropa WHERE PK_Ropa = $pk_ropa";
        $check_result = $conn->query($check_sql);

        if ($check_result->num_rows > 0) {
            $sql = "DELETE FROM ropa WHERE PK_Ropa = $pk_ropa";
            $result = $conn->query($sql);

            if ($result) {
                echo "Registro de ropa eliminado exitosamente.";
            } else {
                echo "Error al eliminar el registro: " . $conn->error;
            }
        } else {
            echo "No se encontró ninguna fila con esa ID de Ropa.";
        }
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Eliminar Ropa</title>
</head>
<body>
    <h2>Eliminar Ropa</h2>
    <form method="post" action="">
        <label for="pk_ropa">ID de Ropa:</label>
        <input type="text" id="pk_ropa" name="pk_ropa">
        <input type="submit" name="delete_ropa" value="Eliminar">
    </form>
    
    <br><br>
    
    <?php
    $sql = "SELECT * FROM ropa";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        echo "<table border='1'>
        <tr>
        <th>ID</th>
        <th>Pieza</th>
        <th>Precio</th>
        <th>Existencia</th>
        <th>Marca</th>
        <th>Departamento</th>
        </tr>";
        while ($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>" . $row['PK_Ropa'] . "</td>";
            echo "<td>" . $row['Pieza'] . "</td>";
            echo "<td>" . $row['precio'] . "</td>";
            echo "<td>" . $row['Existencia'] . "</td>";
            echo "<td>" . $row['Marca'] . "</td>";
            echo "<td>" . $row['Departamento'] . "</td>";
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