/*
 * soil.h
 *
 *  Created on: Feb 9, 2026
 *      Author: HP
 */

#ifndef SOIL_H_
#define SOIL_H_

#include <stdint.h>

void Soil_Init(void);
uint16_t Soil_ReadRaw(void);
uint8_t Soil_IsDry(uint16_t threshold);


#endif /* SOIL_H_ */
