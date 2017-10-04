#include <K30.h>
#include <Wire.h>

K30 co2Sensor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  co2Sensor.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Value:");
  Serial.println(co2Sensor.readCO2());
  delay(1000);
}
