#include "stdafx.h"
#include "ObjectPool.h"


ObjectPool::ObjectPool()
{
}


ObjectPool::~ObjectPool()
{
}

void ObjectPool::Initialize(CBaseObject obj, int length)
{
	objList = new CBaseObject[length];
	i_listLength = length;

	for(int i = 0; i < i_listLength; i++)
	{
		objList[i] = obj;
	}
}

void ObjectPool::Terminate()
{
	delete[] objList;
}

CBaseObject ObjectPool::OnObject()
{
	for (int i = 0; i < i_listLength; i++)
	{
		if (!objList[i].GetActive())
		{
			objList[i].SetActive(true);
			return objList[i];
		}
	}
}
