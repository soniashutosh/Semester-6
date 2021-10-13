// /*------------------------------------------------------------------------------
// HELLO.C

// Copyright 1995-2005 Keil Software, Inc.
// ------------------------------------------------------------------------------*/
// #include <stdlib.h>
// #include <REG51.H> /* special function register declarations   */
//                    /* for the intended 8051 derivative         */
// void delay3()
// {

//     int count1 = 30, count2 = 1000;
//     int i = 0, j = 0;
//     for (i = 0; i < count1; i++)
//     {
//         for (j = 0; j < count2; j++)
//         {
//         }
//     }
// }

// void main(void)
// {

//     unsigned char to_disp[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7F, 0x39, 0x79, 0x71};

//     unsigned char test1[] = {0x77, 0x60};

//     int k;
//     while (1)
//     {
        
//         P0 = 15;
        
//         for (k = 0; k < 9; k++)
//         {
//             P2 = to_disp[k];
//             delay3();
//         }
//         for (k = 8; k >= 0; k--)
//         {
//             P2 = to_disp[k];
//             delay3();
//         }
//     }
// }
