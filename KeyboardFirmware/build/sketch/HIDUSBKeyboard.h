#line 1 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\HIDUSBKeyboard.h"
#ifndef _WIRE_KEYBOARD_H_
#define _WIRE_KEYBOARD_H_
#include "USB.h"
#include "USBHID.h"
#include "KeyboardKeyCode.h"
#include "esp_event.h"
#include "HIDKeyboard.h"

typedef enum {
    ARDUINO_USB_HID_KEYBOARD_ANY_EVENT = ESP_EVENT_ANY_ID,
    ARDUINO_USB_HID_KEYBOARD_LED_EVENT = 0,
    ARDUINO_USB_HID_KEYBOARD_MAX_EVENT,
} arduino_usb_hid_keyboard_event_t;



class HIDUSBKeyboard : public USBHIDDevice, HIDKeyboard{
  private:
    USBHID HID;
    uint8_t reportData[29];

  public:
    HIDUSBKeyboard();
    void begin();
    void end();
    void press(Keyboard_KeyCode_Typedef key);
    void release(Keyboard_KeyCode_Typedef key);
    void report();

    uint16_t _onGetDescriptor(uint8_t *buffer);
        void _onOutput(uint8_t report_id, const uint8_t* buffer, uint16_t len);
    void onEvent(esp_event_handler_t callback);
    void onEvent(arduino_usb_hid_keyboard_event_t event, esp_event_handler_t callback);
};

#endif