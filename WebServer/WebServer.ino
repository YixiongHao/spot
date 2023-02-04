#include <WiFi.h>
#include <string.h>
const char* ssid = "ks";  //wifi name
const char* password = "191hinemoa";  //wifi password
WiFiServer server(80);
int pinNo = 26;
String tailSt;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pinNo, OUTPUT);

  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();  
}

int value = 0;

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available(); 
  if(client)
  {
    Serial.println("New Client.");
    String currentLine = "";
    while(client.available())
    {
      if(client.available())
      {
        char c = client.read();
        Serial.write(c);
        if(c == '\n')
        {
          if(currentLine.length() == 0)
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print("<h2>Click <a href=\"/H\">here</a>to turn the LED on pin GPIO 26 on.</h2><br>");
            client.print("<h2>Click <a href=\"/L\">here</a>to turn the LED on pin GPIO 26 off.</h2><br>");
            client.println();
            break;
          }
          else
          {
            currentLine = "";
          }
        }
        else if (c != '\r')
        {
          currentLine += c;
        }
        if(currentLine.endsWith("GET /H"))
        {
          digitalWrite(pinNo, HIGH);
        }
        if(currentLine.endsWith("GET /L"))
        {
          digitalWrite(pinNo, LOW);
        }
        if(currentLine.endsWith("GET /123"))
        {
          Serial.println();
          tailSt=currentLine.substring(5);
          Serial.print("Tail String:");
          Serial.println(tailSt);
        }
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
  } 
}
