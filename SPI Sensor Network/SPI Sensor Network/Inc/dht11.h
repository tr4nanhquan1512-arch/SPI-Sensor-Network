/*
 * dht11.h
 *
 *  Created on: Feb 9, 2026
 *      Author: HP
 */

#ifndef DHT11_H_
#define DHT11_H_

#include <stdint.h>
#include "GPIO.h"

// Cấu hình chân DHT
#define DHT_PORT   GPIOA
#define DHT_PIN    GPIO_PIN_1

typedef struct {
    uint8_t humidity_int;
    uint8_t humidity_dec;
    uint8_t temperature_int;
    uint8_t temperature_dec;
} DHT_Data_t;

uint8_t DHT_Read(DHT_Data_t *data);

#endif /* DHT11_H_ */
