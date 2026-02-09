/*
 * SOIL.c
 *
 *  Created on: Feb 9, 2026
 *      Author: HP
 */


#include "soil.h"
#include "ADC.h"

void Soil_Init(void)
{
    ADC01_CH0_Init();
}

uint16_t Soil_ReadRaw(void)
{
    return ADC01_CH0_Read();
}

uint8_t Soil_IsDry(uint16_t threshold)
{
    uint16_t value = Soil_ReadRaw();
    return (value < threshold);
}
