#include "InitMap.h"
#include <mutex>


bool turn=0;
mutex mtx;
bool GetOver=1;
int speed=2;

struct direction
{
	int q;
	int p;
};
bool operator==(direction one,direction two)
{
	return (one.p==two.p&&one.q==two.q);
}

direction Up={-1,0};
direction Down={1,0};
direction Left={0,-1};
direction Right={0,1};

class tank
{
private:
	char thetank[3][3];
	char Screen[40][80]; 
public:
	int x;
	int y;
	direction Direction;
	tank(int y,int x,direction Direction);
	~tank(){};
	bool TurnDirection(direction Direction);
	bool Run();
	bool Stop();
	void check(char key);
	void show();
	bool Response();
	void Init();
};

tank::tank(int y,int x,direction Direction)
{
	this->y=y;
	this->x=x;
	this->Direction=Direction;
	for(i=0;i<40;++i)
		for(j=0;j<80;++j)
			Screen[i][j]=oldplace[y-20+i][x-40+j];

	thetank[1][1]='j';
	thetank[1+Direction.p+Direction.q][1+Direction.q+Direction.p]='G';
	thetank[1-Direction.p+Direction.q][1-Direction.q+Direction.p]='m';
	thetank[1+Direction.p-Direction.q][1+Direction.q-Direction.p]='m';
	thetank[1-Direction.p-Direction.q][1-Direction.q-Direction.p]='G';
	thetank[1+Direction.q][1+Direction.p]='k';
	thetank[1-Direction.q][1-Direction.p]='i';
	thetank[1+Direction.p][1+Direction.q]='h';
	thetank[1-Direction.p][1-Direction.q]='h';
}

bool tank::TurnDirection(direction Direction)
{
	if(oldplace[y][x]=='t'&&turn)
	{
		this->Direction=Direction;
		thetank[1][1]='j';
		thetank[1+Direction.p+Direction.q][1+Direction.q+Direction.p]='G';
		thetank[1-Direction.p+Direction.q][1-Direction.q+Direction.p]='m';
		thetank[1+Direction.p-Direction.q][1+Direction.q-Direction.p]='m';
		thetank[1-Direction.p-Direction.q][1-Direction.q-Direction.p]='G';
		thetank[1+Direction.q][1+Direction.p]='k';
		thetank[1-Direction.q][1-Direction.p]='i';
		thetank[1+Direction.p][1+Direction.q]='h';
		thetank[1-Direction.p][1-Direction.q]='h';
		turn=0;
		return 1;
	}
	else
	{
		y+=Direction.q;
		x+=Direction.p;
		if(Response())
		{
			y+=Direction.q;
			x+=Direction.p;
			return 1;
		}
		else    //1
		{
			y-=Direction.q;
			x-=Direction.p;
			return 0;
		}
	}
}

bool tank::Run()
{
	if(!turn&&oldplace[y][x]=='a')
		turn=1;
	if(y==200&&(x>570&&x<590))
		++speed;
	y+=Direction.q;
	x+=Direction.p;
	if(!Response())
	{
		y-=Direction.q;
		x-=Direction.p;
		GetOver=0;
		return 0;
	}
	else
		return 1;
}

bool tank::Response()
{
	if(x<=50||x>=590||y<=50||y>=290)
		return 0;
	else if(x>=69&&x<=571&&y>=69&&y<=271)
		return 0;
	else
		for(i=-1;i<=1;i+=2)
			for(j=-1;j<=1;j+=2)
				if(oldplace[y+i][x+j]!='a'&&oldplace[y+i][x+j]!='t')
					return 0;
	return 1;
}

void tank::check(char key)
{
	switch(key)
	{
		case 'W':
		case 'w':if(this->Direction==Left||this->Direction==Right)
					TurnDirection(Up);
				 break;
		case 'S':
		case 's':if(this->Direction==Left||this->Direction==Right)
					TurnDirection(Down);
				 break;
		case 'A':
		case 'a':if(this->Direction==Up||this->Direction==Down)
					TurnDirection(Left);
				 break;
		case 'D':
		case 'd':if(this->Direction==Up||this->Direction==Down)
					TurnDirection(Right);
				 break;
		case 'N':
		case 'n':GetOver=0;break;
		default :break;
	}
}

void tank::show()
{
	time2=!time2;
	for(i=0;i<40;++i)
		for(j=0;j<80;++j)
			if(oldplace[y-20+i][x-40+j]!=Screen[i][j])
				output(Screen[i][j]=oldplace[y-20+i][x-40+j],i,j);
	for(i=0;i<3;++i)
		for(j=0;j<3;++j)
			output(thetank[i][j],i+19,j+39);
}

void tank::Init()
{
	this->y=265;
	this->x=580;
	this->Direction=Up;
	for(i=0;i<40;++i)
		for(j=0;j<80;++j)
			Screen[i][j]=oldplace[245+i][540+j];
	thetank[1][1]='j';
	thetank[1+Direction.p+Direction.q][1+Direction.q+Direction.p]='G';
	thetank[1-Direction.p+Direction.q][1-Direction.q+Direction.p]='m';
	thetank[1+Direction.p-Direction.q][1+Direction.q-Direction.p]='m';
	thetank[1-Direction.p-Direction.q][1-Direction.q-Direction.p]='G';
	thetank[1+Direction.q][1+Direction.p]='k';
	thetank[1-Direction.q][1-Direction.p]='i';
	thetank[1+Direction.p][1+Direction.q]='h';
	thetank[1-Direction.p][1-Direction.q]='h';
}
