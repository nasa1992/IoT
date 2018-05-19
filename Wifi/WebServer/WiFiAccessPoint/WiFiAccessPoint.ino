#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "DaoDuc";
const char *password = "1234567890";

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
   connected to this access point to see it.
*/
int led = 16;
void handleRoot() {
  server.send(200, "text/html", "<a href=\"/on\">On</a><br><a href=\"/off\">Off</a>");
}
void handleOn() {
  digitalWrite(led, LOW);
  server.sendHeader("location", "/");
  server.send(301);
}

void handleOff() {
  digitalWrite(led, HIGH);
  server.sendHeader("location", "/");
  server.send(301);
}
void setup() {
  pinMode(led, OUTPUT);
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
//  WiFi.mode(WIFI_AP);
  server.on("/", handleRoot);
  server.on("/On", handleOn);
  server.on("/Off", handleOff);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
