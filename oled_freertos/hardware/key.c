#include "stm32f10x.h"                  // Device header
#include "urdevice.h"
#include "Delay.h"

void KEY_Init(void)        /* 上电初始化 */
{
	/* 1. 开启时钟 */
	RCC_APB2PeriphClockCmd(KEY_GPIO_CLK, ENABLE);
	
    /* 2. 配置引脚参数 */
	GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin   = KEY_GPIO_PIN;        // 选 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   // 输出速率
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPU;   // 上拉输入
    GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStructure);
}

uint8_t key_check(void)        
{
	uint8_t KeyNum = 0;
	if(GPIO_ReadInputDataBit(KEY_GPIO_PORT, KEY_GPIO_PIN) == 0 )
	{
		Delay_ms(20);											//延时消抖
		while (GPIO_ReadInputDataBit(KEY_GPIO_PORT, KEY_GPIO_PIN) == 0);	//等待按键松手
		Delay_ms(20);
		KeyNum = 1;
	}	
	return KeyNum;
}
