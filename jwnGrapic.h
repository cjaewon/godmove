// jwnGraph.h :: Made by Cjaewon
// C/C++ Console Graphic Library

#pragma once
#pragma warning(disable:4996)
#pragma warning(disable:E0020)

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
// 기본적인 매크로 함수 정의
#define stop() system("pause"); 
#define cls system("cls"); 

#define printcc( c,l,k) {setcolor(l,k); printf(c);setcolor(7,0);}
#define printccxy(x,y, c,l,k) {gotoxy(x, y);setcolor(l,k); printf(c);setcolor(7,0);}
#define printfxy(x, y, c) {gotoxy(x, y); printf(c);}
#define printcxy(x,y, c,l) {gotoxy(x, y);setcolor(l,0); printf(c);setcolor(7,0);}
//색깔 정의
#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define BLUE2 3 
#define RED 4
#define PINK 5
#define YELLO 6
#define WHITE 7
#define GRAY 8
#define BLUE2 9
#define GREEN2 10
#define BLUE3 11
#define RED2 12
#define PINK2 13
#define YELLO2 14
#define WHITE2 15
//랜덤 매크로
#define randColor rand() % (15)+1
#define random srand(time(NULL));

//gotoxy : 원하는 위치로 커서 이동시키는 함수
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// setcolor : 출력할 문자 색깔을 변경하는 함수
void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

// 원하는 위치에 픽셀 출력 함수
void pixelxy(int x ,int y,int ccolor) {}
	gotoxy(x, y);
	setcolor(ccolor, ccolor);
	cout << "  " << endl;
	setcolor(7, 0);

}
// 픽셀 출력할수
void pixel(int ccolor)
{
	setcolor(ccolor, ccolor);
	cout << "  " << endl;
	setcolor(7, 0);
}
// 콘솔 제목 및 설정
void Console(int x, int y, char name[80]) {
	char h[80];
	char hh[80];

	if (x == 0 && y == 0)
	{
		sprintf(hh, "title %s", name);
		
		goto home;
	}

	sprintf(h, "mode con cols=%d lines=%d", x, y);
	system(h);
	sprintf(hh, "title %s",name);

	home:

	system(hh);
	
}

void pixelb(char i[100], int x) {
	setcolor(x, x);
	cout << i;
}
// Sleep 문 함수
void wait(int x) {
	Sleep(x);
}
// 픽셀 여러개 동사 출력 함수
void pixelbxy(int xx, int yy ,char i[100], int x) {
	gotoxy(xx, yy);
	setcolor(x, x);
	cout << i;
}



