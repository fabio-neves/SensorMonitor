#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

void HandleTemperature();
void HandleLight();

const char* ssid = "GardenMonitor";

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid);
  server.on("/temperatura", HandleTemperature);
  server.on("/claridade", HandleLight);
  server.begin();
}

void loop() {
  server.handleClient();
}

void HandleTemperature() {
  Serial.println("TMP");

  while (!(Serial.available() > 0)) {}

  String result = Serial.readStringUntil('\n');

  server.send(200, "text/html", "<h1>Temperatura ("+result+")</h1>"); 
}

void HandleLight() {
  Serial.println("LUZ");

  while (!(Serial.available() > 0)) {}

  String result = Serial.readStringUntil('\n');

  server.send(200, "text/html", "<h1>Claridade: ("+result+")</h1>"); 
}