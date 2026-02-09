#include "I2C.h"
#include"delay.h"
#include"stm32f103.h"

void I2C_Init(void){
	I2C1_CR1 &= ~(uint32_t)(1 << 0);
	I2C1_CR2 = 8;
	I2C1_CCR = 40;
	I2C1_TRISE = 9;
	I2C1_CR1 |= (1 << 0);
}

void I2C_GPIO_Init(void)
{
	 /* PB6, PB7: clear config */
	    GPIOB_CRL &= ~((0xF << 24) | (0xF << 28));

	    /* AF Open-Drain, output 2MHz
	       MODE = 10, CNF = 11 → 0b1110 = 0xE */
	    GPIOB_CRL |= (0xE << 24); // PB6
	    GPIOB_CRL |= (0xE << 28); // PB7

}

void I2C_Start(void){

	I2C1_CR1 &= ~(uint32_t)(1 << 9);
	I2C1_CR1 |= (1 << 8);
	while(!(I2C1_SR1 & 0x01)){

	}
	//Doing sth
}
void I2C_Stop(void){

	I2C1_CR1 |= (1 << 9);

}
void I2C_Send_Addr(uint8_t addr, uint8_t rw){

	I2C1_DR = (uint32_t)((addr << 1) | (rw & 0x01));
  while(!(I2C1_SR1 & (1 << 1))){
	}
  	(void)I2C1_SR1;
	(void)I2C1_SR2;
}
uint8_t I2C_Send_Data(uint8_t data){

	I2C1_DR = data;
	while(!(I2C1_SR1 & (1 << 2))){
	}
	if(I2C1_SR1 & (1 << 10)){
		I2C1_SR1 &= ~(uint32_t)(1 << 10);
		I2C_Stop();
		return 1;
	}
	return 0;

}
uint8_t I2C_Read_Data(uint8_t ack){

	if(ack){
		I2C1_CR1 |= (1 << 10); // ack = 1;
	}else{
		I2C1_CR1 &= ~(uint32_t)(1 << 10); //ack = 0;
	}

	while(!(I2C1_SR1  & (1 << 6))){
	}

	return (uint8_t)I2C1_DR;

}

