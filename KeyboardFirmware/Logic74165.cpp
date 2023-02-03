#include "Logic74165.h"
#include "Arduino.h"

Logic74165::Logic74165(SPIClass &spi,  unsigned int seriesNum, uint8_t pinPL, uint8_t pinCP, uint8_t pinQ7, uint8_t pinMOSI, uint32_t SPIClockFreq):
spi(spi), seriesNum(seriesNum), pinPL(pinPL), pinCP(pinCP), pinQ7(pinQ7), pinMOSI(pinMOSI), SPIClockFreq(SPIClockFreq){
    pinMode(pinPL, OUTPUT);
    digitalWrite(pinPL, HIGH);
}

void Logic74165::read(uint8_t *buf){
    spi.begin(pinCP, pinQ7, pinMOSI, -1);
    spi.beginTransaction(SPISettings(SPIClockFreq, MSBFIRST, SPI_MODE2));
    spi.transfer(0);
    digitalWrite(pinPL, 0);
    digitalWrite(pinPL, 1);
    spi.transferBytes(NULL, buf, seriesNum);
    spi.endTransaction();
    spi.end();
}