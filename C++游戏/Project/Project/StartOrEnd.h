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
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//�õ����ھ��
	SetConsoleTitle("С������"); //���ô��ڱ���
	COORD rec={162,40};	//x,y(����)
	SetConsoleScreenBufferSize(hOut, rec);
	system("color F4"); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),blue);
	COORD pos={0,0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << "��ӭ����С��������Ϸ\n\n���ȣ������ȷŴ���Ϸ���ڡ�����������\n\n������ǵ�һ���������Ϸ����ô�����������¹���\n\n";
	cout << "����K������������������";
	while(getch()!='k');
	system("cls");
	COORD pos0={0,0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos0);
	cout<<"���̡�w������s������a������d���ֱ�����������ң���ֱ�е��ܻ�����������ת�䣬������ֱ�е������ת�䴦����ת�䣡\n\n��K������";
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
	cout << "��";
	COORD pos9={40,8};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos9);
	cout<<"ֱ�е�����ɫ·�棩���ϰ�������á�w��a��s��d��������������ܿ��ϰ��";
	COORD pos10={100,10};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos10);
	cout <<"<- ת�䴦����ɫ·�棩�����á�w��a��s��d�������ת��";
	while(getch()!='k');
	system("cls");
	COORD pos11={0,0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos11);
	cout<<"׼�������𣿣�Ready Go��\n\n��y����ʼ��Ϸ����Ϸ�а�n��������Ϸ.";
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
	cout << "��Ϸ�����ˣ����y�����¿�ʼ��Ϸ��������������������Ϸ��";
	int key=getch();
	if(key=='y'||key=='Y')
		start();
}