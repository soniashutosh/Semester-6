// /*------------------------------------------------------------------------------
// HELLO.C

// Copyright 1995-2005 Keil Software, Inc.
// ------------------------------------------------------------------------------*/
// #include <stdlib.h>
// #include <REG51.H> /* special function register declarations   */
//                    /* for the intended 8051 derivative         */
// void delay3()
// {

//     int count1 = 70, count2 = 1000;
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

//     unsigned char to_disp[] = {0x3F, 0x06, 0x5B, 0x5F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7F, 0x39, 0x79, 0x71};

//     unsigned char abcd[] = {0x`77, 0x7f, 0x39, 0x3f,0x79,0x71,0x7d,0x76};
//     unsigned char to_dig[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
// 	unsigned char to_dig1[] = {0x, 0x, 0x, 0x, 0x, 0x, 0x, 0x, 0x, 0x};
//     unsigned char led[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

//     unsigned char test1[] = {0x77, 0x60};

//     int k;
// 	int sz;
//     while (1)
//     {
        
//         P0 = 8;
//         // sz= sizeof(abcd)/sizeof(abcd[0]);
//         // for(k = 0; k < sz; ++k) {
//         //     P2 = abcd[k];
//         //     delay3();
//         // }

//         for(k = 0;k<10;k++) {
//             // P2 = test1[k];
//             P2 = to_disp[k];
//             delay3();
//         }
        
//         // for (k = 0; k < 16; k++)
//         // {
//         //     P2 = to_disp[k];
//         //     P1 = led[k];
//         //     delay3();
//         // }
//         // for (k = 15; k >= 0; k--)
//         // {
//         //     P2 = to_disp[k];
//         //     P1 = led[k];
//         //     delay3();
//         // }
//     }
// }
