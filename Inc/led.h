/*
 * led.h
 *
 *  Created on: Aug 11, 2025
 *      Author: shreyaa_vinod
 */

#ifndef LED_H_
#define LED_H_

//======CREATING MACROS AND STRUCTS FOR THE GPIOX PERIPHERALS OF STM32F446RE========//
typedef struct {
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;

} GPIO_typedef_struct;


//MACROS

#define  GPIOA     (GPIO_typedef_struct*) 0x40020000U

#define  GPIOB     (GPIO_typedef_struct*) 0x40020400U
#define  GPIOC     (GPIO_typedef_struct*) 0x40020800U
#define  GPIOD     (GPIO_typedef_struct*) 0x40020C00U
#define  GPIOE     (GPIO_typedef_struct*) 0x40021000U
#define  GPIOF     (GPIO_typedef_struct*) 0x40021400U
#define  GPIOG     (GPIO_typedef_struct*) 0x40021800U
#define  GPIOH     (GPIO_typedef_struct*) 0x40021C00U

//gpio pins
#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7
#define GPIO_PIN8 8
#define GPIO_PIN9 9
#define GPIO_PIN10 10
#define GPIO_PIN11 11
#define GPIO_PIN12 12
#define GPIO_PIN13 13
#define GPIO_PIN14 14
#define GPIO_PIN15 15


//function prototypes
uint32_t positional_val(GPIO_typedef_struct *GPIOx);
void gpio_perip_clk_enable(GPIO_typedef_struct *GPIOx);
void led_init(GPIO_typedef_struct * GPIOx,uint32_t GPIO_PIN);
void led_toggle(GPIO_typedef_struct* GPIOx , uint32_t GPIO_PIN);

#endif /* LED_H_ */
