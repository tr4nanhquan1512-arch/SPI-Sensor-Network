#include "delay.h"
#include "LED.h"
#include "adc.h"
#include "dht11.h"
#include "lcd.h"
#include "i2c.h"

int main(void)
{
    DHT_Data_t dht;
    uint16_t soil;

    LED_Init();
    ADC01_CH0_Init();
    I2C_Init();
    LCD_Init();

    while (1)
    {
        if (DHT_Read(&dht) == 0)
        {
            LCD_SetCursor(0,0);
            LCD_Print("T:");
            LCD_PrintNum(dht.temperature_int);
            LCD_Print(".");
            LCD_PrintNum(dht.temperature_dec);
            LCD_Print("C ");

            LCD_SetCursor(0,1);
            LCD_Print("H:");
            LCD_PrintNum(dht.humidity_int);
            LCD_Print(".");
            LCD_PrintNum(dht.humidity_dec);
            LCD_Print("% ");
        }
        else
        {
            LCD_SetCursor(0,0);
            LCD_Print("DHT ERROR    ");
        }

        soil = ADC01_CH0_Read();

        if (soil < 2000)
            LED_On();
        else
            LED_Off();

        delay_ms(1000);
    }
}
