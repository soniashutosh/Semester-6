#include <stdio.h>
// #include <dos.h>
#include <graphics.h>
void drawCircle(int xc, int yc, int x, int y)
{
	putpixel(xc+x, yc+y, RED);
	putpixel(xc-x, yc+y, RED);
	putpixel(xc+x, yc-y, RED);
	putpixel(xc-x, yc-y, RED);
	putpixel(xc+y, yc+x, RED);
	putpixel(xc-y, yc+x, RED);
	putpixel(xc+y, yc-x, RED);
	putpixel(xc-y, yc-x, RED);
}

void circleBres(int xc, int yc, int r)
{
	int x = 0, y = r;
	int d = 3 - 2 * r; //formula for deciding factor
	drawCircle(xc, yc, x, y);
	while (y >= x)
	{
		x++;
		if (d > 0)        //decrease y only if deciding factor less than 0
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		drawCircle(xc, yc, x, y);
		delay(100);
	}
}


int main()
{
	int xc = 200, yc = 200, r = 50;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	circleBres(xc, yc, r); 
	return 0;
}
