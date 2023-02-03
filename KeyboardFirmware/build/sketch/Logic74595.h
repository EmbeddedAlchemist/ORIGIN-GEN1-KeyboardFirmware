#line 1 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\Logic74595.h"
#ifndef _LOGIC_74595_H_
#define _LOGIC_74595_H_
#include "Arduino.h"
#include "SPI.h"

class Logic74595 {
  public:
    Logic74595(SPIClass &spi, uint32_t seriesNum, uint8_t pinSTCP, uint8_t pinSHCP, uint8_t pinDS, uint8_t pinMISO, uint32_t SPIClockFreq);
    void write(const uint8_t *dat);

  private:
    SPIClass &spi;
    uint32_t seriesNum; // 串联的数目
    uint8_t pinSTCP, pinSHCP, pinDS, pinMISO;
    uint32_t SPIClockFreq;

  protected:
};

#endif