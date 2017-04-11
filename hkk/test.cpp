#include<windows.h>
#include<iostream>
#include<conio.h>
using namespace std;
void main1() {
	HANDLE hOut; 
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOut,&bInfo);
	COORD pos = { 0, 0 };
	_getch();
	//cout << "clear!";
	SetConsoleTitle("控制台窗口操作"); 
	SetConsoleScreenBufferSize(hOut, {80,25});
	SMALL_RECT rc = { 0,0,80 - 1,25 - 1 };
	SetConsoleWindowInfo(hOut, true, &rc);
	DWORD a;
	FillConsoleOutputCharacter(hOut, 'b', 5, pos, &a);
	cout << a;
	_getch();
	_getch();
	_getch();
	cin.get();
	CloseHandle(hOut);
}
