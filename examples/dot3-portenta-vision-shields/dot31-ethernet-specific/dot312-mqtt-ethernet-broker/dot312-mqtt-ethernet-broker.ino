



//#define TINY_MQTT_DEBUG   // define in your sketch



//#include <Portenta_Ethernet.h>
//#include <Ethernet.h>


//#define TINY_MQTT_PORTENTA_ETHERNET  // Draft to switch between WiFi and Ethernet
#include "portenta-pro-community-solutions.h"   // https://github.com/hsaturn/TinyMqtt


#define PORT 1883
MqttBroker broker(PORT);

/** Basic Mqtt Broker
  *
  *  +-----------------------------+
  *  | ESP                         |
  *  |       +--------+            | 
  *  |       | broker |            | 1883 <--- External client/s
  *  |       +--------+            |
  *  |                             |
  *  +-----------------------------+
  */

  
// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 177);  // what are these for??

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);



/*
  ArduinoMqttClient - WiFi Simple Sender

  This example connects to a MQTT broker and publishes a message to
  a topic once a second.

  The circuit:
  - Arduino MKR 1000, MKR 1010 or Uno WiFi Rev.2 board

  This example code is in the public domain.
*/




//EthernetClient wifiClient;
//MqttClient mqttClient(wifiClient);

void setup() {
   // Open serial communications and wait for port to open:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);      // set the LED Green pin mode  
  pinMode(LEDB, OUTPUT);             
  digitalWrite(LEDB, HIGH);  
  digitalWrite(LED_BUILTIN, LOW);  
  
  delay(5000);  // time to get serial monitor working if needed
  Serial.println("Wait a few seconds for a non-blocking chance to activate the serial monitor");
  delay(5000);  
  Serial.println("Wait 5 more seconds for a non-blocking chance to activate the serial monitor");
  delay(5000);   
  Serial.println("Ethernet WebServer Example");

  // start the Ethernet connection and the server:
  Ethernet.begin(mac);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }


  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
  Serial.println();


  Serial << "Connected to Ethernet IP address: " << Ethernet.localIP() << endl;  

  broker.begin();
  Serial << "Broker ready : " << Ethernet.localIP() << " on port " << PORT << endl;

 
}

void loop() {
  broker.loop();
}
