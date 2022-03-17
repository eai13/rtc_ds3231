#include "ds3231.h"

static inline HAL_StatusTypeDef DS3231_I2C_Read(ds3231_registers_en reg, uint8_t * buffer, uint8_t amount){
    return HAL_I2C_Mem_Read(&DS3231_I2C_HANDLE, DS3231_I2C_ADDRESS, reg, DS3231_REGISTER_SIZE, buffer, amount, 100);
}
static inline HAL_StatusTypeDef DS3231_I2C_Write(ds3231_registers_en reg, uint8_t * buffer, uint8_t amount){
    return HAL_I2C_Mem_Write(&DS3231_I2C_HANDLE, DS3231_I2C_ADDRESS, reg, DS3231_REGISTER_SIZE, buffer, amount, 100);
}

HAL_StatusTypeDef DS3231_Init(ds3231_init_flag_en flag){
    HAL_StatusTypeDef status;
    if (flag == DS3231_INIT_FULL_RESET){
        uint8_t buffer[7] = { 0 };
        status = DS3231_I2C_Write(0x00, buffer, sizeof(buffer));
    }
    else{
        uint8_t buffer;
        status = DS3231_I2C_Read(0x00, &buffer, 1);
    }
    return status;
}

HAL_StatusTypeDef DS3231_GetSeconds(uint8_t * seconds){
    HAL_StatusTypeDef status = DS3231_I2C_Read(DS3231_SECONDS, seconds, 1);
    *seconds = ((*seconds) >> 4) * 10 + ((*seconds) & 0b1111);
    return status;
}
HAL_StatusTypeDef DS3231_WriteSeconds(uint8_t seconds){
    seconds = ((seconds / 10) << 4) | (seconds % 10);
    return DS3231_I2C_Write(DS3231_SECONDS, &seconds, 1);
}

HAL_StatusTypeDef DS3231_GetMinutes(uint8_t * minutes){
    HAL_StatusTypeDef status = DS3231_I2C_Read(DS3231_MINUTES, minutes, 1);
    *minutes = ((*minutes) >> 4) * 10 + ((*minutes) & 0b1111);
    return status;
}
HAL_StatusTypeDef DS3231_WriteMinutes(uint8_t minutes){
    minutes = ((minutes / 10) << 4) | (minutes % 10);
    return DS3231_I2C_Write(DS3231_MINUTES, &minutes, 1);
}

HAL_StatusTypeDef DS3231_GetHours(uint8_t * hours){
    HAL_StatusTypeDef status = DS3231_I2C_Read(DS3231_HOURS, hours, 1);
    *hours = ((*hours) & 0b1111) + (((*hours) >> 4) & 0b11) * 10;
    return status;
}
HAL_StatusTypeDef DS3231_WriteHours(uint8_t hours){
    if (hours >= 24) hours = hours % 24;
    hours = ((uint8_t)(hours / 10) << 4) | ((uint8_t)(hours % 10)) | ((uint8_t)(1 << 6));
    return DS3231_I2C_Write(DS3231_HOURS, &hours, 1);
}

HAL_StatusTypeDef DS3231_GetDay(uint8_t * day){
    return DS3231_I2C_Read(DS3231_DAY, day, 1);
}
HAL_StatusTypeDef DS3231_WriteDay(uint8_t day){
    return DS3231_I2C_Write(DS3231_DAY, &day, 1);
}

HAL_StatusTypeDef DS3231_GetDate(uint8_t * date){
    HAL_StatusTypeDef status = DS3231_I2C_Read(DS3231_DATE, date, 1);
    *date = ((*date) >> 4) * 10 + ((*date) & 0b1111);
    return status;
}
HAL_StatusTypeDef DS3231_WriteDate(uint8_t date){
    date = ((date / 10) << 4) | (date % 10);
    return DS3231_I2C_Write(DS3231_DATE, &date, 1);
}

HAL_StatusTypeDef DS3231_GetMonth(uint8_t * month){
    HAL_StatusTypeDef status = DS3231_I2C_Read(DS3231_MONTH_CENTURY, month, 1);
    *month = ((*month) >> 4) * 10 + ((*month) & 0b1111);
    return status;
}
HAL_StatusTypeDef DS3231_WriteMonth(uint8_t month){
    month = ((month / 10) << 4) | (month % 10);
    return DS3231_I2C_Write(DS3231_MONTH_CENTURY, &month, 1);
}

HAL_StatusTypeDef DS3231_GetCentury(uint8_t * century){
    HAL_StatusTypeDef status = DS3231_I2C_Read(DS3231_MONTH_CENTURY, century, 1);
    *century = (*century) >> 7;
    return status;
}
HAL_StatusTypeDef DS3231_WriteCentury(uint8_t century){
    // NONE
}

HAL_StatusTypeDef DS3231_GetYear(uint8_t * year){
    // NONE
}
HAL_StatusTypeDef DS3231_WriteYear(uint8_t year){
    // NONE
}

HAL_StatusTypeDef DS3231_GetTemperature(uint16_t * temp){
    // NONE
}