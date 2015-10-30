#include "thread.h"

void start();
void end();



void start()
{
	GetOver=1;
	speed=2;
	InitMap();
	mytank.Init();
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//得到窗口句柄
	SetConsoleTitle("小车快闪"); //设置窗口标题
	COORD rec={162,40};	//x,y(宽，高)
	SetConsoleScreenBufferSize(hOut, rec);
	system("color F4"); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),blue);
	COORD pos={0,0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << "欢迎体验小车快闪游戏\n\n首先，您得先放大游戏窗口。。。。。。\n\n想必您是第一次玩这个游戏，那么我先来介绍下规则。\n\n";
	cout << "请点击K键继续。。。。。。";
	while(getch()!='k');
	system("cls");
	COORD pos0={0,0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos0);
	cout<<"键盘“w”、“s”、“a”、“d”分别控制上下左右，在直行道能换车道，不能转弯，在两条直行道交汇的转弯处可以转弯！\n\n按K键继续";
	COORD pos1={20,10};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos1);
	cout<<"--------------------------------------------------------------------------------";
	COORD pos2={20,11};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
	cout<<"|                                                                              |";
	COORD pos3={20,12};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos3);
	cout<<"|                                                                              |";
	COORD pos4={20,13};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos4);
	cout<<"|                                                                              |";
	COORD pos5={20,14};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos5);
	cout<<"|                                                                              |";
	COORD pos6={20,15};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos6);
	cout<<"|                                                                              |";
	COORD pos7={20,16};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos7);
	cout<<"--------------------------------------------------------------------------------";
	COORD pos8={60,9};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos8);
	cout << "↓";
	COORD pos9={40,8};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos9);
	cout<<"直行道（白色路面）有障碍物，可利用“w、a、s、d”方向键换车道避开障碍物！";
	COORD pos10={100,10};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos10);
	cout <<"<- 转弯处（蓝色路面）可利用“w、a、s、d”方向键转弯";
	while(getch()!='k');
	system("cls");
	COORD pos11={0,0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos11);
	cout<<"准备好了吗？！Ready Go！\n\n按y键开始游戏，游戏中按n键结束游戏.";
	while(getch()!='y');
	system("cls");
	thread t1(Check);
	thread t2(Show);
	thread t3(Run);
	t1.join();
	t2.join();
	t3.join();
	end();
}

void end()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),blue);
	COORD pos12={0,0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos12);
	cout << "游戏结束了，点击y键重新开始游戏，点击其他任意键结束游戏。";
	int key=getch();
	if(key=='y'||key=='Y')
		start();
}