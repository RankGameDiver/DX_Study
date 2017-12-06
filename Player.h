#pragma once
class CPlayer : public CObject,
				public IInputHandler
{
private:
	bool m_bIsPressLeft;
	bool m_bIsPressRight;
	bool m_bIsPressUp;
	bool m_bIsPressDown;

	bool getItem;

	BulletList* bulletList;

	int attackDelay;

public:
	CPlayer();
	~CPlayer();

public:
	bool Initialize(Vector2D pos);
	void Render();
	void Pulse();
	bool Terminate();

public:
	void KeyboardHandler(void);
	void MouseHandler(MOUSESTATE diMouseState);
};

