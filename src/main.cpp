#include <Arduino.h>

#include "config.h"
#include "relay.h"
#include "sensor.h"

bool relayState = false;

void setup() {
  Serial.begin(Config::kBaud);

  Relay::begin();
  Sensor::begin();
}

void loop() {
  // Крок 1. Зчитати значення ADC з піна GPIO IN (діапазон 0...4095).
  SensorReading sensorReading = Sensor::readLdr();

  // Крок 2. Порівняти значення з порогами (Гістерезис)
  if (sensorReading.raw < Sensor::kThresholdDark) {
    relayState = true;
  } else if (sensorReading.raw > Sensor::kThresholdLight) {
    relayState = false;
  }

  // Крок 3. Встановити стан реле відповідно до результату порівняння.
  Relay::setState(relayState);

  Serial.print("RAW = ");
  Serial.print(sensorReading.raw);
  Serial.print(" | Relay = ");
  Serial.println(relayState ? "ON" : "OFF");

  delay(200);
}
