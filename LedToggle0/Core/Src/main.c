// Where LED is connected
// Port: A
// Pin:  5

#define IOPORT_BASE  (0x50000000UL)
#define GPIOA_OFFSET (0x00000000UL)
#define GPIOA_BASE   (IOPORT_BASE + GPIOA_OFFSET)




/*#define RCC_BASE     (0x40021000UL)
#define RCC_IOPENR_OFFSET (0x34UL)
#define RCC_AHBENR_R (*(volatile unsigned int *)(RCC_BASE + RCC_IOPENR_OFFSET))
*/

#define PERIPH_BASE           (0x40000000UL)  /*!< Peripheral base address */
/*!< Peripheral memory map */
#define APBPERIPH_BASE        (PERIPH_BASE)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000UL)
#define RCC_BASE              (AHBPERIPH_BASE + 0x00001000UL)

#define RCC_IOPEN_R_OFFSET (0x34UL)
#define RCC_IOPEN_R (*(volatile unsigned int *)(RCC_BASE + RCC_IOPEN_R_OFFSET))

#define MODER_OFFSET (0x00000000UL)
#define GPIOA_MODER_R  (*(volatile unsigned int *)(IOPORT_BASE + MODER_OFFSET))
//#define GPIOA_MODER_R  (*(volatile unsigned int *)(IOPORT_BASE + GPIOA_BASE))


#define OD_R_OFFSET (0x14UL)
#define GPIOA_OD_R (*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))

#define PIN5  (1U<<5)
#define LED_PIN PIN5

#define GPIOAEN  (1U<<0)

/* (1U<<10) Set bit 10 to 1
 * &=~(1U<<11) Set bit 11 to 0
 *  */
int main(void)
{
/* 1. Enable clock access to GPIOA */
//RCC_AHBEN_R |= GPIOAEN;
	RCC_IOPEN_R |= GPIOAEN;

/* 2. Set PA5 pin as out put */
GPIOA_MODER_R |= (1U<<10); // Set bit 10 to 1
GPIOA_MODER_R &=~(1U<<11); // Set bit 11 to 0

while(1)
{
/* Set PA5 high */
//GPIOA_OD_R |= LED_PIN;
/*Toggle PA5 */
GPIOA_OD_R ^= LED_PIN;
for(int i=0; i<100000;i++);
}
}
