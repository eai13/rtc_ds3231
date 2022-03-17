#ifndef RTC_DS3231_H
#define RTC_DS3231_H

#include "main.h"
#include "stdint.h"
#include "i2c.h"

#define DS3231_I2C_ADDRESS      0b11010000

#define DS3231_I2C_HANDLE       hi2c2

#define DS3231_REGISTER_SIZE    1

typedef enum{
    DS3231_SECONDS              = 0x00,
    DS3231_MINUTES              = 0x01,
    DS3231_HOURS                = 0x02,
    DS3231_DAY                  = 0x03,
    DS3231_DATE                 = 0x04,
    DS3231_MONTH_CENTURY        = 0x05,
    DS3231_YEAR                 = 0x06,
    DS3231_ALARM_1_SEC          = 0x07,
    DS3231_ALARM_1_MIN          = 0x08,
    DS3231_ALARM_1_HOUR         = 0x09,
    DS3231_ALARM_1_DAY_DATE     = 0x0A,
    DS3231_ALARM_2_MIN          = 0x0B,
    DS3231_ALARM_2_HOUR         = 0x0C,
    DS3231_ALARM_2_DAY_DATE     = 0x0D,
    DS3231_CONTROL_1            = 0x0E,
    DS3231_CONTROL_2            = 0x0F,
    DS3231_STATUS               = 0x0F,
    DS3231_AGING_OFFSET         = 0x10,
    DS3231_TEMP_MSB             = 0x11,
    DS3231_TEMP_LSB             = 0x12
}ds3231_registers_en;

typedef enum{
    DS3231_INIT_NO_RESET    = 0,
    DS3231_INIT_FULL_RESET  = 1
}ds3231_init_flag_en;

HAL_StatusTypeDef DS3231_Init(ds3231_init_flag_en flag);

HAL_StatusTypeDef DS3231_GetSeconds(uint8_t * seconds);
HAL_StatusTypeDef DS3231_WriteSeconds(uint8_t seconds);

HAL_StatusTypeDef DS3231_GetMinutes(uint8_t * minutes);
HAL_StatusTypeDef DS3231_WriteMinutes(uint8_t minutes);

HAL_StatusTypeDef DS3231_GetHours(uint8_t * hours);
HAL_StatusTypeDef DS3231_WriteHours(uint8_t hours);

HAL_StatusTypeDef DS3231_GetDay(uint8_t * day);
HAL_StatusTypeDef DS3231_WriteDay(uint8_t day);

HAL_StatusTypeDef DS3231_GetDate(uint8_t * date);
HAL_StatusTypeDef DS3231_WriteDate(uint8_t date);

HAL_StatusTypeDef DS3231_GetMonth(uint8_t * month);
HAL_StatusTypeDef DS3231_WriteMonth(uint8_t month);

HAL_StatusTypeDef DS3231_GetCentury(uint8_t * century);
HAL_StatusTypeDef DS3231_WriteCentury(uint8_t century);

HAL_StatusTypeDef DS3231_GetYear(uint8_t * year);
HAL_StatusTypeDef DS3231_WriteYear(uint8_t year);

HAL_StatusTypeDef DS3231_GetTemperature(uint16_t * temp);

#endif