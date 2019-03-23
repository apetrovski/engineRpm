#include <ESP8266WiFi.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("name", "password");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
WiFiClient client;
     const uint16_t port = 2000;
     const char * host = "192.168.1.1";
     if (client.connect(host, port)) //Try to connect to TCP Server
     {
        Serial.println("RPM");
        char command[] = "$--RPM,E,1,2000,1,A*65\r\n";
        client.write((uint8_t *)command, sizeof(command));
        delay(5000); 
     }
}
