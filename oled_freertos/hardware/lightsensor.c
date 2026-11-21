#include "stm32f10x.h"                  // Device header
#include "urdevice.h"
void lightsensor_init(void)
{
		/* 1. 开启时钟 */
	RCC_APB2PeriphClockCmd(LIGHTSENSOR_GPIO_CLK, ENABLE);
	
    /* 2. 配置引脚参数 */
	GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin   = LIGHTSENSOR_GPIO_PIN;        // 选 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   // 输出速率
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPU;   // 上拉输入
    GPIO_Init(LIGHTSENSOR_GPIO_PORT, &GPIO_InitStructure);
}

uint8_t	lightsensor_get(void)
{
	return GPIO_ReadInputDataBit(LIGHTSENSOR_GPIO_PORT,LIGHTSENSOR_GPIO_PIN);
}
