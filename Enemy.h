#pragma once

class CEnemy : public CObject
{
public:
	bool Initialize(Vector2D pos);
	void Render();
	void Pulse();
	bool Terminate();

};