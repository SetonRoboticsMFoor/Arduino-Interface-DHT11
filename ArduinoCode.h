#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // Sensor type

DHT dht(DHTPIN, DHTTYPE);

unsigned long previousMillis = 0;
const long interval = 1000; // Send readings every 1 second

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  unsigned long currentMillis = millis();

  // Send reading every 1000ms (1 second)
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    float h = dht.readHumidity();
    float t = dht.readTemperature(); // Default is Celsius. Use dht.readTemperature(true) for Fahrenheit.

    // Check if readings failed
    if (isnan(h) || isnan(t)) {
      Serial.println("ERR,ERR");
    } else {
      Serial.print(t);
      Serial.print(",");
      Serial.println(h);
    }
  }
}