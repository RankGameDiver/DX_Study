#pragma once

class CObject
{
protected:
	Vector2D m_vPos;
	Vector2D m_size;

	bool active;

protected:
	__inline void SetCollider(Vector2D size) { m_size = size; };

public:
	CObject();
	~CObject();

public:
	virtual bool Initialize(Vector2D pos) = 0;
	virtual void Render() = 0;
	virtual void Pulse() = 0;
	virtual bool Terminate() = 0;

public:
	__inline const Vector2D& GetPos() { return m_vPos; };
	__inline const Vector2D& GetSize() { return m_size; };

	bool IsCollision(CObject* obj)
	{
		RECT thisRect = { m_vPos.x - m_size.x / 2, m_vPos.y - m_size.y / 2 ,m_vPos.x + m_size.x / 2, m_vPos.y + m_size.y / 2 };
		RECT objRect = { obj->GetPos().x - obj->GetSize().x / 2, obj->GetPos().y - obj->GetSize().y / 2,
						obj->GetPos().x + obj->GetSize().x / 2, obj->GetPos().y + obj->GetSize().y / 2 };
		RECT temp;

		if (IntersectRect(&temp, &thisRect, &objRect))
		{
			return true;
		}
		return false;
	}
	bool IsCollision(Vector2D vPos)
	{
		POINT ptPos;
		RECT col = { m_vPos.x - (m_size.x / 2), m_vPos.y - (m_size.y / 2), m_vPos.x + (m_size.x / 2), m_vPos.y + (m_size.y / 2) };
		ptPos.x = (int)vPos.x;
		ptPos.y = (int)vPos.y;

		if (PtInRect(&col, ptPos))
		{
			return true;
		}
		return false;
	}

	__inline const bool GetActive() { return active; };
	__inline void SetActive(bool active) { this->active = active; };
};

