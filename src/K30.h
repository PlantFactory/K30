#ifndef _K30_H
#define _K30_H

#include "Arduino.h"

#define K30_DEFAULT_ADDRESS 0x68

class K30 {
private:
  uint8_t addr;

public:
  void begin(uint8_t addr = K30_DEFAULT_ADDRESS);
  int32_t readCO2(void);
};

#endif //_K30_H
