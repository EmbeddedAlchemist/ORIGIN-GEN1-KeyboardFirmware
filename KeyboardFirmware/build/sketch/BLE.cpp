#line 1 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\BLE.cpp"
#include "BLE.h"
#include "DeviceConfig.h"
#undef BLEDevice
NimBLEDevice BleDevice;

void BLE_Init(void){
    BleDevice.init(DeviceConfig.getDeviceName());
    BleDevice.setSecurityAuth(true, true, true);
}
