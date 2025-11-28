<?php
include('config.php');
Date_default_timezone_set('Europe/Copenhagen');
    $conn =  mysqli_connect(DB_SERVER, DB_USER, DB_PASSWORD,DB_NAME) or die("Unable to connect to MySQL");
    //0: temperature
    //1: humidity
    //2: pressures
    //3: light

    if (mysqli_real_escape_string($conn,$_POST['user']) ==NULL ||mysqli_real_escape_string($conn,$_POST['user']) ==NAN){
        $user="NULL";
    }else{
        $user=mysqli_real_escape_string($conn,$_POST['user']);
    }
    if (mysqli_real_escape_string($conn,$_POST['id']) ==NULL){
        $id="NULL";
    }else{
        $id=mysqli_real_escape_string($conn,$_POST['id']);
    }
    $logdate = date("Y-m-d H:i:s");


    $insertSQL=" INSERT INTO ".TB_ENV." (logdate, user, id) 
    values ('".$logdate."',".$user.", ".$id.")";
    mysqli_query($conn,$insertSQL) or die("INSERT Query has Failed - ".$insertSQL );

?>