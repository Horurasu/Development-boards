<?php
header("Content-Type: application/json");

$requestMethod = $_SERVER["REQUEST_METHOD"];

switch($requestMethod) {
   case 'GET':
      handleGetRequest();
      break;
   case 'POST':
      handlePostRequest();
      break;
   case 'PUT':
      handlePutRequest();
      break;
   case 'DELETE':
      handleDeleteRequest();
      break;
   default:
      echo json_encode(["message" => "Method not supported"]);
      break;
}

function handleGetRequest() {
   // Handle GET request
   echo json_encode(["message" => "GET request received"]);
}

function handlePostRequest() {
   // Handle POST request
   echo json_encode(["message" => "POST request received"]);
}

function handlePutRequest() {
   // Handle PUT request
   echo json_encode(["message" => "PUT request received"]);
}

function handleDeleteRequest() {
   // Handle DELETE request
   echo json_encode(["message" => "DELETE request received"]);
}
?>