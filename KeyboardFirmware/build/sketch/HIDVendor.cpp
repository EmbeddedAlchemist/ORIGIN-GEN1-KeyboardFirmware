#line 1 "c:\\Users\\CHALLENGER\\Documents\\KeXieData\\Project\\ModuleKeyboard\\MainKeyboard\\V1\\Code\\KeyboardFirmware\\HIDVendor.cpp"
#include "HIDVendor.h"

#define REPORT_ID 8
esp_err_t arduino_usb_event_handler_register_with(esp_event_base_t event_base, int32_t event_id, esp_event_handler_t event_handler, void *event_handler_arg);
esp_err_t arduino_usb_event_post(esp_event_base_t event_base, int32_t event_id, void *event_data, size_t event_data_size, TickType_t ticks_to_wait);
ESP_EVENT_DEFINE_BASE(HID_VENDOR_EVENT);

static const uint8_t HIDVendorDescriptor[]{
    HID_USAGE_PAGE_N(HID_USAGE_PAGE_VENDOR, 2),
    HID_USAGE(0x01),
    HID_COLLECTION(HID_COLLECTION_APPLICATION),
    /* Report ID if any */
    /* Input */
    HID_USAGE(0x02),
    HID_LOGICAL_MIN(0x00),
    HID_LOGICAL_MAX(0xff),
    HID_REPORT_SIZE(8),
    HID_REPORT_COUNT(63),
    HID_REPORT_ID(REPORT_ID)
    HID_INPUT(HID_DATA | HID_VARIABLE | HID_ABSOLUTE),
    /* Output */
    HID_USAGE(0x03),
    HID_LOGICAL_MIN(0x00),
    HID_LOGICAL_MAX(0xff),
    HID_REPORT_SIZE(8),
    HID_REPORT_COUNT(63),
    HID_REPORT_ID(REPORT_ID)
    HID_OUTPUT(HID_DATA | HID_VARIABLE | HID_ABSOLUTE),
    /* Feature */
    HID_USAGE(0x04),
    HID_LOGICAL_MIN(0x00),
    HID_LOGICAL_MAX(0xff),
    HID_REPORT_SIZE(8),
    HID_REPORT_COUNT(63),
    HID_FEATURE(HID_DATA | HID_VARIABLE | HID_ABSOLUTE),
    HID_COLLECTION_END,
};

static uint8_t feature[64];

HIDVendor::HIDVendor() {
    static bool initialized = false;
    if (!initialized) {
        initialized = true;
        hid.addDevice(this, sizeof(HIDVendorDescriptor));
        memset(feature, 0, 64);
    }
}

void HIDVendor::begin() {
    hid.begin();
}

void HIDVendor::end() {
    hid.end();
}

bool HIDVendor::sendReport(uint8_t *data) {
    return hid.SendReport(REPORT_ID, data, 63);
}

void HIDVendor::onEvent(esp_event_handler_t callback) {
    onEvent(ARDUINO_USB_HID_VENDOR_ANY_EVENT, callback);
}

void HIDVendor::onEvent(arduino_usb_hid_vendor_event_t event, esp_event_handler_t callback) {
    arduino_usb_event_handler_register_with(HID_VENDOR_EVENT, event, callback, this);
}

uint16_t HIDVendor::_onGetDescriptor(uint8_t *dst) {
    memcpy(dst, HIDVendorDescriptor, sizeof(HIDVendorDescriptor));
    return sizeof(HIDVendorDescriptor);
}
uint16_t HIDVendor::_onGetFeature(uint8_t report_id, uint8_t *buffer, uint16_t len) {
    if (report_id != REPORT_ID)
        return 0;
    memcpy(buffer, feature, len);
    VendorEventData_t p;
    p.buffer = feature;
    p.len = len;
    arduino_usb_event_post(HID_VENDOR_EVENT, ARDUINO_USB_HID_VENDOR_GET_FEATURE_EVENT, &p, sizeof(VendorEventData_t), portMAX_DELAY);
    return len;
}
void HIDVendor::_onSetFeature(uint8_t report_id, const uint8_t *buffer, uint16_t len) {
    if (report_id != REPORT_ID) {
        return;
    }
    memcpy(feature, buffer, len);
    VendorEventData_t p;
    p.buffer = feature;
    p.len = len;
    arduino_usb_event_post(HID_VENDOR_EVENT, ARDUINO_USB_HID_VENDOR_SET_FEATURE_EVENT, &p, sizeof(VendorEventData_t), portMAX_DELAY);
}
void HIDVendor::_onOutput(uint8_t report_id, const uint8_t *buffer, uint16_t len) {
    if (report_id != REPORT_ID) {
        return;
    }
    VendorEventData_t p;
    p.buffer = buffer;
    p.len = len;
    arduino_usb_event_post(HID_VENDOR_EVENT, ARDUINO_USB_HID_VENDOR_OUTPUT_EVENT, &p, sizeof(VendorEventData_t), portMAX_DELAY);
}