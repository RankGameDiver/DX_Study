#include "stdafx.h"
#include "MainGame.h"


bool CMainGame::Initialize()
{
	IMAGEMANAGER->ImgLoad("clock", "./Image/clock.png");
	//IMAGEMANAGER->ImgLoad("windmill", "./Image/windmill.png");
	IMAGEMANAGER->ImgLoad("hour", "./Image/hour.png");
	IMAGEMANAGER->ImgLoad("minute", "./Image/minute.png");
	IMAGEMANAGER->ImgLoad("pivot", "./Image/pivot.png");

	//SOUNDMANAGER->LoadSound("bgm", L"./bgm.mp3" ,SoundType::BGM);
	//SOUNDMANAGER->SoundPlay("bgm");

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

	IMAGEMANAGER->ImgRender("clock", Vector2D(0, 0));
	//IMAGEMANAGER->ImgRender("windmill", Vector2D(410, 410), r);
	IMAGEMANAGER->ImgRender("minute", Vector2D(410, 410), (float)st.wMinute * 6);
	IMAGEMANAGER->ImgRender("hour", Vector2D(410, 410), (float)(st.wHour % 12 * 30));
	IMAGEMANAGER->ImgRender("pivot",Vector2D(0,0));
	r += 10;
}

CMainGame::CMainGame()
{

}

CMainGame::~CMainGame()
{
		
}