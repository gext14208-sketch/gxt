#ifndef __LED_H
#define __LED_H


void LED_Init(void);          /* 上电初始化，只调用一次 */
void LED_On(void);           /* 点亮 */
void LED_Off(void);          /* 熄灭 */
void LED_Toggle(void);       /* 翻转 */


#endif 
