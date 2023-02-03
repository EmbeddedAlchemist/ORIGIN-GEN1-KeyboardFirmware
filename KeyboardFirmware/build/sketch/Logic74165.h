#line 1 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\Logic74165.h"
#ifndef _LOGIC_74165_H_
#define _LOGIC_74165_H_
#include "SPI.h"

class Logic74165 {
  private:
    SPIClass &spi;
    unsigned int seriesNum;
    uint8_t pinPL, pinCP, pinQ7, pinMOSI;
    uint32_t SPIClockFreq;

  public:
    Logic74165(SPIClass &spi,  unsigned int seriesNum, uint8_t pinPL, uint8_t pinCP, uint8_t pinQ7, uint8_t pinMOSI, uint32_t SPIClockFreq);
    void read(uint8_t *buf);
};

#endif 