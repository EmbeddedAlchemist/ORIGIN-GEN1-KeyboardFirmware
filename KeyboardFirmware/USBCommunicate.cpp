#include "USB.h"
#include "udf_log.h"
#include "USBHIDVendorCommunicate.h"
//#include "USBHIDKeyboard.h"
//USBHIDKeyboard Keyboard;


static void usbEventCallback(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
    if (event_base == ARDUINO_USB_EVENTS) {
        arduino_usb_event_data_t *data = (arduino_usb_event_data_t *)event_data;
        switch (event_id) {
            case ARDUINO_USB_STARTED_EVENT:
                udf_log_d("USB STARTED!");
                //HIDVendor_Start();
                break;
            case ARDUINO_USB_STOPPED_EVENT:
                udf_log_d("USB STOP!");
                //HIDVendor_End();
                break;
            case ARDUINO_USB_SUSPEND_EVENT:
                udf_log_d("USB SUSPEND!");
                break;
            case ARDUINO_USB_RESUME_EVENT:
                udf_log_d("USB RESUME!");
                break;

            default:
                break;
        }
    }
}

void USB_Init() {
    USB.manufacturerName("UNDEFINE Tech");
    USB.productName("ORIGIN Keyboard");
    USB.PID(0);
    USB.VID(0xDF1E);
    USB.onEvent(usbEventCallback);
    USB.begin();
    HIDVendor_Init();
    //Keyboard.begin();
}