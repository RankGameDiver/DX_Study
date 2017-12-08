#include "stdafx.h"
#include "Aquarium.h"


bool CAquarium::Initialize()
{
	IMAGEMANAGER->ImgLoad("backGround", "./Image/background.png");
	IMAGEMANAGER->ImgLoad("clam", "./Image/clam.png", 80, 80);
	IMAGEMANAGER->ImgLoad("fish", "./Image/fish.png", 80, 81);

	fishPos.x = 400;
	fishPos.y = 400;

	return false;
}

void CAquarium::Terminate()
{
}

bool CAquarium::Pulse()
{
	clamFrame++;
	fishFrame++;

	if (clamFrame >= 200)		clamFrame = 0;
	if (fishFrame >= 200)		fishFrame = 0;
	if (fishFrame <= 50)
	{
		fishPos.x -= 4;
	}
	else if (fishFrame <= 150 && fishFrame > 100)
	{
		fishPos.x += 4;
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		g_pSystem->ChangeScene(eSceneType::eSceneType_InGame);
		Sleep(100);
	}
	
	return false;
}

void CAquarium::Render()
{
	IMAGEMANAGER->ImgRender("backGround", Vector2D(0, 0));
	IMAGEMANAGER->ImgRender("clam", Vector2D(400, 700), clamFrame / 5);
	IMAGEMANAGER->ImgRender("fish", Vector2D(fishPos.x, fishPos.y), fishFrame /5);
	IMAGEMANAGER->ImgRender("fish", Vector2D(fishPos.x + 50, fishPos.y - 130), fishFrame / 5);
	IMAGEMANAGER->ImgRender("fish", Vector2D(fishPos.x - 150, fishPos.y - 300), fishFrame / 5);
}

CAquarium::CAquarium()
{

}

CAquarium::~CAquarium()
{

}