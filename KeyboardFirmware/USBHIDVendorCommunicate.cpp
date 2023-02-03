#include "HIDVendor.h"
#include "HardwareSerial.h"
#include "USB.h"
#include "udf_log.h"

#include "Module.h"

HIDVendor Vendor;

TaskHandle_t TaskHandle_HIDVender;

/**
 * @brief 发送数据包
 *
 * @param data 数据指针
 * @param len 数据长度
 */
void HID_SendPackHandler(void *pvParameters) {
    uint8_t *data;
    uint32_t size;
    uint8_t cmd = 0;
    uint8_t buffer[63];
    PCTransferQueue_t send;
    for (;;) {
        xQueueReceive(PCSendQueue, &send, portMAX_DELAY);
        data = send.data;
        size = send.len;
        uint8_t frameDataStartPos = 6,
                frameDataLen;
        uint32_t sendSize = 0;
        if (size - sendSize > 63 - frameDataStartPos)
            frameDataLen = 63 - frameDataStartPos;
        else
            frameDataLen = size - sendSize;
        buffer[0] = 0x5A;
        buffer[1] = cmd;
        // buffer[2] = (size >> 24) & 0xFF;
        // buffer[3] = (size >> 16) & 0xFF;
        // buffer[4] = (size >> 8) & 0xFF;
        // buffer[5] = (size >> 0) & 0xFF;
        *(uint32_t *)&buffer[2] = size;
        memcpy(&buffer[frameDataStartPos], &data[sendSize], frameDataLen);
        sendSize += frameDataLen;
        Vendor.sendReport(buffer);

        frameDataStartPos = 1;
        buffer[0] = 0;
        for (; sendSize < size; sendSize += frameDataLen) {
            if (size - sendSize > 63 - frameDataStartPos)
                frameDataLen = 63 - frameDataStartPos;
            else
                frameDataLen = size - sendSize;
            memcpy(&buffer[frameDataStartPos], &data[sendSize], frameDataLen);
            Vendor.sendReport(buffer);
        }
        udf_log_d("report send.");
        vPortFree(data);
    }
}

void HID_ReveivePack(const uint8_t *recv) {
    static uint8_t *data = NULL;
    static uint32_t totalSize = 0, recvSize = 0;
    static uint8_t packCmd = 0;
    uint8_t frameDataStartPos = 1,
            frameDataLen;
    if (recv[0] == 0x5A) {
        packCmd = recv[1];
        totalSize = *(uint32_t *)&recv[2];
        udf_log_d("Recv Start! Len =%08x", totalSize);
        recvSize = 0;
        if (data) {
            free(data);
            udf_log_e("Last pack recv error!");
        }
        data = (uint8_t *)malloc(sizeof(uint8_t) * totalSize);
        frameDataStartPos = 6;
    }
    if (!data)
        return;
    if (totalSize - recvSize > 63 - frameDataStartPos)
        frameDataLen = 63 - frameDataStartPos;
    else
        frameDataLen = totalSize - recvSize;
    memcpy(&data[recvSize], &recv[frameDataStartPos], frameDataLen);
    recvSize += frameDataLen;
    if (recvSize >= totalSize) {
        udf_log_d("Recv success! Len =%d", recvSize);
        PCTransferQueue_t recvStruct;
        recvStruct.data = data;
        recvStruct.len = recvSize;
        xQueueSend(PCRecvQueue, &recvStruct, portMAX_DELAY);
        data = NULL;
    }
}

void callbackEvent(void *event_handler_arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
    if (event_base == HID_VENDOR_EVENT) {
        VendorEventData_t *data = (VendorEventData_t *)event_data;
        switch (event_id) {
            case ARDUINO_USB_HID_VENDOR_GET_FEATURE_EVENT:
                udf_log_d("HID VENDOR GET FEATURE: len:%u\n", data->len);
                break;
            case ARDUINO_USB_HID_VENDOR_SET_FEATURE_EVENT:
                udf_log_d("HID VENDOR SET FEATURE: len:%u\n", data->len);
                Serial.println();
                break;
            case ARDUINO_USB_HID_VENDOR_OUTPUT_EVENT:
                HID_ReveivePack(data->buffer);

            default:
                break;
        }
    }
}

void HIDVendor_Handler(void *pvParameters) {
    for (;;) {
        // while (Vendor.available()) {
        //     int l = Vendor.available();
        //     uint8_t buf[l];
        //     Vendor.read(buf, Vendor.available());
        //     Serial.write(buf, l);
        // }
        // while (Serial.available()) {
        //     int l = Serial.available();
        //     uint8_t buf[l];
        //     Serial.read(buf, Serial.available());
        //     Vendor.write(buf, l);
        // }
    }
}

void HIDVendor_Init() {
    Vendor.onEvent(callbackEvent);
    Vendor.begin();
    xTaskCreatePinnedToCore(HIDVendor_Handler, "HIDVenderRecv", 2048, NULL, 0, &TaskHandle_HIDVender, 0);
    xTaskCreate(HID_SendPackHandler, "HID Send", 2048, NULL, 0, NULL);
}
