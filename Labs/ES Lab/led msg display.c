#include<reg51.h>
#define lcd P0

sbit rs=P2^0;
sbit e=P2^1;

void delay (int);
void cmd (char);
void display (char);
void custom (void);
void string (char *);
void init (void);

void delay (int d)
{
unsigned char i;
for(;d>0;d--)
{
for(i=250;i>0;i--);
for(i=248;i>0;i--);
}
}
void cmd (char c)
{
lcd=c;
rs=0;
e=1;
delay(5);
e=0;
}
void display (char c)
{   e=1;
lcd=c;
rs=1;
delay(5);
e=0;
}

void string (char *p)
{
while(*p)
{
display(*p++);
}
}
void init (void)
{
cmd(0x38);
cmd(0x0c);
cmd(0x01);
cmd(0x80);
}
void main()
{
init();
string("Electronics Hub ");
cmd(0xc0);
string("    Presents    ");
delay(2000);
cmd(0x01);
cmd(0x80);
string("  Custom Chars  ");
cmd(0xc0);
string("  on 16x2 LCD   ");
delay(2000);
cmd(0x01);
cmd(0x80);
string("ABCDEFGHIJKLMNOP");
cmd(0xc0);
string("1234567890");
display('0');
display(1);
display(2);
display(3);
display(4);
display(5);
    while(1);
}