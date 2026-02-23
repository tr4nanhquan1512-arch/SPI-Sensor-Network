# SPI Sensor Network

## 1. Giới thiệu chung
Đây là dự án cuối khóa của HCMUT EE Machine Learning & IOT Lab, một dự án bare-metal C về mạng cảm biến có dây sử dụng giao tiếp SPI lập trình thuần register-level (no HAL, no CubeMX). 

## 2. Mục tiêu 
Thực hành lập trình thanh ghi C trên STM32F103C8T6 <br>
Áp dụng Finite State Machine để logic hóa các luồng trạng thái Master-Slave. <br>
Học tài liệu hóa dự cũng như tư duy level hệ thống cho các dự án 

## 3. Phần cứng
MCU: STM32F103C8T6  
Display: LCD 1602 HD44780 (I2C)  
[LCD I2C](https://hshop.vn/lcd-text-lcd1602-xanh-lo)  
Cảm biến: Cảm biến nhiệt độ độ ẩm DHT11, cảm biến độ ẩm đất điện dung  
Module RTC  <br>
Programmer: ST-Link  
Phụ kiện: Mạch chuyển đổi giao tiếp LCD sang I2C, Level-shifter mạch chuyển mức logic 3V3 <-> 5V 

## Cài đặt
STM32CubeIDE  
ST-Link Driver  
Debug LCD: PuTTY

## 4. Kiến trúc phần mềm
### System State Machine
Lưu đồ này mô tả trạng thái tổng thể trạng thái diễn ra của Master và các Slave <br>
<p align="center">
  <img src="SPI Sensor Network/SPI Sensor Network/images/spi_network_fsm.png" alt="SPI Sensor Network State Machine" width="700">
</p>

## 5.Video Demo
▶️ [SPI Sensor Network - Demo Video](https://youtu.be/IXFp3IMizs0)
## 6. Kết luận
Em xin giải thích thêm về kết quả dự án. Em đã làm xong phần mềm và các phần cứng khác. Tuy nhiên, em gặp vấn đề ở bước cuối cùng là xuất ra LCD thì em không làm nó xuất ra được.
Em đã dùng rất nhiều thời gian và nỗ lực để test xuất kết quả ra LCD 1602. <br>
Em xin được nói thêm về quá trình em gặp khó khăn này. Ban đầu khi em nối PCF8574 chung với nguồn 5V từ MCU thì kết quả LCD bị mờ đục thấy ô vuông rất mờ. Em nghĩ LCD bị hư nên có đem ra tiệm test luôn nhưng không phải. Cuối cùng em tìm ra là nếu cấp nguồn 5V từ MCU cho PCF8574 và LCD thì do sụt áp thì LCD sẽ sáng mờ do LCD nhạy dòng. Từ đó em mua thêm adapter 5V 3A để làm nguồn nuôi riêng cho LCD thì đã có kết quả là LCD sáng rõ <br>
Nhưng LCD vẫn chưa xuất ra. Em lại mày mò test rất nhiều cách, em tìm ra là phải có mạch chuyển tín hiệu 4 kênh I2C để chuyển tín hiệu 3V3 logic của MCU thành tín hiệu 5V logic của LCD. Sau đó em cũng đã test riêng xuất LCD trong Arduino IDE, thì nếu không có PCF8574 thì LCD xuất được nhưng có thêm mạch chuyển tín hiệu I2C và PCF8574 thì nó không xuất ra được gì hết. Từ lúc đó em vẫn chưa tìm ra cách để LCD xuất kết quả. <br>
Kết luận: Em tự nhận xét là mình chưa hoàn thành yêu cầu đặt ra của dự án. Tuy vậy trong quá trình làm dự án em đã học được thêm nhiều kinh nghiệm thực hành thực tế như phải tính toán tới nguồn nuôi và mức logic,... Đây là kinh nghiệm quý báu cho em vì nếu không làm dự án thực tế thì sẽ không có được. Em xin cảm ơn các anh TA đã hỗ trợ tụi em nhiều trong khóa học.

