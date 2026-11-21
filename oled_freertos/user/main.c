#include "stm32f10x.h"                  // Device header
#include "Delay.h"    
#include "LED.h"
#include "key.h"
#include "lightsensor.h"
#include "OLED.h"

int main(void)
{
	LED_Init();          /* 上电初始化，只调用一次 */
	KEY_Init();
	lightsensor_init();
	LED_On();
	uint8_t keynum;
	uint8_t lightsensor;
	OLED_Init();
	OLED_Clear();

    while (1)
    {
		keynum=key_check();
		if(keynum == 1 )
		{
			LED_Toggle();	
			
		}	
		lightsensor = lightsensor_get();

		if(lightsensor == 1)
		{
			LED_On();
			OLED_Clear();
			OLED_ShowString(1,1,"lightsensor=1");
			Delay_ms(20);
		}
		else
		{
			LED_Off();
			OLED_Clear();
			OLED_ShowString(1,1,"lightsensor=0");
			Delay_ms(20);
		}
		
    }
	
}
