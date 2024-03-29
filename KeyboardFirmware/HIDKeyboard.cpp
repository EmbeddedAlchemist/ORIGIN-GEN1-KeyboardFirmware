#include "USBHID.h"
#include "HIDKeyboard.h"
const char HIDKeyboard_ReportDescriptor_ConflictFree[45] = {
    HID_USAGE_PAGE(HID_USAGE_PAGE_DESKTOP),
    HID_USAGE(HID_USAGE_DESKTOP_KEYBOARD),
    HID_COLLECTION(HID_COLLECTION_APPLICATION),
    // LED
    HID_REPORT_COUNT(5),
    HID_REPORT_SIZE(1),
    HID_REPORT_ID(HIDKeyboard_ReportID)
    HID_USAGE_PAGE(HID_USAGE_PAGE_LED),
    HID_USAGE_MIN(1),
    HID_USAGE_MAX(5),
    HID_OUTPUT(HID_DATA | HID_VARIABLE | HID_ABSOLUTE),
    HID_REPORT_COUNT(1),
    HID_REPORT_SIZE(3),
    HID_OUTPUT(HID_CONSTANT),
    // key Bitmap
    HID_REPORT_COUNT(0xE8),
    HID_REPORT_SIZE(1),
    HID_REPORT_ID(HIDKeyboard_ReportID)
    HID_LOGICAL_MIN(0),
    HID_LOGICAL_MAX(1),
    HID_USAGE_PAGE(HID_USAGE_PAGE_KEYBOARD),
    HID_USAGE_MIN(0x00),
    HID_USAGE_MAX(0xE7),
    HID_INPUT(HID_DATA | HID_VARIABLE | HID_ABSOLUTE),
    HID_COLLECTION_END,
    };