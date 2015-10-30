#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define black 248
#define white 255
#define blue 249
#define green 250
#define red 252
#define yellow 254

int i=0,j=0,time2=0;


void inline output(const char& key,const int& y,const int& x)
{
	COORD pos={2*x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	switch(key)
	{
		case 'a':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),white);
				 cout << "  ";break;
		case 't':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),176);
				 cout << "  ";break;
		case 'b':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),green);
				 cout << "��";break;
		case 'c':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),yellow);
				 cout << "��";break;
		case 'd':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),black);
				 cout << "��";break;
		case 'e':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),white);
				 cout << "��";break;
		case 'f':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),red);
				 cout << "��";break;
		case 'G':if(time2)
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),blue);
				 else
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),black-8);
				 cout << "��";break;
		case 'm':if(time2)
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),black-8);
				 else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),blue);
				 cout << "��";break;
		case 'h':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),yellow);
				 cout << "��";break;
		case 'i':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),yellow);
				 cout << "��";break;
		case 'j':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),red);
				 cout << "��";break;
		case 'k':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),black);
				 cout << "��";break;
		default:break;
	}
}