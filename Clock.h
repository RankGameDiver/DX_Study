#pragma once

class CClock : public IScene
{
public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();

public:
	CClock();
	~CClock();
};

