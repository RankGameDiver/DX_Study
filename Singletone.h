#pragma once

template <typename T>
class Singletone
{
protected:
	static T* p;
public:
	static T* GetSingletone()
	{
		if (!p)
			p = new T;
		return p;
	}
	static void DestroySingletone()
	{
		if (p)
			delete p;
		p = nullptr;
	}
};

template <typename T>
T* Singletone<T>::p = nullptr;