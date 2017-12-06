#include "stdafx.h"
#include "Enemy.h"

bool CEnemy::Initialize(Vector2D pos)
{
	m_vPos = pos;

	SetCollider(Vector2D(64, 82));

	return false;
}

void CEnemy::Render()
{
	IMAGEMANAGER->ImgRender("mario", m_vPos, 0);

	IMAGEMANAGER->RectRender(m_vPos, m_size);
}

void CEnemy::Pulse()
{
}

bool CEnemy::Terminate()
{
	return false;
}
