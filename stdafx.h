// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WINSIZE_WIDTH  800
#define WINSIZE_HEIGHT 800

#define MAX_LOADSTRING 100

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>
#include <mmsystem.h>


// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <array>
#include "./inc/fmod.hpp"
#include "./inc/fmod_errors.h"

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

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