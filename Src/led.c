/*
 * led.c
 *
 *  Created on: Aug 11, 2025
 *      Author: shreyaa_vinod
 */

//============================TO CONFIGURE 4 GPIO PINS AS OUTPUT AND TO CONNECT LEDS AND WITH DELAY MAKE THEM GLOW USING SEPREATE TASKS

#include<stdio.h>
#include<stdint.h>
#include "led.h"

uint32_t positional_val(GPIO_typedef_struct *GPIOx)
{

	uint32_t result= (GPIOx==GPIOA?0:(GPIOx==GPIOB?1:(GPIOx==GPIOC?2:(GPIOx==GPIOD?3:(GPIOx==GPIOE?4:(GPIOx==GPIOF?5:(GPIOx==GPIOG?6:(GPIOx==GPIOH?7:-1))))))));
	return result;
}
void gpio_perip_clk_enable(GPIO_typedef_struct *GPIOx)
{
	uint32_t *RCC_AHB1ENR= (uint32_t *) 0x40023830U;

	*RCC_AHB1ENR |=(0X1<<positional_val(GPIOx));
}


void led_init(GPIO_typedef_struct * GPIOx,uint32_t GPIO_PIN)
{
	gpio_perip_clk_enable(GPIOx);
	GPIOx->MODER &= ~(0x3<<2*(GPIO_PIN));
	GPIOx->MODER |= (0x1<<2*(GPIO_PIN));

	GPIOx->OSPEEDR  &= ~(0x3<<2*(GPIO_PIN));
	GPIOx->OSPEEDR |= (0x2<<2*(GPIO_PIN));

	GPIOx->OTYPER &= ~(0x1<<(GPIO_PIN));
	GPIOx->OTYPER |= (0x0<<(GPIO_PIN));

	GPIOx->PUPDR &= ~(0x3<<2*(GPIO_PIN));
	GPIOx->PUPDR |= (0x0<<2*(GPIO_PIN));


}


void led_toggle(GPIO_typedef_struct* GPIOx , uint32_t GPIO_PIN)
{
	//TOGGLING THE LED
	if ((GPIOx->ODR & (0x1<<GPIO_PIN))==0)
	{
		GPIOx->ODR |= (0x1<<GPIO_PIN);

	}
	else
	{
		GPIOx->ODR &= ~(0x1<<GPIO_PIN);
	}


}
