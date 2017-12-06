#pragma once
class CBullet : public CObject
{
private:
	int i_frame;
	int i_deltaTime;

	float bulletR;

public:
	CBullet();
	~CBullet();

public:
	bool Initialize(Vector2D pos);
	void Render();
	void Pulse();
	bool Terminate();
};

