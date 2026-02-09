#include "rtc.h"
#include "I2C.h"

#define RTC_ADDR 0x68   // DS3231 (7-bit)

/* ===== BCD helpers ===== */
static uint8_t BCD_To_Dec(uint8_t val)
{
    return (val >> 4) * 10 + (val & 0x0F);
}

static uint8_t Dec_To_BCD(uint8_t val)
{
    return ((val / 10) << 4) | (val % 10);
}

/* ===== RTC Init ===== */
void RTC_Init(void)
{
    I2C_Start();
    I2C_Send_Addr(RTC_ADDR, 0);     // WRITE mode
    I2C_Send_Data(0x0E);            // Control register
    I2C_Send_Data(0x00);            // Disable SQW
    I2C_Stop();
}

/* ===== RTC Set Time ===== */
void RTC_SetTime(RTC_Time *t)
{
    I2C_Start();
    I2C_Send_Addr(RTC_ADDR, 0);     // WRITE
    I2C_Send_Data(0x00);            // Seconds register

    I2C_Send_Data(Dec_To_BCD(t->sec));
    I2C_Send_Data(Dec_To_BCD(t->min));
    I2C_Send_Data(Dec_To_BCD(t->hour));
    I2C_Send_Data(Dec_To_BCD(t->day));
    I2C_Send_Data(Dec_To_BCD(t->date));
    I2C_Send_Data(Dec_To_BCD(t->month));
    I2C_Send_Data(Dec_To_BCD(t->year));

    I2C_Stop();
}

/* ===== RTC Get Time ===== */
void RTC_GetTime(RTC_Time *t)
{
    /* Step 1: point register address */
    I2C_Start();
    I2C_Send_Addr(RTC_ADDR, 0);     // WRITE
    I2C_Send_Data(0x00);            // Seconds register

    /* Step 2: read data */
    I2C_Start();                    // Repeated START
    I2C_Send_Addr(RTC_ADDR, 1);     // READ

    t->sec   = BCD_To_Dec(I2C_Read_Data(1));
    t->min   = BCD_To_Dec(I2C_Read_Data(1));
    t->hour  = BCD_To_Dec(I2C_Read_Data(1));
    t->day   = BCD_To_Dec(I2C_Read_Data(1));
    t->date  = BCD_To_Dec(I2C_Read_Data(1));
    t->month = BCD_To_Dec(I2C_Read_Data(1));
    t->year  = BCD_To_Dec(I2C_Read_Data(0)); // NACK cuối

    I2C_Stop();
}
