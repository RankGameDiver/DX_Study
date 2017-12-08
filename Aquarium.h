#pragma once

class CAquarium : public IScene
{
private:
	int clamFrame = 0;
	int fishFrame = 0;
	Vector2D fishPos;

public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();

public:
	CAquarium();
	~CAquarium();
};
