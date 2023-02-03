#pragma once

#include "FreeRTOS.h"
#include "queue.h"

extern xQueueHandle PCRecvQueue, PCSendQueue;

class Module {
  public:
    uint32_t SN;//模块序列号
    
    virtual void onConnected(void);    // 和模块建立连接时
    virtual void onDisconnected(void); // 和模块断开连接时
    virtual void onInterrupt(void);    // 模块请求中断时
    virtual void onPolling(void);      // 轮询到该模块时
};

typedef struct PCTransferQueue_t {
    uint8_t *data;
    uint32_t len;
} PCTransferQueue_t;

void Module_Init(void);
