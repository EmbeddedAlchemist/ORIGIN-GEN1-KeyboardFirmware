#line 1 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\HIDUSBKeyboard.cpp"
#include "HIDUSBKeyboard.h"

esp_err_t arduino_usb_event_handler_register_with(esp_event_base_t event_base, int32_t event_id, esp_event_handler_t event_handler, void *event_handler_arg);
esp_err_t arduino_usb_event_post(esp_event_base_t event_base, int32_t event_id, void *event_data, size_t event_data_size, TickType_t ticks_to_wait);
ESP_EVENT_DEFINE_BASE(KEYBOARD_EVENT);


HIDUSBKeyboard::HIDUSBKeyboard() : HID() {
    static bool initialized = false;
    if (!initialized) {
        initialized = true;
        HID.addDevice(this, sizeof(HIDKeyboard_ReportDescriptor_ConflictFree));
    }
}

void HIDUSBKeyboard::begin() {
    HID.begin();
}

void HIDUSBKeyboard::end() {
    HID.end();
}

void HIDUSBKeyboard::press(Keyboard_KeyCode_Typedef key) {
    int byteIndex = key / 8, bitIndex = key % 8;
    reportData[byteIndex] |= (1 << bitIndex);
}

void HIDUSBKeyboard::release(Keyboard_KeyCode_Typedef key) {
    int byteIndex = key / 8, bitIndex = key % 8;
    reportData[byteIndex] &= ~(1 << bitIndex);
}

void HIDUSBKeyboard::report() {
    HID.SendReport(HIDKeyboard_ReportID, reportData, sizeof(reportData));
}

void HIDUSBKeyboard::onEvent(esp_event_handler_t callback) {
    onEvent(ARDUINO_USB_HID_KEYBOARD_ANY_EVENT, callback);
}

void HIDUSBKeyboard::onEvent(arduino_usb_hid_keyboard_event_t event, esp_event_handler_t callback) {
    arduino_usb_event_handler_register_with(KEYBOARD_EVENT, event, callback, this);
}

uint16_t HIDUSBKeyboard::_onGetDescriptor(uint8_t *buffer) {
    memcpy(buffer, HIDKeyboard_ReportDescriptor_ConflictFree, sizeof(HIDKeyboard_ReportDescriptor_ConflictFree));
    return sizeof(HIDKeyboard_ReportDescriptor_ConflictFree);
}

void HIDUSBKeyboard::_onOutput(uint8_t report_id, const uint8_t *buffer, uint16_t len) {
    if (report_id == HIDKeyboard_ReportID) {
        uint8_t p;
        arduino_usb_event_post(KEYBOARD_EVENT, ARDUINO_USB_HID_KEYBOARD_LED_EVENT, &p, sizeof(p), portMAX_DELAY);
    }
}
