#ifndef _HOST_PIN_DEF_H
#define _HOST_PIN_DEF_H

#ifdef __cplusplus
 extern "C" {
#endif

#define VER_RELEASE         0
#define VER_DEBUG			1

#define VERSION VER_DEBUG

typedef union 
{ 
   unsigned char REG8; 
   struct BIT 
   { 
     unsigned char B0:1;
     unsigned char B1:1;
     unsigned char B2:1;
     unsigned char B3:1;
     unsigned char B4:1;
     unsigned char B5:1;
     unsigned char B6:1;
     unsigned char B7:1;
   }; 
}FSR;

#define PORTA_out ((FSR *)  GPIOA_BaseAddress)
#define PORTA_in  ((FSR *) (GPIOA_BaseAddress+1))
#define PORTA_DDR ((FSR *) (GPIOA_BaseAddress+2))
#define PORTA_CR1 ((FSR *) (GPIOA_BaseAddress+3))
#define PORTA_CR2 ((FSR *) (GPIOA_BaseAddress+4))

#define PORTB_out ((FSR *)  GPIOB_BaseAddress)
#define PORTB_in  ((FSR *) (GPIOB_BaseAddress+1))
#define PORTB_DDR ((FSR *) (GPIOB_BaseAddress+2))
#define PORTB_CR1 ((FSR *) (GPIOB_BaseAddress+3))
#define PORTB_CR2 ((FSR *) (GPIOB_BaseAddress+4))

#define PORTC_out ((FSR *)  GPIOC_BaseAddress)
#define PORTC_in  ((FSR *) (GPIOC_BaseAddress+1))
#define PORTC_DDR ((FSR *) (GPIOC_BaseAddress+2))
#define PORTC_CR1 ((FSR *) (GPIOC_BaseAddress+3))
#define PORTC_CR2 ((FSR *) (GPIOC_BaseAddress+4))

#define PORTD_out ((FSR *)  GPIOD_BaseAddress)
#define PORTD_in  ((FSR *) (GPIOD_BaseAddress+1))
#define PORTD_DDR ((FSR *) (GPIOD_BaseAddress+2))
#define PORTD_CR1 ((FSR *) (GPIOD_BaseAddress+3))
#define PORTD_CR2 ((FSR *) (GPIOD_BaseAddress+4))

#define PORTE_out ((FSR *)  GPIOE_BaseAddress)
#define PORTE_in  ((FSR *) (GPIOE_BaseAddress+1))

#define PORTF_out ((FSR *)  GPIOF_BaseAddress)
#define PORTF_in  ((FSR *) (GPIOF_BaseAddress+1))
#define PORTF_DDR ((FSR *) (GPIOF_BaseAddress+2))
#define PORTF_CR1 ((FSR *) (GPIOF_BaseAddress+3))
#define PORTF_CR2 ((FSR *) (GPIOF_BaseAddress+4))

#if (VERSION == VER_RELEASE)
#elif (VERSION == VER_DEBUG)
#endif

#define REAL_BUTTON_GPIO	GPIOC
#define REAL_BUTTON_PIN		GPIO_PIN_4
#define REAL_BUTTON_OUT		(PORTC_out->B4)

#define WIHD_BUTTON_GPIO	GPIOC
#define WIHD_BUTTON_PIN		GPIO_PIN_3
#define WIHD_BUTTON_IN		(PORTC_in->B3)

#define POWER_SW_GPIO		GPIOC
#define POWER_SW_PIN		GPIO_PIN_7
#define POWER_SW_OUT		(PORTC_out->B7)

#ifdef __cplusplus
}
#endif

#endif /* _HOST_PIN_DEF_H */

