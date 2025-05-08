<!DOCTYPE html>
<html>
<head>
  <title>User Info Table</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      background: #f2f2f2;
      padding: 30px;
    }
    table {
      width: 100%;
      border-collapse: collapse;
      background: #fff;
      box-shadow: 0 4px 8px rgba(0,0,0,0.1);
    }
    th, td {
      border: 1px solid #ddd;
      padding: 12px;
      text-align: left;
    }
    th {
      background-color: #007BFF;
      color: white;
    }
    h2 {
      color: #333;
    }
  </style>
</head>
<body>

<h2>User Information</h2>

<table>
  <thead>
    <tr>
      <th>Name</th>
      <th>Password</th>
      <th>Email</th>
    </tr>
  </thead>
  <tbody>
    <?php
      $file = fopen("users.txt", "r");
      if ($file) {
        while (!feof($file)) {
          $nameLine = trim(fgets($file));
          $passwordLine = trim(fgets($file));
          $emailLine = trim(fgets($file));

          // Ensure all three lines are read
          if ($nameLine && $passwordLine && $emailLine) {
            $name = str_replace("Name: ", "", $nameLine);
            $password = str_replace("Password: ", "", $passwordLine);
            $email = str_replace("Email: ", "", $emailLine);

            echo "<tr>";
            echo "<td>$name</td>";
            echo "<td>$password</td>";
            echo "<td>$email</td>";
            echo "</tr>";
          }
        }
        fclose($file);
      } else {
        echo "<tr><td colspan='3'>Unable to open file.</td></tr>";
      }
    ?>
  </tbody>
</table>

</body>
</html>