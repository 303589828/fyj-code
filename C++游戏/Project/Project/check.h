#include "tank.h"
#include <conio.h>


bool check(tank& MyTank)
{
	char key=getch();
	switch(key)
	{
		case 'w':MyTank.TurnDirection(Up);return 1;
		case 's':MyTank.TurnDirection(Down);return 1;
		case 'a':MyTank.TurnDirection(Left);return 1;
		case 'd':MyTank.TurnDirection(Right);return 1;
		case 'q':return 0;
		default:break;
	}
}