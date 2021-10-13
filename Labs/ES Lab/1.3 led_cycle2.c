// wave.h
#include <stdlib.h>
#include <REG51.H> /* special function register declarations   */

#define ZERO 0x00
#define ONE 0x01
#define TWO 0x02
#define THREE 0x04
#define FOUR 0x08
#define FIVE 0x10
#define SIX 0x20
#define SEVEN 0x40
#define EIGHT 0x80

#define FORWARD +1
#define BACKWARD -1
const int lim = 5;

void delay2()
{
    int count1 = 10, count2 = 1000; // rand() % 1000 + 1000;
    int i = 0, j = 0;
    for (i = 0; i < count1; i++)
        for (j = 0; j < count2; j++)
            ;
}

void main(void)
{
    int mask[] = {ONE|TWO, TWO|THREE, THREE|FOUR, FOUR|EIGHT, EIGHT|SEVEN, SEVEN|SIX, SIX|FIVE, FIVE|ONE};
    int i = 0;
    // int mask2[] = {ZERO, ONE, ONE|SIX, ONE|SIX|THREE, ONE|SIX|THREE|EIGHT}; 
    while (1)
    {
        P1 = mask[i++];
        delay2();
        i %= 8;       
    }
}
