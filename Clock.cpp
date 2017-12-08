#include "stdafx.h"
#include "Clock.h"

bool CClock::Initialize()
{
	IMAGEMANAGER->ImgLoad("witcher Clock", "./Image/witcher Clock.png");
	IMAGEMANAGER->ImgLoad("min", "./Image/min.png");
	IMAGEMANAGER->ImgLoad("hour", "./Image/hour.png");

	return false;
}

void CClock::Terminate()
{
}

bool CClock::Pulse()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		g_pSystem->ChangeScene(eSceneType::eSceneType_Fish);
		Sleep(100);
	}
	return false;
}

void CClock::Render()
{
	static float r = 0;
	SYSTEMTIME st;
	char time[84] = "";

	GetLocalTime(&st);

	IMAGEMANAGER->ImgRender("witcher Clock", Vector2D(0, 0));
	IMAGEMANAGER->ImgRender("min", Vector2D(410, 410), (float)st.wMinute * 6);
	IMAGEMANAGER->ImgRender("hour", Vector2D(410, 410), (float)(st.wHour % 12 * 30));
	r += 10;
}

CClock::CClock()
{

}

CClock::~CClock()
{
		
}