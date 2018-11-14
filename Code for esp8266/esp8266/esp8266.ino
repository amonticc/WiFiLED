#include <ESP8266WiFi.h>

const char* host_text = "192.168.5.1"; // TCP host (RPI)
byte host[] = { 192, 168, 5, 1 }; // TCP host (RPI)
const int port = 17; // Port TCP host is using
const char* ssid     = "LightWiFi"; //WiFi SSID that will be connected to
const char* password = "WiFiLight"; //Password for that access point
int numOfPixels = 0; // Length of LED strip in pixels
int colors[3][3][8];
int brightness;
int command;
int changeSpeed;
int PIN_NUM = 16; // Pin that the LEDs are connected to

WiFiClient client;

void setup() {
  pinMode(PIN_NUM, OUTPUT);
  digitalWrite(PIN_NUM, LOW);
  WiFi.mode(WIFI_STA); // Sets device to client mode
  WiFi.begin(ssid, password); // Makes connect to WiFi
  Serial.begin(115200); 
  Serial.print("Connecting to WiFi: ");
  
  while (WiFi.status() != WL_CONNECTED) // Prints periods while connecting to WiFi
  {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("Connected");
  Serial.print("My IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Connecting to: ");
  Serial.println(host_text);
  while(!client.connect(host, port))
  {
    Serial.println("Waiting for socket connection...");
    delay(500);
  }
  Serial.println("Socket connection made!!!");
  
  while(!client.available())
  {
    delay(50);
  }
  String num = client.readString();
  numOfPixels = atoi(num.c_str());
}

void loop ()
{
  if(client.available())
  {
    update_data();
  }
  else
  {
    
  }



  // Read all the lines of the reply from server and print them to Serial
  Serial.println("receiving from remote server");
  if (client.available()) 
  {
    Serial.print("Message: ");
    String c = client.readString();
    c.trim();
    Serial.println(c);
    delay(1000);
  }
  
}


void send_signal()
{
  if (command == 0) // Blank the led (off)
    digitalWrite(PIN_NUM, LOW); 
  else if (command == 1) // Set all to one color

  else if (command == 2) // Strobe (off and color selected)

  else if (command == 3) // Flash between two colors
    
}

void update_data()
{
  byte input = client.read();
  int i = 0;
  while(i < 6)
  {
    if(i == 0)
      command = input(int);
    else if (i == 1)
      brightness = input(int);
    else if (i == 2)
      changeSpeed = input(int);
     else if
     {
      for (int j = 0; j < 3 ; j++)
      {
        color[i - 3][j] = 
      }
     }
     
  }
  input = client.read();
}

void send_one()
{
  digitalWrite(PIN_NUM, HIGH);
  delay(0.0012);
  digitalWrite(PIN_NUM, LOW);
  delay(.0013); // Might need to shink to adjust for next proccesses
}

void send_zero()
{
  digitalWrite(PIN_NUM, HIGH);
  delay(.0005);
  digitalWrite(PIN_NUM, LOW);
  delay(.002);
}

void stable_color()
{
  for(int i = 0; i < num_of_leds; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      int sub* = color[0][j];
      for(int k = 0; k < 8; k++)
      {
        if (color[0][j][k] == 1)
        {
          send_one();
        }
        else
        {
          send_zero();
        }
      }
    }
  }
}



