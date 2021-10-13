#include<reg51.h>
#define led P0
sbit sw1=P2^0;
sbit sw2=P2^1;
sbit sw3=P2^2;
sbit sw4=P2^3;
unsigned char ch[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7F,0x39,0x3F,0x79,0x71};
//void delay (int);
void display (unsigned long int);
void sdelay (char);

void delay(int count){
int i,j;
for( i=0;i<=count;i++)
for( j=0;j<=1000;j++){

}

}

void sdelay (char d)
{
for(;d>0;d--);
}

void display (unsigned long int n)
{
led=ch[n/10000];
sw4=1;
sdelay(100);
sw4=0;

led=ch[(n/1000)%10];
sw3=1;
sdelay(100);
sw3=0;

led=ch[(n/100)%10];
sw2=1;
sdelay(100);
sw2=0;

led=ch[(n/10)%10];
sw1=1;
sdelay(100);
// delay(1);
sw1=0;
}

void main()
{
unsigned long int i=10;

while(1)
{
i=++i;
display(i);
// delay(1);
if(i==99999)
i=10;
}
}  
