#include <ESP8266WiFi.h>

const char* host = "192.168.5.1";
const uint16_t port = 17;

void setup() {
  const char* ssid     = "LightWiFi";
  const char* password = "WiFiLight";
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.begin(115200);
  Serial.print("Connecting to WiFi: ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected");
  Serial.print("My IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Connecting to: ");
  Serial.println(host);
}
void loop (){
  WiFiClient client;
  
  if (!client.connect(host, port)) {
  Serial.println("connection failed");
  delay(5000);
  return;
  }
  // Read all the lines of the reply from server and print them to Serial
  Serial.println("receiving from remote server");
  while (client.available()) {
    char ch = static_cast<char>(client.read());
    Serial.print(ch);
  }
  
}

