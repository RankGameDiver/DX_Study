// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WINSIZE_WIDTH  800
#define WINSIZE_HEIGHT 800

#define MAX_LOADSTRING 100

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>
#include <mmsystem.h>


// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <array>
#include "./inc/fmod.hpp"
#include "./inc/fmod_errors.h"

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

#include <map>
#include <string>
#include "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include/d3d9.h"
#include "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include/d3dx9.h"

#pragma comment(lib, "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86/d3d9.lib")
#pragma comment(lib, "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86/d3dx9.lib")
#pragma comment(lib, "./lib/fmodex_vc.lib")

extern HWND _hWnd;
extern LPDIRECT3DDEVICE9 Device;

#include "Resource.h"
#include "Singletone.h"
#include "MyDevice.h"

#include "Vector2d.h"

#include "IScene.h"
#include "ImageManager.h"
#include "SoundManager.h"
#include "BaseWindow.h"
#include "TimeManager.h"
#include "FrameSkip.h"
#include "InputHandler.h"
#include "InputManager.h"
#include "MainProc.h"

#include "Object.h"

#include "Bullet.h"
#include "BulletList.h"
#include "Enemy.h"
#include "Player.h"

#include "MainGame.h"
#include "Intro.h"
#include "System.h"