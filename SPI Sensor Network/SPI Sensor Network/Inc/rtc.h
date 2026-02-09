/*
 * rtc.h
 *
 *  Created on: Feb 9, 2026
 *      Author: HP
 */

#ifndef RTC_H_
#define RTC_H_

#include <stdint.h>

typedef struct {
    uint8_t sec;
    uint8_t min;
    uint8_t hour;
    uint8_t day;
    uint8_t date;
    uint8_t month;
    uint8_t year;
} RTC_Time;

void RTC_Init(void);
void RTC_SetTime(RTC_Time *t);
void RTC_GetTime(RTC_Time *t);

#endif /* RTC_H_ */
