# SPI Sensor Network

## 1. Giới thiệu chung
Đây là dự án cuối khóa của HCMUT EE Machine Learning & IOT Lab, một dự án bare-metal C về mạng cảm biến có dây sử dụng giao tiếp SPI lập trình thuần register-level (no HAL, no CubeMX). 

## 2. Mục tiêu 
Thực hành lập trình thanh ghi C trên STM32F103C8T6
Áp dụng Finite State Machine để logic hóa các luồng trạng thái Master-Slave.
Học tài liệu hóa dự cũng như tư duy level hệ thống cho các dự án 

## 3. Phần cứng
MCU: STM32F103C8T6  
Display: LCD 1602 HD44780 (I2C)  
[LCD I2C](https://hshop.vn/lcd-text-lcd1602-xanh-lo)  
Programmer: ST-Link  
Phụ kiện: Mạch chuyển đổi giao tiếp LCD sang I2C, Level-shifter mạch chuyển mức logic 3V3 <-> 5V 

## Cài đặt
STM32CubeIDE  
ST-Link Driver  
Debug LCD: PuTTY

## 4. Kiến trúc phần mềm 


