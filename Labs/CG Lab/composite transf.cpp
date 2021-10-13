#include <graphics.h>
#include <stdio.h>
int main()
{

int gm, gd = DETECT, ax, x1 = 100;
int x2 = 100, x3 = 200, y1 = 100;
int y2 = 200, y3 = 100;



int tx,ty;
printf("enter the transform vector");
scanf("%d %d",&tx,&ty);
int sx,sy;
printf("enter the scaling factor ");
scanf("%d %d",&sx,&sy);

initgraph(&gd, &gm, NULL);
cleardevice();
line(x1, y1, x2, y2);
line(x2, y2, x3, y3);
line(x3, y3, x1, y1);
x1=x1+tx;
x2=x2+tx;
x3=x3+tx;
y1=y1+ty;
y2+=ty;
y3+=ty;
x1=x1*sx;
x2*=sx;
y1*=sy;
y2*=sy;
getch();
line(x1, y1, x2, y2);
line(x2, y2, x3, y3);
line(x3, y3, x1, y1);


getch();
closegraph();
return 0;
}
