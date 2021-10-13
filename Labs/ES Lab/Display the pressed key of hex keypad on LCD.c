#include<reg51.h>
#define lcd P0


sbit C4 = P1^0;     // Connecting keypad to Port 1
sbit C3 = P1^1;
sbit C2 = P1^2;
sbit C1 = P1^3;
sbit R4 = P1^4;
sbit R3 = P1^5;
sbit R2 = P1^6;
sbit R1 = P1^7;


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

void row_finder1() //Function for finding the row for column 1
{
R1=R2=R3=R4=1;
C1=C2=C3=C4=0;

if(R1==0)
display('3');
if(R2==0)
display('2');
if(R3==0)
display('1');
if(R4==0)
display('0');
}

void row_finder2() //Function for finding the row for column 2
{
R1=R2=R3=R4=1;
C1=C2=C3=C4=0;

if(R1==0)
display('7');
if(R2==0)
display('6');
if(R3==0)
display('5');
if(R4==0)
display('4');
}

void row_finder3() //Function for finding the row for column 3
{
R1=R2=R3=R4=1;
C1=C2=C3=C4=0;

if(R1==0)
display('B');
if(R2==0)
display('A');
if(R3==0)
display('9');
if(R4==0)
display('8');
}

void row_finder4() //Function for finding the row for column 4
{
R1=R2=R3=R4=1;
C1=C2=C3=C4=0;

if(R1==0)
display('F');
if(R2==0)
display('E');
if(R3==0)
display('D');
if(R4==0)
display('C');
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


while(1)
    {    
        delay(30);
        C1=C2=C3=C4=1;
          R1=R2=R3=R4=0;
          if(C1==0)
          row_finder1();
          else if(C2==0)
           row_finder2();
           else if(C3==0)
        row_finder3();
        else if(C4==0)
        row_finder4();
delay(100);
    }
}