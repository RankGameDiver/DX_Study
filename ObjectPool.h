#pragma once
class ObjectPool
{
private:
	CBaseObject* objList;
	int i_listLength;

public:
	ObjectPool();
	~ObjectPool();

public:
	void Initialize(CBaseObject obj,int length);
	void Terminate();

	CBaseObject OnObject();

	int GetListLength() { return i_listLength; };
	CBaseObject GetBaseObject(int i) { return objList[i]; };
};

