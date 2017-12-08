#pragma once

class CMiniGame : public IScene
{
private:
	int frame;
	int rank;
	int score;
	Vector2D playerPos;
	Vector2D playerScale;
	Vector2D leafPos;
	Vector2D leafScale;
public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();

public:
	CMiniGame();
	~CMiniGame();
};