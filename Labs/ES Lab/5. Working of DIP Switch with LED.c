#include <reg51.h>

sbit Led0 = P2 ^ 0;    //pin connected to toggle Led
sbit Switch0 = P1 ^ 0; //Pin connected to toggle led
sbit Led1 = P2 ^ 1;    //pin connected to toggle Led
sbit Switch1 = P1 ^ 1; //Pin connected to toggle led
sbit Led2 = P2 ^ 2;    //pin connected to toggle Led
sbit Switch2 = P1 ^ 2; //Pin connected to toggle led
sbit Led3 = P2 ^ 3;    //pin connected to toggle Led
sbit Switch3 = P1 ^ 3; //Pin connected to toggle led
sbit Led4 = P2 ^ 4;    //pin connected to toggle Led
sbit Switch4 = P1 ^ 4; //Pin connected to toggle led

int main()
{
    Led0 = 0;    //configuring as output pin
    Switch0 = 0; //Configuring as input pin
    Led1 = 0;    //configuring as output pin
    Switch1 = 0; //Configuring as input pin
    Led2 = 0;    //configuring as output pin
    Switch2 = 0; //Configuring as input pin
    Led3 = 0;    //configuring as output pin
    Switch3 = 0; //Configuring as input pin
    Led4 = 0;    //configuring as output pin
    Switch4 = 0; //Configuring as input pin
    while (1)    //Continuous monitor the status of the switch.
    {
        if (Switch0 == 1)
        {
            Led0 = 1; //Led On
        }
        else
        {
            Led0 = 0; //Led Off
        }
        if (Switch1 == 1)
        {
            Led1 = 1; //Led On
        }
        else
        {
            Led1 = 0; //Led Off
        }
        if (Switch2 == 1)
        {
            Led2 = 1; //Led On
        }
        else
        {
            Led2 = 0; //Led Off
        }
        if (Switch3 == 1)
        {
            Led3 = 1; //Led On
        }
        else
        {
            Led3 = 0; //Led Off
        }
        if (Switch4 == 1)
        {
            Led4 = 1; //Led On
        }
        else
        {
            Led4 = 0; //Led Off
        }
    }
    return 0;
}