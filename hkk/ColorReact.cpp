#include"ColorReact.h"
#include"SaltyEngine.h"
#include<ctime>
#include<cstdlib>
#define runningTime (clock()-startTime)/CLOCKS_PER_SEC
#define BACKGROUND_YELLOW BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY
#define BACKGROUND_PURPLE BACKGROUND_RED | BACKGROUND_BLUE
#define BACKGROUND_PINK BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY
#define BACKGROUND_WHITE BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY
#define BACKGROUND_SKY BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY
#define BACKGROUND_BLACK NULL
#define FOREGROUND_YELLOW FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define FOREGROUND_BLACK NULL
#define FOREGROUND_PURPLE FOREGROUND_RED | FOREGROUND_BLUE
#define FOREGROUND_PINK FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define FOREGROUND_SKY FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define FOREGROUND_WHITE FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
vector<Scene*>scenePtr;
void Game::Start() {
	startTime = clock();              //��¼��ʼʱ��
	
	srand(time(0));                   //���������
	
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hOut, &bInfo);
	SetConsoleTitle("�ʺ�ս�ǣ�......");                            //���ô�����

	COORD size = { 80, 25 };
	SetConsoleScreenBufferSize(hOut, size);
	SMALL_RECT rc = { 0,0, 80 - 1, 25 - 1 };
	SetConsoleWindowInfo(hOut, true, &rc);

    static Mode1 mode1;
	static Welcome welcome;
	//sceneQueue.push_back(welcome);
	//sceneQueue.push_back(mode1);
	scenePtr.push_back(&welcome);
	scenePtr.push_back(&mode1);
	welcome.enabled = true;
	mode1.enabled =false;
    while (gameRun == true) {
		update();
		_sleep(40);
	}
	CloseHandle(hOut);
}


void Mode1::Run() {
		M1Card m1Card;
		M1Question m1Question(&m1Card.bgColor,&m1Card.charColor,&m1Card.description);
		WORD att0 = m1Card.bgColor.backGround | m1Card.charColor.foreGround;
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, m1Card.bgColor.backGround);
		for(short i=5;i<=15;++i)
			for (short j = 5;j <= 15;++j)
			{
				COORD pos = { i,j };
				SetConsoleCursorPosition(hOut, pos);
				WriteConsole(hOut, "A", 2, NULL, NULL);
			};
		COORD pos = { 0,20 };
		SetConsoleCursorPosition(hOut, pos);
		m1Question.PrintQuestion();
        CloseHandle(hOut);
}

M1Card::M1Card(): bgColor(rand() % 9 ), charColor(rand() % 9),description(rand()&9){
	
}

M1Question::M1Question(Color* back,Color* fore,Color* des):qColor(rand() % 9) {
	isCorrect = false;
	charNum = rand() % 3;
	if (charNum == 0) {
		word = "����ɫ";
		if ((*back).index == qColor.index)isCorrect = true;
	}
	else if (charNum == 1) {
		word = "���ֵ���ɫ";
		if ((*fore).index == qColor.index)isCorrect = true;
	}
	else {
		word = "������������ɫ";
		if ((*des).index == qColor.index)isCorrect = true;
	}
}

Color::Color(int x){
	index = x;
	switch (index){
	case 0:{
		chinese="��";
		foreGround= FOREGROUND_BLACK;
		backGround= BACKGROUND_BLACK;
		break;
	}
	case 1:{
	chinese = "��";
	foreGround = FOREGROUND_WHITE;
	backGround = BACKGROUND_WHITE;
	break;
	}
	case 2: {
		chinese = "��";
		foreGround = FOREGROUND_RED;
		backGround = BACKGROUND_RED;
		break;
	}
	case 3: {
		chinese = "��";
		foreGround = FOREGROUND_GREEN;
		backGround = BACKGROUND_GREEN;
		break;
	}
	case 4: {
		chinese = "��";
		foreGround = FOREGROUND_BLUE;
		backGround = BACKGROUND_BLUE;
		break;
	}
	case 5: {
		chinese = "��";
		foreGround = FOREGROUND_YELLOW;
		backGround = BACKGROUND_YELLOW;
		break;
	}
	case 6: {
		chinese = "��";
		foreGround = FOREGROUND_PINK;
		backGround = BACKGROUND_PINK;
		break;
	}
	case 7: {
		chinese = "��";
		foreGround = FOREGROUND_PURPLE;
		backGround = BACKGROUND_PURPLE;
		break;
	}
	case 8: {
		chinese = "��";
		foreGround = FOREGROUND_SKY;
		backGround = BACKGROUND_SKY;
		break;
	}
	}
}

void M1Question::PrintQuestion(){
	cout << "����" + word + "��" + qColor.chinese + "ɫ����     " << "Y���Եģ�   N�����ԣ�";
}
////////////////////////////////Scene Welcome///////////////////////////////////
void Welcome::Run() {
	cout << "Welcome to Rainbow World��~";
	char mode = _getch();
	switch (mode) {
	case '1': {
		enabled = false;
		(*scenePtr[1]).enabled = true;
		break;
	}
	case '2': {
		break;
	}
	case '3': {
		break;
	}
	default: {
		cout << "error mode.";
	}
	}
}

