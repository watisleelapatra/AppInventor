#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("ESP32_xxx"); // REPLACE xxx with your name
  Serial.println("The device started, now you can pair it!");
}

void loop() {
  if (SerialBT.available()) {
    String incomingString = "";
    
    // Read incoming characters byte by byte
    while (SerialBT.available()) {
      char incomingChar = SerialBT.read();
      incomingString += incomingChar;
      delay(5); // Short delay to let buffer catch up
    }
    
    // Print the received string to the Serial Monitor
    Serial.print("Received: ");
    //Serial.println(incomingString);
    if(incomingString == "1") {
      Serial.println("1");
      digitalWrite(2, HIGH);
      delay(1000);
    }
    digitalWrite(2, LOW);
  }
}
