#include "stdafx.h"
#include "BulletList.h"

#define LISTLENGTH 200

BulletList::BulletList()
{
}


BulletList::~BulletList()
{
}

void BulletList::Initialize()
{
	for (int i = 0; i < LISTLENGTH; i++)
	{
		bulletList[i] = new CBullet;
		bulletList[i]->Initialize(Vector2D(0, 0));
		bulletList[i]->SetActive(false);
	}
}

void BulletList::Render()
{
	for (int i = 0; i < LISTLENGTH; i++)
	{
		if (bulletList[i]->GetActive())
		{
			bulletList[i]->Render();
		}
	}
}

void BulletList::Pulse()
{
	for (int i = 0; i < LISTLENGTH; i++)
	{
		if (bulletList[i]->GetActive())
		{
			bulletList[i]->Pulse();
		}
	}
}

void BulletList::Terminate()
{
	delete[] bulletList;
}

CBullet* BulletList::OnObject()
{
	for (int i = 0; i < LISTLENGTH; i++)
	{
		if (!bulletList[i]->GetActive())
		{
			bulletList[i]->SetActive(true);
			return bulletList[i];
		}
	}
}
