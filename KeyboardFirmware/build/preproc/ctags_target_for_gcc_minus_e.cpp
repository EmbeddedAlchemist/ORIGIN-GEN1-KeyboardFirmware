# 1 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino"

# 3 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino" 2
# 4 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino" 2
# 5 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino" 2
# 6 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino" 2
# 7 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino" 2
# 8 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino" 2
# 9 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino" 2

//#include "BLE.h"
# 12 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino" 2


SPIClass hspi(1);
Logic74165 test(hspi, 3, 5, 6, 7, 4, 24000000);

HIDUSBKeyboard usbKeyboard;
//HIDBLEKeyboard bleKeyboard;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    do { Serial.printf("[ %ldms " "INFO" " %s:%d ] " "ESP-IDF Version: %s" "\r\n", millis(), pathToFileName("c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino"), 23, esp_get_idf_version()); } while (0);;
    do { Serial.printf("[ %ldms " "INFO" " %s:%d ] " "Chip: %s %d, %dCore(s), %dMHz" "\r\n", millis(), pathToFileName("c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino"), 24, ESP.getChipModel(), ESP.getChipRevision(), ESP.getChipCores(), getCpuFrequencyMhz()); } while (0);;
    do { Serial.printf("[ %ldms " "INFO" " %s:%d ] " "Flash: %dMB, %dMHz, Mode%d" "\r\n", millis(), pathToFileName("c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino"), 25, ESP.getFlashChipSize() / 1024 / 1024, ESP.getFlashChipSpeed() / 1000 / 1000, ESP.getFlashChipMode()); } while (0);;
    do { Serial.printf("[ %ldms " "INFO" " %s:%d ] " "PSRAM: %.2f%MB" "\r\n", millis(), pathToFileName("c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino"), 26, (float)ESP.getPsramSize() / 1024 / 1024); } while (0);;
    do { Serial.printf("[ %ldms " "INFO" " %s:%d ] " "MAC/ID: %6X%6X" "\r\n", millis(), pathToFileName("c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino"), 27, (int)(ESP.getEfuseMac() >> 24), (int)(ESP.getEfuseMac() & 0xFFFFFF)); } while (0);;
    do { Serial.printf("[ %ldms " "INFO" " %s:%d ] " ">>>PROGRAM START!" "\r\n", millis(), pathToFileName("c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino"), 28); } while (0);;
    usbKeyboard.begin();
    Module_Init();
    USB_Init();
    //BLE_Init();
    //bleKeyboard.begin();
}

void loop() {
    vTaskDelete(
# 37 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino" 3 4
               __null
# 37 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\KeyboardFirmware.ino"
                   );
}
