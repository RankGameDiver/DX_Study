#pragma once

namespace MyDevice
{
	HRESULT CreateDevice();						//디바이스 생성함수
	void ReleaseDevice();						//디바이스 해제함수
	D3DPRESENT_PARAMETERS GetD3DPP(bool iswindow);
}