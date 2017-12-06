#include "stdafx.h"
#include "FrameWork.h"


HINSTANCE hInst;   

LPDIRECT3DDEVICE9 Device;
HWND _hWnd;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	g_pSystem->Initialize();

	g_pSystem->Run();

	g_pSystem->Terminate();

	CSystem::DestroySingletone();
}