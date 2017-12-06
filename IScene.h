#pragma once

class IScene
{
public:
	enum eSceneType
	{
		eSceneType_Unknown,
		eSceneType_Intro,
		eSceneType_Menu,
		eSceneType_InGame,
		eSceneType_Exit,
		eSceneType_Quit,
		eSceneType_Count,
	};

public:
	eSceneType m_eType;

public:
	IScene()
	{
		m_eType = eSceneType_Unknown;
	}

	virtual ~IScene()
	{
	}

	__inline void SetType(eSceneType eType);
	__inline eSceneType GetType() const;

	virtual bool Initialize() = 0;
	virtual void Terminate() = 0;
	virtual bool Pulse() = 0;
	virtual void Render() = 0;
};

__inline void IScene::SetType(eSceneType eType)
{
	m_eType = eType;
}

__inline IScene::eSceneType IScene::GetType() const
{
	return m_eType;
}
