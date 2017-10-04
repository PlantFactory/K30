// K30.cpp

#include "K30.h"
#include "Wire.h"

void K30::begin(uint8_t addr = K30_DEFAULT_ADDRESS) {
  this->addr = addr;
}

int32_t K30::readCO2(void) {
  int32_t co2_value = 0;

  Wire.beginTransmission(this->addr);
  Wire.write(0x22);
  Wire.write(0x00);
  Wire.write(0x08);
  Wire.write(0x2A);

  Wire.endTransmission();

  delay(10);

  Wire.requestFrom(this->addr, 4);

  uint8_t i = 0;
  uint8_t buffer[4] = {0, 0, 0, 0};

  while (Wire.available())
  {
    buffer[i] = Wire.read();
    i++;
  }

  co2_value |= buffer[1];
  co2_value = co2_value << 8;
  co2_value |= buffer[2];

  uint8_t sum = 0;
  sum = buffer[0] + buffer[1] + buffer[2];

  if (sum == buffer[3])
  {
    return co2_value;
  }
  else
  {
    return -1;
  }
}
