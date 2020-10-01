#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int abs(int n){
	return ((n>0)?n:(n*(-1)));
}

void DDA(int x1, int y1, int x2, int y2){
	int dx = x2-x1;
	int dy = y2-y1;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float xinc = dx/(float)steps;
	float yinc = dy/(float)steps;

	float x = x1;
	float y = y1;
	for(int i=0; i<=steps; i++){
		putpixel(x,y,RED);
		x+=xinc;
		y+=yinc;

	}

}

int main(){
	int gd = DETECT, gm;
	clrscr();

	initgraph(&gd, &gm, "");

	DDA(2,2,14,16);
	getch();
	return 0;
}

