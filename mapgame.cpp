#include "stdafx.h"
#include "jwnGrapic.h"
#define max 40

//함수지정
void maker();
void cursor_view(char s);
void start();
void maker();
void map();
void Levelscore();
void player();
void playerout();
void out();
void out2();
void boom();
void menu();
//함수지정
//변수지정
int p = 0;
int t=0;
int score = 0;
int level = 0;
// player x, y current
int px=50;
int py=7;
// player x, y before
int pxb = 0;
int pyb = 0;
int times = 0;
int ri = 35;
int lol =0;
int lolking = 0;
int play = 80;
int ture1 = 0;
int ture2 = 0;
int mapout[max];
int mapout2[max];
int iii = 0;
int in = 0;

int main()
{
	random;
	home:
	
	iii = 0;
	in = 0;
	score = 0;
	level = 0;
	px = 50;
	py = 7;
	pxb = 0;
	pyb = 0;
	times = 0;
	ri = 35;
	lol = 0;
	lolking = 0;
	play = 80;
	ture1 = 0;
	ture2 = 0;
	
	
	Console(0, 0, "제작 cj(c언어 게임)");
	menu();

	start();
	cls; //화면 지우기
	map();
	Levelscore();
	out();

	if (p==1) {
		while(1) {
			player();
			if (lolking == 1) {
				cls;

				setcolor(RED2, BLACK);

				cout << "\n\n\n\n\n\n\t\t\t\t" << endl;
				cout << "\t\t\t     ┌───────┐" << endl;
				cout << "\t\t\t     │  game  over  │" << endl;
				cout << "\t\t\t		└───────┘  " << endl;

				Sleep(1000);

				cls;
				goto home;
			}
		}
	} else if (p == 3) maker();

	stop();
	return 0;


}
//시작 화면
void start()
{
	
}
void map()
{
	
	
	setcolor(WHITE2, WHITE2);
	printccxy(46,1, "                                ", WHITE2, WHITE2);
	printccxy(46,2, "                                ", WHITE2, WHITE2);
	printccxy(46,3, "                                ", WHITE2, WHITE2);
	printccxy(46,4, "                                ", WHITE2, WHITE2);
	printccxy(46,5, "                                ", WHITE2, WHITE2);
	printccxy(46,6, "                                ", WHITE2, WHITE2);
	printccxy(46,7, "                                ", WHITE2, WHITE2);
	printccxy(46,8, "                                ", WHITE2, WHITE2);
	printccxy(46,9, "                                ", WHITE2, WHITE2);
	printccxy(46,10, "                                ", WHITE2, WHITE2);
	printccxy(46,11, "                                ", WHITE2, WHITE2);
	printccxy(46,12, "                                ", WHITE2, WHITE2);
	printccxy(46,13, "                                ", WHITE2, WHITE2);
}
void Levelscore()
{
	// ─ │ ┌ 
	printcxy(2,1,"  ┌──────────┐ ",BLUE3);
	printcxy(2,2,"  │       level        │ ", BLUE3);
	printcxy(2,3,"  │                    │ ", BLUE3);
	printcxy(2,4,"  └──────────┘  ", BLUE3);

	printcxy(2, 6, "  ┌──────────┐ ", GREEN2);
	printcxy(2, 7, "  │       score        │ ", GREEN2);
	printcxy(2, 8,"  │                    │ ", GREEN2);
	printcxy(2, 9,"  └──────────┘ ",GREEN2);
	printfxy(42, 14,"┌─────────────────┐ " );
	printfxy(42, 15,"│↑(Up)↓(Down)→(Left)←(Right)   │  ");
	printfxy(42, 16,"└─────────────────┘");
	
	pixelxy(2, 12, GRAY);
	printfxy(5, 12, ":player/플레이어");
	pixelxy(2, 13, PINK2);
	printfxy(5, 13, "dangerous /위험");
	pixelxy(2, 14 ,RED2);
	printfxy(5, 14, "die/죽음");
}
void player()
{


	playerout();
	pxb = px;
	pyb = py;
	pixelxy(px, py, GRAY);
	if (GetAsyncKeyState(VK_UP) && ture2 == 0) { py -= 1; out2();}
	else if (GetAsyncKeyState(VK_DOWN) && ture2 == 0) { py += 1; out2(); }
	else if (GetAsyncKeyState(VK_LEFT) && ture2 == 0) { px -= 1; out2(); }
	else if (GetAsyncKeyState(VK_RIGHT) && ture2 == 0) { px += 1; out2(); }
	if (lol == 0) {
		Sleep(5.099);
		times ++;
		if (times == play) {
			for (int i = 0; i < max; i++) {
				gotoxy(mapout[i], mapout2[i]);
				pixel(RED2);
			}

			ture2 = 1;
			for (int i = 0; i < max; i++) {
				if (mapout[i] == px  && mapout2[i] == py) {
					lolking = 1;
				}		
			}

			if(play > 20)play -= 5;
			if (level > 15)play = 14;
			
			level += 1;
			gotoxy(15, 3);
			setcolor(BLUE3, BLACK);
			cout << level;
			gotoxy(14, 8);
			score += rand() % ((100 - 22) + 1) + 22;
			setcolor(GREEN2, BLACK);
			cout << score;
			ture2 = 0;
			Sleep(1000);
			map();
			out();
			out2();
			times = 0;
		}
		Sleep(38);
		gotoxy(5, 17);
		cout << "x:" << px;
		gotoxy(5, 18);
		cout << "y:" << py;
		pixelxy(pxb, pyb, WHITE2);
	}
}

// 플레이어가 맵 밖에 나가는 것을 방지
void playerout() {
	if (px==45) px += 1;
	else if (py==0) py += 1;
	else if (px == 77) px -= 1;
	else if (py == 14) py -= 1;
}

void out()
{
	for (int i = 0; i < max; i++) {
		mapout[i] = rand() % ((74 - 46) + 1) + 46;
		mapout2[i] = rand() % 13 + 1;
	}
}
void out2() {
	for (int i = 0; i < max; i++) {
		gotoxy(mapout[i], mapout2[i]);
		pixel(PINK2);
	}
}
void menu() {
	cursor_view(1);
	
	cout << "\n\n\n\n\n\n\n\n\n\n\n " << endl;
	setcolor(YELLO2, BLACK);		
	cout << "\t\t\t\t  God Move " << endl;
	setcolor(WHITE2, BLACK);
	cout << "\t\t\t\t 제작 cj " << endl;
	cout << "\t\t\t        Console GAME    " << endl;
	setcolor(YELLO2, BLACK);
	cout << "     ┌─────────────────────────────────┐" << endl;
	setcolor(8, BLACK);
	cout << "     │  _______  _______  ______     __   __  _______  __   __  _______ │" << endl;
	setcolor(9, BLACK);
	cout << "     │ |       ||       ||      |   |  |_|  ||       ||  | |  ||       |│" << endl;
	setcolor(10, BLACK);
	cout << "     │ |    ___||   _   ||  _    |  |       ||   _   ||  |_|  ||    ___|│" << endl;
	setcolor(11, BLACK);
	cout << "     │ |   | __ |  | |  || | |   |  |       ||  | |  ||       ||   |___ │" << endl;
	setcolor(12, BLACK);
	cout << "     │ |   ||  ||  |_|  || |_|   |  |       ||  |_|  ||       ||    ___|│" << endl;
	setcolor(13, BLACK);
	cout << "     │ |   |_| ||       ||       |  | ||_|| ||       | |     | |   |___ │" << endl;
	setcolor(14, BLACK);
	cout << "     │ |_______||_______||______|   |_|   |_||_______|  |___|  |_______|│" << endl;
	setcolor(15, BLACK);
	cout << "     └─────────────────────────────────┘" << endl;
	gotoxy(31, 3);
	printf("┌──────┐\n");
	gotoxy(31, 4);
	printf("│   key = ↓ │\n");
	gotoxy(31, 5);
	printf("┌──────┐\n");
	gotoxy(31, 6);
	printf("│    play    │\n");
	gotoxy(31, 7);
	printf("│            │\n");
	gotoxy(31, 8);
	printf("│    maker   │\n");
	gotoxy(31, 9);
	printf("│            │\n");
	gotoxy(31, 10);
	printf("│    exit    │\n");
	gotoxy(31, 11);
	printf("└──────┘ \n");	
	while (true) {
		if (GetAsyncKeyState(VK_DOWN)) {
			iii++;
			if (iii == 1) {
				gotoxy(34, 10);
				printf("  ");
				gotoxy(34, 6);
				setcolor(BLUE3, BLACK);
				printf("▶");
			} else if (iii == 2) {
				gotoxy(34, 6);
				printf("  ");
				gotoxy(34, 8);
				setcolor(BLUE3, BLACK);
				printf("▶");
			} else if (iii == 3) {
				gotoxy(34, 8);
				printf("  ");
				gotoxy(34, 10);
				setcolor(BLUE3, BLACK);
				printf("▶");
				iii = 0;
			}
		}
			else if (GetAsyncKeyState(VK_RETURN))
			{
				if (iii = 1)
				{
					iii = 4;
					goto home;
				}
				if (iii = 2)
				{
					goto home;
					
				}
				if (iii = 3)
				{
					goto home;

				}
			}
			wait(200);
	
		}
	
home:
	
if(iii=1)	p = 1; 
else if (iii = 3)	p = 3; }

void cursor_view(char s)      // 0넣으면숨기기, 1넣으면보이기
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = s;
	ConsoleCursor.dwSize = 2;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
void maker()  
{
	cout << "\t\t\t      제작:cj" << endl;
	cout << "\t\t\t      게임명:GodMove" << endl;
	cout << "\t\t\t      제작 언어:c언어&c++" << endl;
	cout << "\t\t\t      총 코드 :446줄" << endl;
}
