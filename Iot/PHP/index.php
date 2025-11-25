<!--<!doctype html>
<html>
    <body>
        <div>
         <a>
            <link
            href="chart.php" target="_blank">
            <table id="table" class="table table-hover table-mc-light-blue">
                <thead>
                    <tr>
                        <th>User</th>
                        <th>Id</th>
                        <th>LogDate</th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                    <td data-title="user"><?php //echo $rows["user"]?></td>
                    <td data-title="id"><?php //echo $rows["id"]?></td>
                    <td data-title="logdate"><?php //echo $rows["logdate"]?></td>
                    </tr>
                </tbody>
            </table>
         </a>
        </div>
    </body>
</html>
-->

<!-- PHP code to establish connection with the localserver -->
<?php
include('config.php');

// Username is root
/*$user = 'lmh_hx2_hold1_dk';
$password = 'jzWw4yZ7P6D33stxqA4X6no5';

// Database name is geeksforgeeks
$database = 'lmh-hx2-hold1.dk.mysql';

// Server is localhost with
// port number 3306
$servername='lmh_hx2_hold1_dk:22';
$ENV='IoT_Lock';
$conn = new$conn($servername, $user, $password, $database, $ENV,);
*/
$conn =  mysqli_connect(DB_SERVER, DB_USER, DB_PASSWORD,DB_NAME) or die("Unable to connect to MySQL");

// Checking for connections
if ($conn->connect_error) {
    die('Connect Error (' .
    $conn->connect_errno . ') '.
    $conn->connect_error);
}

// SQL query to select data from database
$sql = " SELECT * FROM IoT_Lock ORDER BY id DESC ";
$result = $conn->query($sql);
$conn->close();
?>
<!-- HTML code to display data in tabular format -->
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <title>GFG User Details</title>
    <!-- CSS FOR STYLING THE PAGE -->
    <style>
        table {
            margin: 0 auto;
            font-size: large;
            border: 1px solid black;
        }

        h1 {
            text-align: center;
            color: #006600;
            font-size: xx-large;
            font-family: 'Gill Sans', 'Gill Sans MT',
            ' Calibri', 'Trebuchet MS', 'sans-serif';
        }

        td {
            background-color: #E4F5D4;
            border: 1px solid black;
        }

        th,
        td {
            font-weight: bold;
            border: 1px solid black;
            padding: 10px;
            text-align: center;
        }

        td {
            font-weight: lighter;
        }
    </style>
</head>

<body>
    <section>
        <h1>IoT_Lock</h1>
        <!-- TABLE CONSTRUCTION -->
        <table>
            <tr>
                <th>User</th>
                <th>ID</th>
                <th>LogDate</th>
            </tr>
            <!-- PHP CODE TO FETCH DATA FROM ROWS -->
            <?php 
                // LOOP TILL END OF DATA
                while($rows=$result->fetch_assoc())
                {
            ?>
            <tr>
                <!-- FETCHING DATA FROM EACH
                    ROW OF EVERY COLUMN -->
                <td><?php echo $rows['id'];?></td>
                <td><?php echo $rows['logdate'];?></td>
                <td><?php echo $rows['user'];?></td>
            </tr>
            <?php
                }
            ?>
        </table>
    </section>
</body>

</html>