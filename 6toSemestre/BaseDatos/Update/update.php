<?php
session_start();
include '../db_connect.php';

if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: /bd/logs/login.php");
    exit;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $pk_ropa = $_POST['pk_ropa'];
    $cantidad_vendida = $_POST['cantidad_vendida'];

    if ($conn !== null) {
        $check_sql = "SELECT * FROM ropa WHERE PK_Ropa = $pk_ropa";
        $check_result = $conn->query($check_sql);

        if ($check_result && $check_result->num_rows > 0) {
            $update_sql = "UPDATE ropa SET Existencia = Existencia - $cantidad_vendida WHERE PK_Ropa = $pk_ropa";
            $update_result = $conn->query($update_sql);

            if ($update_result) {
                echo "Existencia actualizada exitosamente.";
            } else {
                echo "Error al actualizar la existencia: " . $conn->error;
            }
        } else {
            echo "No se encontró ninguna fila con esa ID de Ropa.";
        }
    } else {
        echo "Error: La conexión a la base de datos no está disponible.";
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Actualizar Existencia de Ropa</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f4;
            margin: 0;
            padding: 0;
        }

        .action-bar {
            display: flex;
            justify-content: flex-start;
            align-items: center;
            background-color: #fff;
            border-bottom: 1px solid #ccc;
            padding: 10px;
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
            z-index: 1000;
        }

        .form-container {
            display: flex;
            flex-direction: column;
            align-items: flex-start;
            width: 30%;
            padding: 20px;
            border: 1px solid #ccc;
            border-radius: 5px;
            background-color: #E6E6E6;
        }

        .form-container input[type="text"],
        .form-container input[type="submit"] {
            width: calc(100% - 22px);
            padding: 8px;
            margin-bottom: 10px;
            border: 1px solid #ccc;
            border-radius: 3px;
            
        }

        .table-container {
            width: 70%;
            margin-top: 60px;
            padding: 20px;
            border: 1px solid #ccc;
            border-radius: 5px;
            background-color: #fff;
        }

        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }

        th, td {
            border: 1px solid #029CCD;
            padding: 8px;
            text-align: left;
        }

        th {
            background-color: #18B1E1;
        }

        a {
            display: block;
            text-align: center;
            margin-top: 20px;
            text-decoration: none;
            color: #000;
        }

        a:hover {
            color: #0198C8;
        }
    </style>
</head>
<body>
    <div class="action-bar">
        <a href="/bd/db/emp_dashboard.php">Volver</a>
    </div>

    <div style="display: flex;">
        <div class="form-container">
            <h2>Actualizar Existencia de Ropa</h2>
            <form method="post" action="">
                <label for="pk_ropa">ID de Ropa:</label>
                <input type="text" id="pk_ropa" name="pk_ropa">
                <label for="cantidad_vendida">Cantidad Vendida:</label>
                <input type="text" id="cantidad_vendida" name="cantidad_vendida">
                <input type="submit" name="actualizar_existencia" value="Actualizar">
            </form>
        </div>

        <div class="table-container">
            <?php
            $sql = "SELECT ropa.PK_Ropa, pieza.Pieza, pieza.Talla, ropa.precio, ropa.Existencia FROM ropa INNER JOIN pieza ON pieza.PK_Pieza = ropa.Pieza";
            $result = $conn->query($sql);
            if ($result->num_rows > 0) {
                echo "<table>
                <tr>
                <th>ID</th>
                <th>Pieza</th>
                <th>Talla</th>
                <th>Precio</th>
                <th>Existencia</th>
                </tr>";
                while ($row = $result->fetch_assoc()) {
                    echo "<tr>";
                    echo "<td>" . $row['PK_Ropa'] . "</td>";
                    echo "<td>" . $row['Pieza'] . "</td>";
                    echo "<td>" . $row['Talla'] . "</td>";
                    echo "<td>" . $row['precio'] . "</td>";
                    echo "<td>" . $row['Existencia'] . "</td>";
        
                    echo "</tr>";
                }
                echo "</table>";
            } else {
                echo "0 resultados";
            }
            ?>
            
            <br><br>
        
        </div>
    </div>
</body>
</html>