#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "";
const char* password = "";
const int ledPin = 2;

WebServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); 

  // Conectar a la red WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a la red WiFi...");
  }

  Serial.println("Conexión WiFi establecida.");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());

  // Rutas para manejar las solicitudes HTTP
  server.on("/", HTTP_GET, []() {
    String content = "<h1>Bienvenido al ESP32 Web Server</h1>";
    content += "<p>Dirección IP del servidor: ";
    content += "<p>Control del LED:</p>";
    content += "<a href=\"/encender\"><button>Encender LED</button></a>&nbsp;";
    content += "<a href=\"/apagar\"><button>Apagar LED</button></a>";
    server.send(200, "text/html", content);
  });

  server.on("/encender", HTTP_GET, []() {
    digitalWrite(ledPin, HIGH);
    server.sendHeader("Location", "/");
    server.send(303);
  });

  server.on("/apagar", HTTP_GET, []() {
    digitalWrite(ledPin, LOW);
    server.sendHeader("Location", "/");
    server.send(303);
  });

  server.begin();
  Serial.println("Servidor HTTP iniciado.");
}

void loop() {
  server.handleClient();
}
