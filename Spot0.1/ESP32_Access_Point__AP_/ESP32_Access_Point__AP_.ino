#include "WiFi.h"
#define LED0 26
#define LED1 27
const char* ssid = "Spot0.1";
const char* password = NULL;
WiFiServer server (80);

String html = "<!DOCTYPE html>\
<html>\
<head>\
  <title>ESP IOT DASHBOARD</title>\
  <meta name=\"viewpoint\"content=\"width=device-width, initial-scale=1\">\
  <link rel=\"icon\"type=\"image/png\"href=\"favicon.png\">\
  <style>\
    .grid{\
      display: grid;\
      grid-template-columns: auto auto auto;\
      max-width: 29rem;\
    }\
    .grid*{\
      fint-size: 6rem;\
      text-align: center;\
      line-height: 8rem;\
      /*border: 1px solid #000;*/\
    }\
    .grid button{\
      background-color: tranparent;\
      border: none;\
      color: hsl(0, 0%, 25%);\
      font-family:\"Liberatoin Sans\",\"Open Sans\",sans-serif, monospace;\
    }\
    .grid button:active{\
      color: red;\
    }\
    .up{\
      transform: rotate(90deg) scaleX(-1);\
      /*margin-bottom: 1rem; */\
    }\
    .down{\
      transform: rotate(90deg);\
    }\
    .left{\
      margin-right: 2.5rem;\
      transform: scaleX(-1);\
    }\
    .right{\
      margin-left: 2.5rem;\
    }\
    .input{\
      display: block;\
      max-width: 16rem;\
    }\
    .wrapper{\
      display: flex;\
      flex-direction: column;\
      align-items: center;\
    }\
    .wrapper>*+*{\
      margin-top: 5rem;\
    }\
    .p{\
      color: hsl(0,0%,25%);\
      font-size: 5rem;\
    }\
   </style>\
  </head>\
 <body>\
  <div class=\"wrapper\">\
    <!--p class=\"p\">\
      {operation}&nbsp;{displayValue}\
    <!--p-->\
    Spot0.1 Remote Controller\
     <div class=\"grid\">\
      <div></div>\
      <button class=\"up\"id=\"up\"onclick=\"fetch('/?up')\">\
        &#10151;\
      </button>\
      <div></div>\
      <button class=\"left\"id=\"left\"onClick={Lefthandle}>\
       &#10151;\
      </button>\
      <button id=\"stop\"onClick=\"fetch('/?stop')\">\
       &#11044;\
      </button>\
      <button class=\"right\"id=\"right\"onClick={Righthandle}>\
       &#10151;\
      </button>\
      <div></div>\
      <button class=\"down\"id=\"down\"onClick=\"fetch('/?down')\">\
        &#10151;\
      </button>\
      <div></div>\
     </div>\
     <input\
      class=\"input\"\
      min=\"0\"\
      max=\"180\"\
      onChange={handleChange}\
      type=\"range\"\
      value={value}\
     ><\input>\
    </div>\
    <script src=\"script.js\"><\script>\
</body>\
</html>";

void Connect_WiFi()
{
  WiFi.begin(ssid, password);
  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(100);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  digitalWrite(LED0, LOW);
  digitalWrite(LED1, LOW);
  Serial.print("Setting soft access point mode");
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();
  if(client)
  {
    String request = client.readStringUntil('\r');
    client.print(html);
    if(request.indexOf("?up")!=-1||request.indexOf("?down")!=-1)digitalWrite(LED0, HIGH);
    if(request.indexOf("?stop")!=-1)digitalWrite(LED0, LOW);
    request="";
  }
}
