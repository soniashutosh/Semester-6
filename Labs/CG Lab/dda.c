#include<stdio.h>
#include<graphics.h>
#include<math.h>

int roundNo(float num){
    return num < 0 ? num - 0.5 : num + 0.5;
}

void DDA(int x1, int y1, int x2, int y2){

	int dx = x2 - x1;
	int dy = y2 - y1;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);


	float Xinc = dx / (float) steps;
	float Yinc = dy / (float) steps;


	float X = x1;
	float Y = y1;
	for (int i = 0; i <= steps; i++)
	{
		putpixel (X,Y,YELLOW); 
		X += Xinc;		 
		Y += Yinc;		 
		delay(8);		 
							
	}
}


int main()
{
	int gd = DETECT, gm;


	initgraph (&gd, &gm, NULL);

	int x1 = 0, y1 = 0, x2 = 300, y2 = 300;
	DDA(x1, y1, x2, y2);
	return 0;
}

