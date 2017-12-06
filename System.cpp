#include "stdafx.h"

CSystem::CSystem(void)
{
	m_bIsReady = false;
	m_pCurrScene = NULL;
}

CSystem::~CSystem(void)
{

}

bool CSystem::Initialize(void)
{
	CBaseWindow::Initialize();
	CTimeManager::Initialize();

	MyDevice::CreateDevice();

	m_pGameFrame = new CFrameSkip;
	m_pGameFrame->SetFramePerSec(60);

	m_pInputManager = new CInputManager;
	m_pInputManager->Initialize();

	m_pInputManager->SetInputHandler(NULL);




	ChangeScene(IScene::eSceneType::eSceneType_InGame);

	return true; 
}

void CSystem::Update(void)
{
	CTimeManager::Pulse();
	m_pInputManager->Pulse();

	if (!m_pCurrScene){ return; }
	m_pCurrScene->Pulse();

	float fTimeStep = CTimeManager::GetTimeStep();

	if (m_pGameFrame->Update(fTimeStep))
	{
		{
			Device->Clear(0, nullptr, D3DCLEAR_STENCIL | D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(255, 0, 0, 255), 1.0f, 0);
			Device->BeginScene();
			IMAGEMANAGER->Begin();

			m_pCurrScene->Render();

			IMAGEMANAGER->End();
			Device->EndScene();
			Device->Present(0, 0, 0, 0);
		}
	}
}

void CSystem::Terminate(void)
{
	CBaseWindow::Terminate();
	CTimeManager::Terminate();

	g_pInputManager->SetInputHandler(NULL);

	delete m_pInputManager;
	delete m_pGameFrame;
}

void CSystem::Run(void)
{
	MSG msg;

	PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else	return;

		}
		else if (m_bIsActive)
		{
			Update();
		}
		else
		{
			WaitMessage();
		}
	}
}


void CSystem::ChangeScene(IScene::eSceneType eType)
{
	auto a = this;
	if (m_pCurrScene)
	{
		m_pCurrScene->Terminate();
		delete m_pCurrScene;
		m_pCurrScene = NULL;
	}

	switch (eType)
	{
	case IScene::eSceneType_Intro:
		m_pCurrScene = new CIntro;
		break;

	case IScene::eSceneType_Menu:
		break;

	case IScene::eSceneType_InGame:
		m_pCurrScene = new CMainGame;
		break;

	case IScene::eSceneType_Exit:
		break;

	case IScene::eSceneType_Quit:
		SendMessage(_hWnd, WM_QUIT, NULL, NULL);
		break;
	}

	if (m_pCurrScene)
	{
		m_pCurrScene->Initialize();
	}

}