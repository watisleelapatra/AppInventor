#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
unsigned char speed;

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("ESP32_watis"); // REPLACE xxx with your name
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
      speed = incomingString.toInt();
    }
    
    // Print the received string to the Serial Monitor
    //Serial.print("Received: ");
    //Serial.println(speed);
  }
  digitalWrite(2, LOW);
  delay(speed*50);
  digitalWrite(2, HIGH);
  delay(speed*50);
}
