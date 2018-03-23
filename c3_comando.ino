#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

WiFiClient client;
#define AP_SSID "TP-LINK_F6A8"
#define AP_PASSWORD  "37881511"

void wifiConnect() {
  Serial.print("Connecting to AP");
  WiFi.begin(AP_SSID, AP_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(0,1);
  Serial.begin(9600);
  delay(300);
  Serial.println("starting");
  WiFi.disconnect();
  Serial.println("disconnected");
  wifiConnect();
  Serial.println("Connected");
}

void loop() {
  HTTPClient http;
  http.begin("http://c3ra.inf.ufg.br/cubes/info?pid=2&id=3");
  int httpCode = http.GET();
  Serial.println(httpCode);
  if(httpCode == HTTP_CODE_OK) {
  Serial.print("HTTP response code ");
    Serial.println(httpCode);
    String response = http.getString();
    Serial.println(response);
  }
  http.end();
}
