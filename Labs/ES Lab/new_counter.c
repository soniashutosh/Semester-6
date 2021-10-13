// #include <reg51.h>

// #define SegOne   0x08
// #define SegTwo   0x04
// #define SegThree 0x02
// #define SegFour  0x01   

// void DELAY_ms(unsigned int ms_Count)
// {
//     unsigned int i,j;
//     for(i=0;i<ms_Count;i++)
//     {
//         for(j=0;j<100;j++);
//     }
// }

// int main() 
// {
//     char seg_code[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
//     int cnt, num, temp,i;

//     while (1) 
//     {
//         for (cnt = 0x00; cnt <= 9999; cnt++) // loop to display 0-9999
//         {
//             for (i = 0; i < 100; i++)
//             {
//                 num = cnt;
//                 temp = num / 1000;
//                 num = num % 1000;
//                 P0 = SegOne; 
//                 P2 = seg_code[temp];               

//                 DELAY_ms(1);

//                 temp = num / 100;
//                 num = num % 100;
//                 P0 = SegTwo; 
//                 P1 = seg_code[temp];

//                 DELAY_ms(1);

//                 temp = num / 10;
//                 P0 = SegThree;  // to : control pin(LEFT pin of 7segment)
//                 P2 = seg_code[temp];	// to : data pin(RIGHT pin of 7segment)

//                 DELAY_ms(1);

//                 temp = num % 10;
//                 P0 = SegFour;
//                 P2 = seg_code[temp];

//                 DELAY_ms(1);                              
//             }
//         }
//     }
// }