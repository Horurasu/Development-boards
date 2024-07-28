#include <WiFi.h>
#include <WebServer.h>
#include <FS.h> // Biblioteca para el sistema de archivos SPIFFS

const char *ssid = "upsrj_PROFESORES_campus";
const char *password = "D0c9nt9$2022*#";

WebServer server(80);

void setup() {
  Serial.begin(115200);
  
  // Inicialización de la conexión WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a la red WiFi...");
  }
  Serial.println("Conexión WiFi establecida.");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());

  // Inicialización del sistema de archivos SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("Error al montar el sistema de archivos SPIFFS");
    return;
  }

  // Inicialización del servidor web
  server.on("/", HTTP_GET, []() {
    String content = "<h1>Bienvenido al ESP32 Web Server</h1>";
    content += "<button onclick=\"guardarDatos()\">Guardar datos</button>";
    content += "<script>function guardarDatos() {"
               "var xhttp = new XMLHttpRequest();"
               "xhttp.open('GET', '/guardar', true);"
               "xhttp.send();}</script>";
    server.send(200, "text/html", content);
  });

  // Ruta para guardar datos
  server.on("/guardar", HTTP_GET, []() {
    guardarDatosLocalmente();
    server.send(200, "text/plain", "Datos guardados localmente");
  });

  server.begin();
  Serial.println("Servidor HTTP iniciado.");
}

void loop() {
  server.handleClient();
}

void guardarDatosLocalmente() {
  // Abre un archivo en modo de escritura (si no existe, se crea)
  File archivo = FS.open("/datos.txt", "a");
  if (!archivo) {
    Serial.println("Error al abrir el archivo de datos");
    return;
  }

  // Obtén la hora actual para registrarla junto con los datos
  String datosAGuardar = obtenerHoraActual() + ": Botón presionado\n";

  // Escribe los datos en el archivo
  archivo.println(datosAGuardar);
  archivo.close();

  Serial.println("Datos guardados localmente en el archivo datos.txt");
}

String obtenerHoraActual() {
  // Obtén la hora actual del sistema
  // Aquí deberías implementar tu lógica para obtener la hora actual
  // Por simplicidad, retornaremos una cadena vacía en este ejemplo
  return "";
}
