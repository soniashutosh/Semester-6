// #include <reg51.h>
// #define lcd P0
// #define keyport P1

// sbit rs = P0 ^ 0;
// sbit e = P0^ 1;

// void delay(int);
// void cmd(char);
// void display(char);
// void custom(void);
// void string(char *);
// void init(void);

// unsigned char custom_char[] = {
//     0x00,
//     0x04,
//     0x0E,
//     0x04,
//     0x15,
//     0x0E,
//     0x04,
//     0x00,
//     0x00,
//     0x04,
//     0x0E,
//     0x0E,
//     0x0E,
//     0x1F,
//     0x04,
//     0x00,
//     0x00,
//     0x0A,
//     0x15,
//     0x11,
//     0x11,
//     0x0A,
//     0x04,
//     0x00,
//     0x0E,
//     0x11,
//     0x11,
//     0x1F,
//     0x1B,
//     0x1B,
//     0x1B,
//     0x1F,
//     0x0E,
//     0x11,
//     0x10,
//     0x1F,
//     0x1B,
//     0x1B,
//     0x1B,
//     0x1F,
//     0x00,
//     0x0E,
//     0x15,
//     0x1B,
//     0x0E,
//     0x0E,
//     0x00,
//     0x00,
// };

// unsigned char keypad[4][4] = {{'7', '8', '9', '/'},
//                               {'4', '5', '6', 'x'},
//                               {'1', '2', '3', '-'},
//                               {' ', '0', '=', '+'}};

// unsigned char colloc, rowloc;

// void delay(int d)
// {
//     unsigned char i;
//     for (; d > 0; d--)
//     {
//         for (i = 250; i > 0; i--)
//             ;
//         for (i = 248; i > 0; i--)
//             ;
//     }
// }

// unsigned char key_detect()
// {
//     keyport = 0xF0; /*set port direction as input-output*/
//     do
//     {
//         keyport = 0xF0;
//         colloc = keyport;
//         colloc &= 0xF0;       /* mask port for column read only */
//     } while (colloc != 0xF0); /* read status of column */

//     do
//     {
//         do
//         {
//             delay(20);                 /* 20ms key debounce time */
//             colloc = (keyport & 0xF0); /* read status of column */
//         } while (colloc == 0xF0);      /* check for any key press */

//         delay(1);
//         colloc = (keyport & 0xF0);
//     } while (colloc == 0xF0);

//     while (1)
//     {
//         /* now check for rows */
//         keyport = 0xFE; /* check for pressed key in 1st row */
//         colloc = (keyport & 0xF0);
//         if (colloc != 0xF0)
//         {
//             rowloc = 0;
//             break;
//         }

//         keyport = 0xFD; /* check for pressed key in 2nd row */
//         colloc = (keyport & 0xF0);
//         if (colloc != 0xF0)
//         {
//             rowloc = 1;
//             break;
//         }

//         keyport = 0xFB; /* check for pressed key in 3rd row */
//         colloc = (keyport & 0xF0);
//         if (colloc != 0xF0)
//         {
//             rowloc = 2;
//             break;
//         }

//         keyport = 0xF7; /* check for pressed key in 4th row */
//         colloc = (keyport & 0xF0);
//         if (colloc != 0xF0)
//         {
//             rowloc = 3;
//             break;
//         }
//     }

//     if (colloc == 0xE0)
//     {
//         return (keypad[rowloc][0]);
//     }
//     else if (colloc == 0xD0)
//     {
//         return (keypad[rowloc][1]);
//     }
//     else if (colloc == 0xB0)
//     {
//         return (keypad[rowloc][2]);
//     }
//     else
//     {
//         return (keypad[rowloc][3]);
//     }
// }

// void cmd(char c)
// {
//     lcd = c;
//     rs = 0;
//     e = 1;
//     delay(5);
//     e = 0;
// }
// void display(char c)
// {
//     lcd = c;
//     rs = 1;
//     e = 1;
//     delay(5);
//     e = 0;
// }
// void custom(void)
// {
//     int k;
//     cmd(0x40);
//     for (k = 0; k < 48; k++)
//         display(custom_char[k]);
//     cmd(0x80);
// }

// void string(char *p)
// {
//     while (*p)
//     {
//         display(*p++);
//     }
// }

// void init(void)
// {
//     cmd(0x38);
//     cmd(0x0c);
//     cmd(0x01);
//     cmd(0x80);
// }
// void main()
// {
//     char x1, x2, op;
//     int res, temp = 0, temp1 = 0;
//     init();
//     custom();
//     string("Enter an expression");
//     cmd(0xc0);
//     while (1 == 1)
//     {
//         x1 = key_detect();
//         if (x1 == '+' || x1 == '/' || x1 == '-' || x1 == 'x')
//             break;
//         else
//         {
//             temp = temp * 10 + (x1 - '0');
//             display(x1);
//             cmd(0x06);
//         }
//     }
//     op = x1;
//     display(op);
//     cmd(0x06);
//     while (1 == 1)
//     {
//         x1 = key_detect();
//         if (x1 == '+' || x1 == '/' || x1 == '-' || x1 == 'x' || x1 == '=')
//             break;
//         else
//         {
//             temp1 = temp1 * 10 + (x1 - '0');
//             display(x1);
//             cmd(0x06);
//         }
//     }
//     display('=');
//     switch (op)
//     {
//     case '+':
//         res = temp + temp1;
//         break;
//     case '-':
//         res = temp - temp1;
//         break;
//     case 'x':
//         res = temp * temp1;
//         break;
//     case '/':
//         res = temp / temp1;
//         break;
//     }
//     if (res < 0)
//     {
//         cmd(0x06);
//         display('-');
//         temp = 0;
//         res = -1 * res;
//         while (res != 0)
//         {
//             temp = temp * 10 + (res % 10);
//             res = res / 10;
//         }
//         res = temp;
//         while (res != 0)
//         {
//             cmd(0x06);
//             display((res % 10) + '0');
//             res = res / 10;
//         }
//     }
//     else
//     {
//         temp = 0;
//         while (res != 0)
//         {
//             temp = temp * 10 + (res % 10);
//             res = res / 10;
//         }
//         res = temp;
//         while (res != 0)
//         {
//             cmd(0x06);
//             display((res % 10) + '0');
//             res = res / 10;
//         }
//     }

//     while (1)
//         ;
// }