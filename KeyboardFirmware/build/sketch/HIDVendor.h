#line 1 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\HIDVendor.h"
#pragma once
#include "USBHID.h"

ESP_EVENT_DECLARE_BASE(HID_VENDOR_EVENT);

typedef enum {
    ARDUINO_USB_HID_VENDOR_ANY_EVENT = ESP_EVENT_ANY_ID,
    ARDUINO_USB_HID_VENDOR_SET_FEATURE_EVENT = 0,
    ARDUINO_USB_HID_VENDOR_GET_FEATURE_EVENT,
    ARDUINO_USB_HID_VENDOR_OUTPUT_EVENT,
    ARDUINO_USB_HID_VENDOR_MAX_EVENT,
} arduino_usb_hid_vendor_event_t;

typedef struct {
    const uint8_t* buffer;
    uint16_t len;
} VendorEventData_t;

class HIDVendor : public USBHIDDevice {
  private:
    USBHID hid;

  public:
    HIDVendor();
    void begin();
    void end();
    bool sendReport(uint8_t *data);

    void onEvent(esp_event_handler_t callback);
    void onEvent(arduino_usb_hid_vendor_event_t event, esp_event_handler_t callback);

    uint16_t _onGetDescriptor(uint8_t *buffer);
    uint16_t _onGetFeature(uint8_t report_id, uint8_t *buffer, uint16_t len);
    void _onSetFeature(uint8_t report_id, const uint8_t *buffer, uint16_t len);
    void _onOutput(uint8_t report_id, const uint8_t *buffer, uint16_t len);
};