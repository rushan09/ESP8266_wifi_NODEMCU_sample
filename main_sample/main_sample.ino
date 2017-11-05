#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

const char* ssid="xxxxx";
const char* password="xxxxx";

WiFiServer server(80);

void setup() {
//  pinMode(7,OUTPUT);
  Serial.begin(115200);
  Serial.println("");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid,password);

  while(WiFi.status() != WL_CONNECTED){
    delay(250);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Wifi connected");

  server.begin();
  Serial.println("Web server started");

  Serial.print("Connect url- ");
  Serial.print("http://");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void loop() {
  WiFiClient client = server.available();
  if(!client){
    return;
  }
  String request = client.readStringUntil('\r'); 
//  digitalWrite(7,HIGH);
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<DOCTYPE HTML>");
  client.println("<html>");
  client.println("<style>");
  client.println("body {background-color: #ACAEAD;}");
  client.println("</style>");
  client.println("<h1>Car controller</h1>");
  client.println("<p> use arrow keys to controll </P>");
  client.println("<script type=\"text/javascript\"> ");
  client.println("document.onkeydown = function(e) { ");
  client.println("switch (e.keyCode) { ");
  client.println("case 37: window.location = \"/left=1\"; break; ");
  client.println("case 38: window.location = \"/up=1\"; break; ");
  client.println("case 39: window.location = \"/right=1\"; break; ");
  client.println("case 40: window.location = \"/down=1\"; break; }}; ");
  client.println("</script> </html> ");
  delay(10);
}





