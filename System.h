#pragma once

class CFrameSkip;

class CSystem : public Singletone<CSystem>,
	            public CBaseWindow,
				public CTimeManager
{
private:
	bool		m_bIsReady;// 시작하기전 대기.
	IScene*		m_pCurrScene;

	CFrameSkip*		m_pGameFrame;
	CInputManager*	m_pInputManager;
	CImageManager*	m_pImageManager;

	bool m_bFullScreen;

private:
	Vector2D	m_vMouseXY;
	bool m_bIsMouseLeft;
	bool m_bIsMouseRight;
	bool m_bIsMouseMid;

public:
	CSystem(void);
	virtual ~CSystem(void);

public:
	bool Initialize(void);
	void Update(void);
	void Terminate(void);
	void Run(void);

	void ChangeScene(IScene::eSceneType eType);

public:
	__inline void SetFullScreen(bool bFullScreen);
	__inline bool GetFullScreen() const;
};

#define g_pSystem	CSystem::GetSingletone()

__inline void CSystem::SetFullScreen(bool bFullScreen)
{
	m_bFullScreen = bFullScreen;
}

__inline bool CSystem::GetFullScreen() const
{
	return m_bFullScreen;
}