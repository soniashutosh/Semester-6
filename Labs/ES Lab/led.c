#include <reg51.h>

void delay(int count)
{
	int i, j;
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < 10000; j++)
		{
		}
	}
}

void main()
{
	while (1)
	{
		P1 = 0x01;
		delay(10);
		P1 = 0x06;
		delay(10);
	}
}