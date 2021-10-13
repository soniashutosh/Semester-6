/*------------------------------------------------------------------------------
HELLO.C

Copyright 1995-2005 Keil Software, Inc.
------------------------------------------------------------------------------*/

#include <stdlib.h>
#include <REG51.H> /* special function register declarations   */
                   /* for the intended 8051 derivative         */
void delay3()
{

    int count1 = 10, count2 = rand() % 1000 + 1000;
    int i = 0, j = 0;
    for (i = 0; i < count1; i++)
    {
        for (j = 0; j < count2; j++)
        {
        }
    }
}

void main(void)
{

    int dir = 1;
    int cbit = 1;

    while (1)
    {
        // P1 = 0x01;     		    /* Toggle P1.0 each time we print */
        // delay();   /* Print "Hello World" */

        // P1 = 0x05;     		    /* Toggle P1.0 each time we print */
        // delay();   /* Print "Hello World" */

        delay3();
        P1 = cbit;

        if (cbit == 8)
        {
            cbit = 256;
            dir = 0;
        }
        else if (cbit == 16)
        {
            cbit = 1;
            dir = 1;
        }
        else if (dir == 1)
            cbit <<= 1;
        else
            cbit >>= 1;
    }
}
