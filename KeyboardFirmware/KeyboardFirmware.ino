
#include "HIDUSBKeyboard.h"
#include "HIDBLEKeyboard.h"
#include "Logic74165.h"
#include "Module.h"
#include "SPI.h"
#include "USBCommunicate.h"
#include "udf_log.h"
#include "KeyboardKeyCode.h"
//#include "BLE.h"
#include "HIDBLEKeyboard.h"


SPIClass hspi(HSPI);
Logic74165 test(hspi, 3, 5, 6, 7, 4, 24000000);

HIDUSBKeyboard usbKeyboard;
//HIDBLEKeyboard bleKeyboard;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    udf_log_i("ESP-IDF Version: %s", esp_get_idf_version());
    udf_log_i("Chip: %s %d, %dCore(s), %dMHz", ESP.getChipModel(), ESP.getChipRevision(), ESP.getChipCores(), getCpuFrequencyMhz());
    udf_log_i("Flash: %dMB, %dMHz, Mode%d", ESP.getFlashChipSize() / 1024 / 1024, ESP.getFlashChipSpeed() / 1000 / 1000, ESP.getFlashChipMode());
    udf_log_i("PSRAM: %.2f%MB", (float)ESP.getPsramSize() / 1024 / 1024);
    udf_log_i("MAC/ID: %6X%6X", (int)(ESP.getEfuseMac() >> 24), (int)(ESP.getEfuseMac() & 0xFFFFFF));
    udf_log_i(">>>PROGRAM START!");
    usbKeyboard.begin();
    Module_Init();
    USB_Init();
    //BLE_Init();
    //bleKeyboard.begin();
}

void loop() {
    vTaskDelete(NULL);
}