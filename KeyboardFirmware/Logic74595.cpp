#include "esp32-hal-gpio.h"
#include "Logic74595.h"

Logic74595::Logic74595(SPIClass &spi, uint32_t seriesNum, uint8_t pinSTCP, uint8_t pinSHCP, uint8_t pinDS, uint8_t pinMISO, uint32_t SPIClockFreq):
  spi(spi), seriesNum(seriesNum), pinSTCP(pinSTCP), pinSHCP(pinSHCP), pinDS(pinDS), pinMISO(pinMISO), SPIClockFreq(SPIClockFreq) {
    pinMode(pinSTCP, OUTPUT);
    digitalWrite(pinSTCP, LOW);
}

void Logic74595::write(const uint8_t *dat) {
    spi.begin(pinSHCP, pinMISO, pinDS, -1);
    spi.beginTransaction(SPISettings(SPIClockFreq, MSBFIRST, SPI_MODE0));
    spi.transfer(0);
    spi.transferBytes(dat, NULL, seriesNum);
    digitalWrite(pinSTCP, HIGH);
    digitalWrite(pinSTCP, LOW);
    spi.endTransaction();
    spi.end();
} 

