#include "stdafx.h"
#include "Player.h"

#define MOVESPEED 2.0f;
#define DELAYTIME_NORMAL 30;
#define DELAYTIME_ITEM 15;

CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

bool CPlayer::Initialize(Vector2D pos)
{
	m_vPos = pos;

	bulletList = new BulletList;
	bulletList->Initialize();

	m_bIsPressLeft = false;
	m_bIsPressRight = false;
	m_bIsPressUp = false;
	m_bIsPressDown = false;

	active = true;

	getItem = false;

	SetCollider(Vector2D(64, 82));

	attackDelay = DELAYTIME_NORMAL;

	g_pInputManager->SetInputHandler(this);

	return false;
}

void CPlayer::Render()
{
	if (active)
	{
		IMAGEMANAGER->ImgRender("mario", m_vPos, 0);

		bulletList->Render();

		//IMAGEMANAGER->RectRender(m_vPos, m_size);

	}
}

void CPlayer::Pulse()
{
	g_pInputManager->Pulse();

	if (active)
	{
		bulletList->Pulse();

		if (attackDelay > 0) attackDelay--;

		if (m_bIsPressLeft)		m_vPos.x -= MOVESPEED;
		if (m_bIsPressRight)	m_vPos.x += MOVESPEED;
		if (m_bIsPressUp)		m_vPos.y -= MOVESPEED;
		if (m_bIsPressDown)		m_vPos.y += MOVESPEED;
	}
}

bool CPlayer::Terminate()
{
	delete bulletList;
	return false;
}

void CPlayer::KeyboardHandler(void)
{
	if (g_pKeyCodeScan(VK_LEFT))	 m_bIsPressLeft = true;
	if (!g_pKeyCodeScan(VK_LEFT))	 m_bIsPressLeft = false;
	if (g_pKeyCodeScan(VK_RIGHT))    m_bIsPressRight = true;
	if (!g_pKeyCodeScan(VK_RIGHT))	 m_bIsPressRight = false;
	if (g_pKeyCodeScan(VK_UP))		 m_bIsPressUp = true;
	if (!g_pKeyCodeScan(VK_UP))		 m_bIsPressUp = false;
	if (g_pKeyCodeScan(VK_DOWN))	 m_bIsPressDown = true;
	if (!g_pKeyCodeScan(VK_DOWN))	 m_bIsPressDown = false;
	if (g_pKeyCodeScan('Z') && attackDelay <= 0)
	{
		bulletList->OnObject()->Initialize(m_vPos);
		if (getItem) { attackDelay = DELAYTIME_ITEM; }
		else if (!getItem) { attackDelay = DELAYTIME_NORMAL; }
	}
	if (g_pKeyCodeScan('X')) getItem ? getItem = false : getItem = true;
}

void CPlayer::MouseHandler(MOUSESTATE diMouseState)
{

}
 