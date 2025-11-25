<?php
include('config.php');
    $conn =  mysqli_connect(DB_SERVER, DB_USER, DB_PASSWORD,DB_NAME) or die("Unable to connect to MySQL");
    //0: user

    if (mysqli_real_escape_string($conn,$_POST['user']) ==NULL ||mysqli_real_escape_string($conn,$_POST['user']) ==NAN){
        $user="NULL";
    }else{
        $user=mysqli_real_escape_string($conn,$_POST['user']);
    }
    if (mysqli_real_escape_string($conn,$_POST['id']) ==NULL ||mysqli_real_escape_string($conn,$_POST['id']) ==NAN){
       $id="NULL";
    }else{
        $user=mysqli_real_escape_string($conn,$_POST['id']);
    }
    $logdate= date("Y-m-d H:i:s");

    $insertSQL="INSERT into ".TB_ENV." (logdate,user) values ('".$logdate."',".$user.",".$id.")";
    mysqli_query($conn,$insertSQL) or die("INSERT Query has Failed - ".$insertSQL );

?>