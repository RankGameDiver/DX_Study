#include "stdafx.h"
#include "Clock.h"

bool CMiniGame::Initialize()
{
	IMAGEMANAGER->ImgLoad("player1", "./Image/player1.png");
	IMAGEMANAGER->ImgLoad("player2", "./Image/player2.png");
	IMAGEMANAGER->ImgLoad("player3", "./Image/player3.png");
	IMAGEMANAGER->ImgLoad("player4", "./Image/player4.png");
	IMAGEMANAGER->ImgLoad("leaf", "./Image/leaf.png");

	score = 0;
	rank = 1;
	frame = 0;
	playerPos.x = 300;
	playerPos.y = 300;
	playerScale.x = 128;
	playerScale.y = 128;
	leafPos.x = 400;
	leafPos.y = -128;
	leafScale.x = 128;
	leafScale.y = 128;

	return false;
}

void CMiniGame::Terminate()
{
}

bool CMiniGame::Pulse()
{
	frame++;
	leafPos.y += 6;
	if (frame >= 800)
		frame = 0;

	if (leafPos.x + leafScale.x / 2 <= playerPos.x + playerScale.x && leafPos.x + leafScale.x / 2 >= playerPos.x)
	{
		if (leafPos.y + leafScale.y / 2 <= playerPos.y + playerScale.x && leafPos.y + leafScale.y / 2 >= playerPos.y)
		{
			score += 1;
			leafPos.x = frame;
			leafPos.y = -128;
		}
	}

	if (leafPos.y >= 1000)
	{
		leafPos.x = frame;
		leafPos.y = -128;
	}

	if (score == 5)
		rank = 2;
	else if (score == 15)
		rank = 3;
	else if (score == 30)
		rank = 4;

	if (GetAsyncKeyState(VK_UP) & 0x8000) playerPos.y -= 4;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)playerPos.y += 4;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)playerPos.x -= 4;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)playerPos.x += 4;

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		g_pSystem->ChangeScene(eSceneType::eSceneType_Clock);
		Sleep(100);
	}
	return false;
}

void CMiniGame::Render()
{
	switch (rank)
	{
	case 1:
		IMAGEMANAGER->ImgRender("player1", Vector2D(playerPos.x, playerPos.y));
		break;
	case 2:
		IMAGEMANAGER->ImgRender("player2", Vector2D(playerPos.x, playerPos.y));
		break;
	case 3:
		IMAGEMANAGER->ImgRender("player3", Vector2D(playerPos.x, playerPos.y));
		break;
	case 4:
		IMAGEMANAGER->ImgRender("player4", Vector2D(playerPos.x, playerPos.y));
		break;
	default:
		break;
	}
	IMAGEMANAGER->ImgRender("leaf", Vector2D(leafPos.x, leafPos.y));
}

CMiniGame::CMiniGame()
{

}

CMiniGame::~CMiniGame()
{

}