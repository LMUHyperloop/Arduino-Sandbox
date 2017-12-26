#include <dht.h>

#define MOIST humidity
#define eddie jen

dht jen;


void setup() {
  // put your setup code here, to run once:
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  eddie.read11(7);
  Serial.print("Temperature: " + (String)eddie.temperature + "\n");
  Serial.print("Humidity: " + (String)eddie.MOIST + "\n");
  Serial.print("Water Drops: " + String(analogRead(8)) + "\n");
  Serial.print("Soil Threshold: " + (String)digitalRead(8) + "\n");
  delay(2000);
}
