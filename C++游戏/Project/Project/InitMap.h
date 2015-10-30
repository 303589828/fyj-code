#include "output.h"

char xu[2]={'b','c'};
char sh[2]={'d','e'};
char oldplace[341][641];

int k=0,l=0,m=0,n=0,h=0,g=0;


void SetBarrier(int y,int x,int color)
{
	for(i=y+1;i<=y+3;++i)
		for(j=x+1;j<=x+3;++j)
			oldplace[i][j]=xu[color];
	for(i=0;i<5;++i)
	{
		oldplace[y][x+i]=sh[(x+y+i)%2];
		oldplace[y+4][x+i]=sh[(x+y+i+1)%2];
		oldplace[y+i][x]=sh[(x+y+i)%2];
		oldplace[y+i][x+4]=sh[(x+y+i+1)%2];
	}
}

void InitMap()
{
	int x=170;
	i=0;j=-1;
	int s=130;
	while(s>70)
	{
		while(x>s)
		{
			while(++j<470+x)
				oldplace[i][j]='a';
			--i;
			while(++i<170+x)
				oldplace[i][j]='a';
			++j;
			while(--j>170-x)
				oldplace[i][j]='a';
			++i;
			while(--i>170-x)
				oldplace[i][j]='a';
			++i;
			--x;
		}
		s-=10;
		while(x>s)
		{
			while(++j<470+x)
				oldplace[i][j]=xu[j/10%2];
			--i;
			while(++i<170+x)
				oldplace[i][j]=xu[i/10%2];
			++j;
			while(--j>170-x)
				oldplace[i][j]=xu[j/10%2];
			++i;
			while(--i>170-x)
				oldplace[i][j]=xu[i/10%2];
			++i;
			--x;
		}
		s-=20;
	}//while

	for(i=50;i<70;++i)
		for(j=50;j<70;++j)
			oldplace[i][j]=oldplace[i+221][j]=oldplace[i][j+521]=oldplace[i+221][j+521]='t';

	for(i=80;i<=260;++i)
		for(j=80;j<=560;++j)
			oldplace[i][j]='a';
	x=130,s=128;
	for(int k=0;k<2;++k)
	{
		for(int l=0;l<2;++l)
		{
			i=170-x;j=169-x;
			while(x>s)
			{
				while(++j<470+x)
					oldplace[i][j]=sh[(i+j)%2];//sh[((j+5)/10+i)%2];
				--i;
				while(++i<170+x)
					oldplace[i][j]=sh[(i+j)%2];//sh[((i+5)/10+j)%2];
				++j;
				while(--j>170-x)
					oldplace[i][j]=sh[(i+j)%2];//sh[((j+5)/10+i)%2];
				++i;
				while(--i>170-x)
					oldplace[i][j]=sh[(i+j)%2];//sh[((i+5)/10+j)%2];
				++i;
				--x;
			}
			x-=6;
			s-=8;
		}
		x-=14;
		s-=14;
	}
	SetBarrier(276,170,0);
	SetBarrier(281,170,1);
	SetBarrier(271,270,0);
	SetBarrier(286,270,1);
	SetBarrier(281,370,0);
	SetBarrier(286,370,1);
	SetBarrier(271,470,0);
	SetBarrier(276,470,1);

	SetBarrier(50,170,0);
	SetBarrier(55,170,1);
	SetBarrier(60,270,0);
	SetBarrier(65,270,1);
	SetBarrier(50,370,0);
	SetBarrier(65,370,1);
	SetBarrier(55,470,0);
	SetBarrier(60,470,1);
}

