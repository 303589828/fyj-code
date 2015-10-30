#include <iostream>
#include "output.h"
using namespace std;

class block
{
private:
	int color;
	string pattern;
public:
	block(const int color=white,const string pattern=" ");
	~block(){};
	void operator=(const block& newblock);
	void change(const int color=white,const string pattern=' ');
	friend const ostream& operator<<(const ostream& output,const block& theblock);
};

block::block(const int color=white,const string pattern=" ")
{
	this->color=color;
	this->pattern=pattern;
}

void block::operator=(const block& newblock)
{
	this->color=newblock.color;
	this->pattern=newblock.pattern;
}

void block::change(const int color=white,const string pattern=" ")
{
	this->color=color;
	this->pattern=pattern;
}

const ostream& operator<<(const ostream& coutput,const block& theblock)
{
	output(theblock.pattern,theblock.color);
	return coutput;
}