#pragma once

class CMainGame : public IScene
{
private:
	CPlayer* player;
	CEnemy*  enemy;

public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();

public:
	CMainGame();
	~CMainGame();
};

