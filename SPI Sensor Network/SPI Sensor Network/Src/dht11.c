/*
 * dht11.c
 *
 *  Created on: Feb 9, 2026
 *      Author: HP
 */


#include "dht11.h"
#include "delay.h"

/* ===== Internal functions ===== */

static void DHT_SetOutput(void)
{
    GPIO_Config(DHT_PORT, DHT_PIN, GPIO_MODE_OUTPUT_OD);
}

static void DHT_SetInput(void)
{
    GPIO_Config(DHT_PORT, DHT_PIN, GPIO_MODE_INPUT_FLOATING);
}

static uint8_t DHT_ReadBit(void)
{
    uint32_t timeout = 0;

    // Wait LOW
    while (GPIO_Read_Pin(DHT_PORT, DHT_PIN))
    {
        if (++timeout > 100) return 0;
        delay_us(1);
    }

    // Wait HIGH
    timeout = 0;
    while (!GPIO_Read_Pin(DHT_PORT, DHT_PIN))
    {
        if (++timeout > 100) return 0;
        delay_us(1);
    }

    // Measure HIGH time
    delay_us(40);

    if (GPIO_Read_Pin(DHT_PORT, DHT_PIN))
        return 1;
    else
        return 0;
}

static uint8_t DHT_ReadByte(void)
{
    uint8_t i, byte = 0;

    for (i = 0; i < 8; i++)
    {
        byte <<= 1;
        byte |= DHT_ReadBit();
    }

    return byte;
}

/* ===== Public function ===== */

uint8_t DHT_Read(DHT_Data_t *data)
{
    uint8_t checksum;
    uint8_t buf[5];

    // Start signal
    DHT_SetOutput();
    GPIO_Write_Pin(DHT_PORT, DHT_PIN, 0);
    delay_ms(18);

    GPIO_Write_Pin(DHT_PORT, DHT_PIN, 1);
    delay_us(30);
    DHT_SetInput();

    // Check response LOW (80 us)
    if (GPIO_Read_Pin(DHT_PORT, DHT_PIN))
        return 1;
    delay_us(80);

    // Check response HIGH (80 us)
    if (!GPIO_Read_Pin(DHT_PORT, DHT_PIN))
        return 2;
    delay_us(80);

    // Read 5 bytes
    for (int i = 0; i < 5; i++)
        buf[i] = DHT_ReadByte();

    checksum = buf[0] + buf[1] + buf[2] + buf[3];

    if (checksum != buf[4])
        return 3;

    data->humidity_int     = buf[0];
    data->humidity_dec     = buf[1];
    data->temperature_int  = buf[2];
    data->temperature_dec  = buf[3];

    return 0; // OK
}
