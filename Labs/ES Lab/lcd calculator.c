#include<reg51.h>
#define ldata P0
void lcdcmd(unsigned char);
void lcddata(unsigned char);
void MSDelay(unsigned int);
void disp_num(float num);
int get_num(char ch);
void lcdinit();
int num1=0;
int num2=0;
char scan_key_num1(void);
char scan_key_num2(void);
unsigned char s[30]={"ENTER 1 NO= "};
unsigned char s1[30]={"ENTER 2 NO= "};
unsigned char s2[30]={"OPERATOR = "};
sbit rs = P2^0;
sbit rw = P2^2;
sbit en = P2^1;
sbit r0=P1^3;
sbit r1=P1^2;
sbit r2=P1^1;
sbit r3=P1^0;
sbit c0=P1^4;
sbit c1=P1^5;
sbit c2=P1^6;
sbit c3=P1^7;

void lcdinit(){
 MSDelay(15000);
lcdcmd(0x30);
MSDelay(4500);
lcdcmd(0x30);
MSDelay(300);
lcdcmd(0x30);
MSDelay(600);
    lcdcmd(0x38);
    lcdcmd(0x0F);
    lcdcmd(0x01);
    lcdcmd(0x06);
    lcdcmd(0x80);
}


int main (void)
  {
   while(1){
   unsigned int k=0,m=0,n=0;int k2,k1; char key,key1;unsigned char ch2;
   lcdinit();
   
ch2=scan_key_num1();
scan_key_num2();
// lcdcmd(0x01);
switch(ch2)
{
case '+':
disp_num(num1+num2);
break;
case '-':
disp_num(num1-num2);
break;
case '*':
disp_num(num1*num2);
break;
case '/':
disp_num(num1/num2);
break;
}
return 0;
}
}
void lcdcmd(unsigned char value)
  {
    ldata = value;      
    rs = 0;
    rw = 0;
    en = 1;            
    MSDelay(50);
    en = 0;
MSDelay(50);
   
  }
void lcddata(unsigned char value)
  {
    ldata = value;  
    rs = 1;
    rw = 0;
    en = 1;          
    MSDelay(50);
    en = 0;
    MSDelay(50);
  }
void MSDelay(unsigned int itime)
  {
    unsigned int i, j;
    for(i=0;i< itime;i++)          
      for(j=0;j<5;j++);      
  }
char scan_key_num1()
{


unsigned char c;
c='s';
while(!( c=='+' || c=='-' || c=='#' || c=='$' || c=='*' || c=='/' ))
{
r0=0;r1=1;r2=1;r3=1;
if(c0==0 && r0==0 ){lcddata('0');MSDelay(100000);num1=num1*10+0;}
    if(c1==0 && r0==0){ lcddata('1');MSDelay(100000);num1=num1*10+1;}
if(c2==0 && r0==0){ lcddata('2');MSDelay(100000);num1=num1*10+2;}
if(c3==0 && r0==0){ lcddata('3');MSDelay(100000);num1=num1*10+3;}
 
r0=1;r1=0;r2=1;r3=1;

if(c0==0 && r1==0){ lcddata('4');MSDelay(100000);num1=num1*10+4;}
    if(c1==0 && r1==0){ lcddata('5');MSDelay(100000);num1=num1*10+5;}
if(c2==0 && r1==0){ lcddata('6');MSDelay(100000);num1=num1*10+6;}
if(c3==0 && r1==0){ lcddata('7');MSDelay(100000);num1=num1*10+7;;}

r0=1;r1=1;r2=0;r3=1;

if(c0==0 && r2==0){ lcddata('8');MSDelay(100000);num1=num1*10+8;}
    if(c1==0 && r2==0){ lcddata('9');MSDelay(100000);num1=num1*10+9;}
if(c2==0 && r2==0){ lcddata('+');MSDelay(100000);return c= '+';}
if(c3==0 && r2==0){ lcddata('-');MSDelay(100000);return c= '-';}

r0=1;r1=1;r2=1;r3=0;

if(c0==0 && r3==0){ lcddata('*');MSDelay(100000);return  c= '*';}
    if(c1==0 && r3==0){ lcddata('/');MSDelay(100000);return c= '/';}
if(c2==0 && r3==0){ lcddata('^');MSDelay(100000);return c= '^';}
if(c3==0 && r3==0){ lcddata('=');MSDelay(100000);return c= '=';}
}
return 0;
}
char scan_key_num2()
{


unsigned char c;
c='s';
while(!( c=='+' || c=='-' || c=='#' || c=='$' || c=='*' || c=='/' ))
{
r0=0;r1=1;r2=1;r3=1;
if(c0==0 && r0==0 ){lcddata('0');MSDelay(100000);num2=num2*10+0;}
    if(c1==0 && r0==0){ lcddata('1');MSDelay(100000);num2=num2*10+1;}
if(c2==0 && r0==0){ lcddata('2');MSDelay(100000);num2=num2*10+2;}
if(c3==0 && r0==0){ lcddata('3');MSDelay(100000);num2=num2*10+3;}
 
r0=1;r1=0;r2=1;r3=1;

if(c0==0 && r1==0){ lcddata('4');MSDelay(100000);num2=num2*10+4;}
    if(c1==0 && r1==0){ lcddata('5');MSDelay(100000);num2=num2*10+5;}
if(c2==0 && r1==0){ lcddata('6');MSDelay(100000);num2=num2*10+6;}
if(c3==0 && r1==0){ lcddata('7');MSDelay(100000);num2=num2*10+7;;}

r0=1;r1=1;r2=0;r3=1;

if(c0==0 && r2==0){ lcddata('8');MSDelay(100000);num2=num2*10+8;}
    if(c1==0 && r2==0){ lcddata('9');MSDelay(100000);num2=num2*10+9;}
if(c2==0 && r2==0){ lcddata('+');MSDelay(100000);return c= '+';}
if(c3==0 && r2==0){ lcddata('-');MSDelay(100000);return c= '-';}

r0=1;r1=1;r2=1;r3=0;

if(c0==0 && r3==0){ lcddata('*');MSDelay(100000);return  c= '*';}
    if(c1==0 && r3==0){ lcddata('/');MSDelay(100000);return c= '/';}
if(c2==0 && r3==0){ lcddata('^');MSDelay(100000);return c= '^';}
if(c3==0 && r3==0){ lcddata('=');MSDelay(100000);return c= '=';}
}
return 0;
}

int get_num(char ch)         //convert char into int
{
switch(ch)
{
case '0': return 0; break;
case '1': return 1; break;
case '2': return 2; break;
case '3': return 3; break;
case '4': return 4; break;
case '5': return 5; break;
case '6': return 6; break;
case '7': return 7; break;
case '8': return 8; break;
case '9': return 9; break;
}
return 0;
}

void disp_num(float num)            //displays number on LCD
{


unsigned char UnitDigit  = 0;  //It will contain unit digit of numb
unsigned char TenthDigit = 0;  //It will contain 10th position digit of numb
unsigned char decimal = 0;
int j;
int numb;
j=(int)(num*10);
numb=(int)num;
if(numb<0)
{
numb = -1*numb;  // Make number positive
lcddata('-'); // Display a negative sign on LCD
}

TenthDigit = (numb/10000);         // Findout Tenth Digit

        // If it is zero, then don't display
lcddata(TenthDigit+0x30); // Make Char of TenthDigit and then display it on LCD

TenthDigit = ((numb/1000 )%10);         // Findout Tenth Digit

        // If it is zero, then don't display
lcddata(TenthDigit+0x30); // Make Char of TenthDigit and then display it on LCD
TenthDigit = ((numb/100 )%10);         // Findout Tenth Digit

        // If it is zero, then don't display
lcddata(TenthDigit+0x30); // Make Char of TenthDigit and then display it on LCD

TenthDigit = ((numb/10 )%10);         // Findout Tenth Digit

        // If it is zero, then don't display
lcddata(TenthDigit+0x30); // Make Char of TenthDigit and then display it on LCD

TenthDigit = ((numb/1 )%10);         // Findout Tenth Digit

        // If it is zero, then don't display
lcddata(TenthDigit+0x30); // Make Char of TenthDigit and then display it on LCD




/*lcddata('.');
decimal=(j%10)+0x30;
lcddata(decimal); */
MSDelay(2000000);



}