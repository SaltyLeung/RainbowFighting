#ifndef COLOR_REACT_H
#define COLOR_REACT_H
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<array>
#include<string>
#include<ctime>
#include"SaltyEngine.h"
using namespace std;
class Game:public SaltyEngine {
private:
	bool isLose;
	clock_t startTime;
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
public:
	void Start();
};
////////////////////////////////////////////////////////////////Scene Mode 1//////////////////////////////////////////
class Mode1:public Scene {
	clock_t startTime;
	void Run();
};

class Color {
public:
	int index;
	string chinese;
	DWORD foreGround;
	DWORD backGround;
	Color(int);
};

class UI:Scene {
private:
	int score();
public:
	void printUI();
};

class M1Card:public GameObject {
public:
	Color bgColor;
	Color charColor;
	Color description;
	M1Card();
};

class M1Question:public GameObject {
public:
	bool isCorrect;
	int charNum;
	Color qColor;
	string word;
	M1Question(Color *back, Color *fore, Color *des);
	void PrintQuestion();
};

////////////////////////////////////////////////////////////////Scene Mode 1//////////////////////////////////////////
class Welcome:public Scene {
	void Run();
};

//static const array < Color, 9 > colorSeries = { Color(0),Color(1),Color(2),Color(3),Color(4),Color(5),Color(6),Color(7),Color(8) };
#endif
