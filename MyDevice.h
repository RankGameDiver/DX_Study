#pragma once

namespace MyDevice
{
	HRESULT CreateDevice();						//����̽� �����Լ�
	void ReleaseDevice();						//����̽� �����Լ�
	D3DPRESENT_PARAMETERS GetD3DPP(bool iswindow);
}