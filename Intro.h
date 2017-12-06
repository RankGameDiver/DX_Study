#pragma once
class CIntro : public IScene,
			   public IInputHandler
{
public:
	bool Initialize();
	void Terminate();
	bool Pulse();
	void Render();

public:
	CIntro();
	~CIntro();

public:
	void KeyboardHandler(void);
	void MouseHandler(MOUSESTATE diMouseState);
};

