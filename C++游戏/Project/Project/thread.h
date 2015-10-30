#include "tank.h"
#include <thread>



tank mytank(265,580,Up);

void Check()
{
	while(GetOver)
	{
			mytank.check();
			mtx.unlock();
	}

}

void Show()
{
	while(GetOver)
	{
		mtx.lock();
		mytank.show();
		mtx.unlock();
	}
}

void Run()
{
	while(GetOver)
	{
		mtx.lock();
		for(k=0;k<speed;++k)
			mytank.Run();
		if((mytank.y<=120||mytank.y>=220)&&(mytank.x<=120||mytank.x>=520))
			for(k=0;k<speed/5;++k)
				mytank.Run();
		mtx.unlock();
	}
}