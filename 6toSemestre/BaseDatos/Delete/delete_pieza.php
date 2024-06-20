<?php
session_start();
include '../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

$result = null;

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['delete_pieza'])) {
        $pk_pieza = $_POST['pk_pieza'];

        $check_sql = "SELECT * FROM pieza WHERE PK_Pieza = $pk_pieza";
        $check_result = $conn->query($check_sql);

        if ($check_result->num_rows > 0) {
            $sql = "DELETE FROM pieza WHERE PK_Pieza = $pk_pieza";
            $result = $conn->query($sql);

            if ($result) {
                echo "Registro de pieza eliminado exitosamente.";
            } else {
                echo "Error al eliminar el registro: " . $conn->error;
            }
        } else {
            echo "No se encontró ninguna fila con esa ID de Pieza.";
        }
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Eliminar Pieza</title>
</head>
<body>
    <h2>Eliminar Pieza</h2>
    <form method="post" action="">
        <label for="pk_pieza">ID de Pieza:</label>
        <input type="text" id="pk_pieza" name="pk_pieza">
        <input type="submit" name="delete_pieza" value="Eliminar">
    </form>
    
    <br><br>
    
    <?php
    $sql = "SELECT * FROM pieza";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        echo "<table border='1'>
        <tr>
        <th>ID</th>
        <th>Talla</th>
        <th>Pieza</th>
        </tr>";
        while ($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>" . $row['PK_Pieza'] . "</td>";
            echo "<td>" . $row['Talla'] . "</td>";
            echo "<td>" . $row['Pieza'] . "</td>";
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