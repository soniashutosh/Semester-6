// #include <reg52.h>
// sbitLED_pin = P1^5;
// bit LED_state_G;

// void LED_FLASH_Init(void);
// void LED_FLASH_Change_State(void);
// void DELAY_LOOP_Wait(const unsigned int);

// void main(void)
// {
// 	LED__FLASH_Init();

// 	while (1)
// 	{
// 		LED_FLASH_Change_State();
// 		DELAY_LOOP_Wait(1000);
// 	}
// }

// void LED_FLASH_Init(void)
// {
// 	LED_state_G=0;
// }

// void LED_FLASH_Change_State(void)
// {
// 	if (LED_state_G ==1)
// 	{
// 		LED_state_G = 0;
// 		LED_pin = 0;
// 	}
// 	else
// 	{
// 		LED_state_G = 1;
// 		LED_pin =1;
// 	}
// }

// void DELAY_LOOP_Wait(const unsigned int DELAY)
// {
// 	unsigned int x, y;
// 	for (x=0 ; x<= DELAY; x++)
// 	{
// 		for (y=0; y<=120 : y++)
// 	}
// }
