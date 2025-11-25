
<!doctype html>
<html>
<head>
    <meta http-equiv="refresh" content="60">
    <title>User</title>
    <script src="Chart.bundle.min.js"></script>
   
</head>
<body>

<form method=""GET" action="chart.php">
Start: <input type="datetime-local" name="begindate" id="begindate" />
End: <input type="datetime-local" name="enddate" id="enddate" />
<input type="submit" />
</form>


<br/>
<<anvas id="user" style="width:100%; height:400px;">
<script>
    var ctx = document.getElementById("user");
    var config = {
        type: 'line',

        data: {
            labels:,
            datasets:[{
                label:'user',
                fill:false,
                borderColor:'rgba(154,21,7,1)',
                data:,

            }]
        },
        options: {
            responsive:false,
            title:{
                display:true,
                text:'user Log Over Time',
            },
            scales: {
                xAxes: [{
                    display:true,
                }]
            }
        }
    };


        window.User = new Chart(ctx, config);
</script>
</body>
</html>