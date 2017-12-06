#include "stdafx.h"
#include "Bullet.h"

#define DELTATIME 30

CBullet::CBullet()
{
}


CBullet::~CBullet()
{
}

bool CBullet::Initialize(Vector2D pos)
{
	i_frame = 0;
	i_deltaTime = DELTATIME;

	m_vPos = pos;

	SetCollider(Vector2D(50,50));

	bulletR = 0;

	return false;
}

void CBullet::Render()
{
	if (active)
	{
		IMAGEMANAGER->ImgRender("bullet", m_vPos, i_frame, bulletR);
		bulletR += 2.5;

		if (m_vPos.x >= 1700) SetActive(false);
	}
}

void CBullet::Pulse()
{
	if (active)
	{
		m_vPos.x += 6;

		if (i_deltaTime > 0) i_deltaTime--;
		else if (i_deltaTime <= 0)
		{
			i_frame == 0 ? i_frame = 1 : i_frame = 0;
			i_deltaTime = DELTATIME;
		}
	}
}

bool CBullet::Terminate()
{
	return false;
}
