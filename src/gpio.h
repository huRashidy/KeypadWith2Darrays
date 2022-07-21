/*
 * gpio.h
 *
 *  Created on: Apr 30, 2022
 *      Author: moham
 */
#include "stm32f4xx_it.h"

#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_

void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin);
char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state);
char GPIO_ReadPin(GPIO_TypeDef * GPIOx,char pin);

#endif /* INCLUDE_GPIO_H_ */
