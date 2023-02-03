#include "Module.h"
#include "udf_log.h"

xQueueHandle PCRecvQueue;
xQueueHandle PCSendQueue;

void Module_PCSend(uint32_t deviceID, uint8_t *data, uint32_t size) {
    uint8_t *buffer = (uint8_t *)pvPortMalloc(sizeof(uint8_t) * size + sizeof(uint32_t));
    *(uint32_t *)&buffer[0] = deviceID;
    memcpy(&buffer[4], data, size);
    udf_log_d("Send. deviceID=%x, size=%d, buffer=%p", deviceID, sizeof(uint8_t) * size + sizeof(uint32_t), buffer);
    PCTransferQueue_t send;
    send.data = buffer;
    send.len = size;
    xQueueSend(PCSendQueue, &send, portMAX_DELAY);
}

void Module_PCRecvhandler(void *pvParameters) {
    PCTransferQueue_t recv;
    for (;;) {
        xQueueReceive(PCRecvQueue, &recv, portMAX_DELAY);
        uint32_t moduleID = *(uint32_t *)&recv.data[0];
        uint8_t *moduleData = (uint8_t *)pvPortMalloc(sizeof(uint8_t) * (recv.len - sizeof(uint32_t)));
        memcpy(moduleData, &recv.data[sizeof(uint32_t)], recv.len - sizeof(uint32_t));
        vPortFree(recv.data);
        udf_log_d("data recv. moduleID=%X, size=%d", moduleID, recv.len - sizeof(uint32_t));
        if (moduleID == 0) {
            uint8_t tmp[36];
            *(uint32_t *)&tmp[0] = (uint32_t)ESP.getEfuseMac();
            strcpy((char *)&tmp[4], "ORIGIN Keyboard Gen1 Alpha");
            Module_PCSend(0x00000000, tmp, 36);
        } else {
        }
    }
}

void Module_Init() {
    PCRecvQueue = xQueueCreate(16, sizeof(PCTransferQueue_t));
    PCSendQueue = xQueueCreate(16, sizeof(PCTransferQueue_t));
    xTaskCreate(Module_PCRecvhandler, "Module Recv", 2048, NULL, 0, NULL);
}
