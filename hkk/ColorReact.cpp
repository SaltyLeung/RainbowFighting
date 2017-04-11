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
	startTime = clock();              //记录开始时间
	
	srand(time(0));                   //随机数清零
	
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hOut, &bInfo);
	SetConsoleTitle("彩虹战记？......");                            //设置窗口名

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
		word = "背景色";
		if ((*back).index == qColor.index)isCorrect = true;
	}
	else if (charNum == 1) {
		word = "文字的颜色";
		if ((*fore).index == qColor.index)isCorrect = true;
	}
	else {
		word = "文字描述的颜色";
		if ((*des).index == qColor.index)isCorrect = true;
	}
}

Color::Color(int x){
	index = x;
	switch (index){
	case 0:{
		chinese="黑";
		foreGround= FOREGROUND_BLACK;
		backGround= BACKGROUND_BLACK;
		break;
	}
	case 1:{
	chinese = "白";
	foreGround = FOREGROUND_WHITE;
	backGround = BACKGROUND_WHITE;
	break;
	}
	case 2: {
		chinese = "红";
		foreGround = FOREGROUND_RED;
		backGround = BACKGROUND_RED;
		break;
	}
	case 3: {
		chinese = "绿";
		foreGround = FOREGROUND_GREEN;
		backGround = BACKGROUND_GREEN;
		break;
	}
	case 4: {
		chinese = "蓝";
		foreGround = FOREGROUND_BLUE;
		backGround = BACKGROUND_BLUE;
		break;
	}
	case 5: {
		chinese = "黄";
		foreGround = FOREGROUND_YELLOW;
		backGround = BACKGROUND_YELLOW;
		break;
	}
	case 6: {
		chinese = "粉";
		foreGround = FOREGROUND_PINK;
		backGround = BACKGROUND_PINK;
		break;
	}
	case 7: {
		chinese = "紫";
		foreGround = FOREGROUND_PURPLE;
		backGround = BACKGROUND_PURPLE;
		break;
	}
	case 8: {
		chinese = "青";
		foreGround = FOREGROUND_SKY;
		backGround = BACKGROUND_SKY;
		break;
	}
	}
}

void M1Question::PrintQuestion(){
	cout << "请问" + word + "是" + qColor.chinese + "色的吗？     " << "Y：对的！   N：不对！";
}
////////////////////////////////Scene Welcome///////////////////////////////////
void Welcome::Run() {
	cout << "Welcome to Rainbow World！~";
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

