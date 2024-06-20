<!DOCTYPE html>
<html>
<head>
    <title>Iniciar Sesión</title>
    <style>
        body {
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
        }

        form {
            width: 300px;
            padding: 20px;
            border: 1px solid #ccc;
            border-radius: 5px;
            display: flex;
            flex-direction: column;
        }

        label {
            margin-bottom: 5px;
        }

        input[type="text"],
        input[type="password"],
        input[type="submit"] {
            width: calc(100% - 22px);
            padding: 10px;
            margin-bottom: 10px;
            box-sizing: border-box;
            border: 1px solid #ccc;
        }

        input[type="submit"] {
            background-color: #18B1E1;
            color: white;
            border: none;
            cursor: pointer;
        }

        input[type="submit"]:hover {
            background-color: #0198C8;
        }
    </style>
</head>
<body>
    <form method="post" action="login.php">
        <label for="username">Nombre de usuario:</label>
        <input type="text" id="username" name="username">
        <label for="password">Contraseña:</label>
        <input type="password" id="password" name="password">
        <input type="submit" value="Iniciar Sesión">
    </form>
</body>
</html>