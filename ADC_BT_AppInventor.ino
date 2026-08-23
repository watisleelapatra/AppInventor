#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const int adcPin = 34;  // ADC pin connected to sensor

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_ADC");  // Bluetooth device name
  Serial.println("Bluetooth device started, now you can pair it!");
}

void loop() {
  int adcValue = analogRead(adcPin);  // Reads 0-4095
  
  // Send as a string followed by newline
  SerialBT.println(adcValue);
  
  Serial.println(adcValue);  // For debugging via USB
  
  delay(1000);  // Adjust sending interval as needed
}
