<?php
session_start();
include '../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

$result = null;
$nombre_departamento = "";
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['delete_departamento'])) {
        $nombre_departamento = $_POST['nombre_departamento'];

        $check_sql = "SELECT * FROM departamento WHERE Departamento = '$nombre_departamento'";
        $check_result = $conn->query($check_sql);

        if ($check_result->num_rows > 0) {
            $sql = "DELETE FROM departamento WHERE Departamento = '$nombre_departamento'";
            $result = $conn->query($sql);

            if ($result) {
                echo "Registro del departamento eliminado exitosamente.";
            } else {
                echo "Error al eliminar el registro: " . $conn->error;
            }
        } else {
            echo "No se encontró ningún departamento con ese nombre.";
        }
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Eliminar Departamento</title>
</head>
<body>
    <h2>Eliminar Departamento</h2>
    <form method="post" action="">
        <label for="nombre_departamento">Nombre del Departamento:</label>
        <input type="text" id="nombre_departamento" name="nombre_departamento" value="<?php echo $nombre_departamento; ?>">
        <input type="submit" name="delete_departamento" value="Eliminar">
    </form>
    
    <br><br>
    
    <?php
    $sql = "SELECT * FROM departamento";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        echo "<table border='1'>
        <tr>
        <th>ID</th>
        <th>Nombre del Departamento</th>
        </tr>";
        while ($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>" . $row['PK_dpto'] . "</td>";
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