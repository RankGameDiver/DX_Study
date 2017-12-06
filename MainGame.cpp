#include "stdafx.h"
#include "MainGame.h"


bool CMainGame::Initialize()
{
	IMAGEMANAGER->ImgLoad("witcher Clock", "./Image/witcher Clock.png");
	IMAGEMANAGER->ImgLoad("min", "./Image/min.png");
	IMAGEMANAGER->ImgLoad("hour", "./Image/hour.png");

	return false;
}

void CMainGame::Terminate()
{
}

bool CMainGame::Pulse()
{
	return false;
}

void CMainGame::Render()
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

CMainGame::CMainGame()
{

}

CMainGame::~CMainGame()
{
		
}