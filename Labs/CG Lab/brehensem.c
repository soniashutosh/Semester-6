#include<stdio.h>
#include<graphics.h>
#include<math.h>

int roundNo(float num){
    return num < 0 ? num - 0.5 : num + 0.5;
}

void brehensham(int x1, int y1, int x2, int y2)
{

	int dx = x2 - x1;
	int dy = y2 - y1;


	int d=(2*dy)-dx;
	int x=x1,y=y1;
	
	double slop = (1.0*dy)/dx;
	
	if(slop < 1){
		while(x<x2){
			if(d>=0){
				putpixel(x,y,YELLOW);
				y++;
				x++;
				d+=2*(dy-dx);	
				delay(50);
			}else{
				putpixel(x,y,YELLOW);
				x++;
				d+=2*(dy);
				delay(50);
			}
		}
	}else{
		while(x<x2){
			if(d>=0){
				putpixel(x,y,YELLOW);
				y++;
				x++;
				d+=2*(dx-dy);	
				delay(50);
			}else{
				putpixel(x,y,YELLOW);
				x++;
				d+=2*(dx);
				delay(50);
			}
		}
	}
}


int main()
{
	int gd = DETECT, gm;


	initgraph (&gd, &gm,NULL);

	int x1 = 0, y1 = 0, x2 = 300, y2 = 300;
	if(x1 > x2){
		int x = x1;
		x1 = x2;
		x2 = x;
		
		int y = y1;
		y1 = y2;
		y2 = y;
	}
	
	brehensham(x1, y1, x2, y2);
	return 0;
}

