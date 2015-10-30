#include <iostream>
#include <string>
#include "InitMap.h"
using namespace std;

bool time1=0;
bool ok=1,ok2=1,ok3=1;
char wheel[2]={'G','m'};



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


class map
{
private:
	char place[341][641];
public:
	map();
	~map(){};
	void Init();
	bool SetTank(const int& y,const int& x,const direction& Direction);
	void Recover(int y,int x);
	char* operator[](int n);

};

map::map()
{
	InitMap();
	for(i=0;i<341;++i)
		for(j=0;j<641;++j)
			place[i][j]=oldplace[i][j];
}

/*bool map::SetTank(const int& y,const int& x,const direction& Direction)
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

		place[y][x]='j';
		place[y+Direction.p+Direction.q][x+Direction.q+Direction.p]='G';
		place[y-Direction.p+Direction.q][x-Direction.q+Direction.p]='m';
		place[y+Direction.p-Direction.q][x+Direction.q-Direction.p]='m';
		place[y-Direction.p-Direction.q][x-Direction.q-Direction.p]='G';
		place[y+Direction.q][x+Direction.p]='k';
		place[y-Direction.q][x-Direction.p]='i';
		place[y+Direction.p][x+Direction.q]='h';
		place[y-Direction.p][x-Direction.q]='h';
		return 1;
}*/

void map::Recover(int y,int x)
{
	place[y][x]=oldplace[y][x];
}

char* map::operator[](int n)
{
	return place[n];
}

void map::Init()
{
	for(i=0;i<341;++i)
		for(j=0;j<641;++j)
			place[i][j]=oldplace[i][j];
}