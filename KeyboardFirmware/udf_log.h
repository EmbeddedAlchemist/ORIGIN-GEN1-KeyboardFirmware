#pragma once
#include "Arduino.h"
#include "HardwareSerial.h"

#define UDF_LOG_LEVEL_DISABLE 0
#define UDF_LOG_LEVEL_ERROR 1
#define UDF_LOG_LEVEL_WARNING 2
#define UDF_LOG_LEVEL_DEBUG 3
#define UDF_LOG_LEVEL_INFO 4

#ifndef UDF_DEBUG_LEVEL
#define UDF_DEBUG_LEVEL UDF_LOG_LEVEL_INFO
#endif

#define udf_log_x(lv, fmt, arg...)                                                                               \
    do {                                                                                                         \
        Serial.printf("[ %ldms " lv " %s:%d ] " fmt "\r\n", millis(), pathToFileName(__FILE__), __LINE__, ##arg); \
    } while (0);

#if UDF_DEBUG_LEVEL >= UDF_LOG_LEVEL_ERROR
#define udf_log_e(fmt, arg...) udf_log_x("ERROR", fmt, ##arg)
#else
#define udf_log_e(fmt, arg) (void)0
#endif

#if UDF_DEBUG_LEVEL >= UDF_LOG_LEVEL_WARNNING
#define udf_log_w(fmt, arg...) udf_log_x("WARNING", fmt, ##arg)
#else
#define udf_log_w(fmt, arg) (void)0
#endif

#if UDF_DEBUG_LEVEL >= UDF_LOG_LEVEL_DEBUG
#define udf_log_d(fmt, arg...) udf_log_x("DEBUG", fmt, ##arg)
#else
#define udf_log_d(fmt, arg) (void)0
#endif

#if UDF_DEBUG_LEVEL >= UDF_LOG_LEVEL_INFO
#define udf_log_i(fmt, arg...) udf_log_x("INFO", fmt, ##arg)
#else
#define udf_log_i(fmt, arg) (void)0
#endif
