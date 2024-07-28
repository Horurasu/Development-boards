<?php
	header("Content-Type: application/json");
	
	$conn = new mysqli("localhost", "root",	"","SensorUltrasonico");
	

	if($conn->connect_error){
		die("Error de conexion: ". $conn->connect_error);
	}


	$sql = "SELECT * FROM DataSensor";
	$result = $conn->query($sql);


	$data = array();
	while ($row = $result->fetch_assoc()){
		$data[] = $row;
	}


	$conn->close();


	echo json_encode($data);
?>
