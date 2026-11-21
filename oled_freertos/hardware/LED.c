#include "stm32f10x.h"                  // Device header
#include "urdevice.h"

void LED_Init(void)        /* 上电初始化 */
{
	/* 1. 开启时钟 */
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);
	
    /* 2. 配置引脚参数 */
	GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin   = LED_GPIO_PIN;        // 选 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   // 输出速率
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;   // 推挽输出
    GPIO_Init(LED_GPIO_PORT, &GPIO_InitStructure);
	
}
void LED_On(void)          /* 引脚置低，点亮 */
{
	GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_PIN);
}
void LED_Off(void)        /* 引脚置高，熄灭 */
{
	GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_PIN);
}
void LED_Toggle(void)      /* 翻转 */
{
	if(GPIO_ReadOutputDataBit(LED_GPIO_PORT, LED_GPIO_PIN) == 1 )
		GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_PIN);
	else
		GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_PIN);
}



