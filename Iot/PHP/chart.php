
<!doctype html>
<html>
<head>
    <meta http-equiv="refresh" content="60">
    <title>Temp/Humidity</title>
    <script src="Chart.bundle.min.js"></script>
   
</head>
<body>

<form method=""GET" action="chart.php">
Start: <input type="datetime-local" name="begindate" id="begindate" />
End: <input type="datetime-local" name="enddate" id="enddate" />
<input type="submit" />
</form>


<br/>
<<anvas id="temperature" style="width:100%; height:400px;">
<script>
    var ctx = document.getElementById("temperature");
    var config = {
        type: 'line',

        data: {
            labels:,
            datasets:[{
                label:'Temperature',
                fill:false,
                borderColor:'rgba(154,21,7,1)',
                data:,

            }]
        },
        options: {
            responsive:false,
            title:{
                display:true,
                text:'Temperature',
            },
            scales: {
                xAxes: [{
                    display:true,
                }]
            }
        }
    };


        window.temperatureChart = new Chart(ctx, config);
</script>
<canvas id="humidity" style="width:100%; height:400px;"></canvas>
<script>
    var ctx = document.getElementById("humidity");
    var config = {
        type: 'line',
        data: {
            labels:,
            datasets:[{
                label:'Humidity',
                fill:false,
                borderColor:'rgba(7,42,154,1)',
                data:,

            }]
        },
        options: {
            responsive:false,
            title:{
                display:true,
                text:'Humidity',
            }
        }
    };


    window.humidityChart = new Chart(ctx, config);
</script>

</body>
</html>