#pragma once
class BulletList
{
private:
	CBullet* bulletList[200];

public:
	BulletList();
	~BulletList();

public:
	void Initialize();
	void Render();
	void Pulse();
	void Terminate();

	CBullet* OnObject();
};

