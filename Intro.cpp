#include "stdafx.h"
#include "Intro.h"


bool CIntro::Initialize()
{
	g_pInputManager->SetInputHandler(this);

	return false;
}

void CIntro::Terminate()
{
}

bool CIntro::Pulse()
{
	g_pInputManager->Pulse();
	return false;
}



void CIntro::Render()
{
}

CIntro::CIntro()
{
}


CIntro::~CIntro()
{
}

void CIntro::KeyboardHandler(void)
{
	//if (g_pKeyCodeScan(VK_SPACE))
	//{
	//	g_pSystem->ChangeScene(eSceneType::eSceneType_InGame);
	//}
		
}

void CIntro::MouseHandler(MOUSESTATE diMouseState)
{
}
