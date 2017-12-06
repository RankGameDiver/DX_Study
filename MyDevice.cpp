#include "stdafx.h"
#include "MyDevice.h"

namespace MyDevice
{
	//����̽� �����Լ�
	HRESULT CreateDevice()
	{
		//1. Device �� ������ IDirect3D9 ��ü�� ��´�.
		LPDIRECT3D9 d3d9;
		d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

		//IDirect3D9 ��ü��Ⱑ �����ϸ� NULL �� ������
		if (d3d9 == NULL)
		{
			MessageBox(_hWnd, TEXT("Direct3DCreate9() - FAILED"), TEXT("FAILED"), MB_OK);
			return E_FAIL;
		}

		//2. �ϵ���� ������ ������ �ͼ� �ڽ��� ���� ���μ��� Ÿ���� ������
		D3DCAPS9	caps;
		//Direct3D9 ��ü�� ���� ���� ī���� �ϵ���� ������ ������ �´�.
		
		d3d9->GetDeviceCaps(
			D3DADAPTER_DEFAULT,		//�� ���÷��� �׷��� ī�� �׳� D3DADAPTER_DEFAULT
			D3DDEVTYPE_HAL,			//����̽�Ÿ�� ���� �׳� D3DDEVTYPE_HAL
			&caps					//����̽� ������ �޾ƿ� D3DCAPS9 ������
		);

		//������� ó������� ������ �÷��� ��
		DWORD vertexProcessing = 0;

		//���� ó���� ���� ���� ó���� �ϵ����� �����ϴ°�?
		if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
			vertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
		else
			vertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

		//3. D3DPRESENT_PARAMETERS ����ü ������ ����
		D3DPRESENT_PARAMETERS d3dpp = GetD3DPP(true);

		//4. Device ����

		//Direct3D9 ��ü�� ���ؼ� Device �� �����Ѵ�.

		HRESULT result = d3d9->CreateDevice(
			D3DADAPTER_DEFAULT,			//�� ���÷��� �׷��� ī�� �׳� D3DADAPTER_DEFAULT
			D3DDEVTYPE_HAL,				//����̽�Ÿ�� ���� �׳� D3DDEVTYPE_HAL
			_hWnd,						//����̽��� ����� ������ �ڵ�
			vertexProcessing,			//���� ó�� ��Ŀ� ���� �÷���
			&d3dpp,						//�տ��� ������ D3DPRESENT_PARAMETERS ����ü ������
			&Device);					//���� ����̽� ����������

		if (FAILED(result))
		{
			//����̽� ��������

			//d3d9 ��ü �������Ѵ�
			d3d9->Release();
			d3d9 = NULL;


			MessageBox(_hWnd, TEXT("CreateDevice() - FAILED"), TEXT("FAILED"), MB_OK);
			return E_FAIL;
		}


		//����̽� ��������
		d3d9->Release();
		d3d9 = NULL;

		return S_OK;
	}

	//����̽� �����Լ�
	void ReleaseDevice()
	{
		if (Device)
			Device->Release();
		Device = nullptr;
	}

	D3DPRESENT_PARAMETERS GetD3DPP(bool iswindow)
	{
		D3DPRESENT_PARAMETERS d3dpp;
		d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;					//���� ���ۿ� ���׽� ���� ũ�� ���� 24bit ���ٽ� ���� 8 ��Ʈ
		d3dpp.BackBufferCount = 1;										//����۴� �Ѱ�
		d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;						//����� ���� ���� ����8��Ʈ,����8��Ʈ,�׸�8��Ʈ,���8��Ʈ
		d3dpp.BackBufferWidth = WINSIZE_WIDTH;							//����� �ȼ� ���� ũ��
		d3dpp.BackBufferHeight = WINSIZE_HEIGHT;						//����� �ȼ� ���� ũ��
		d3dpp.EnableAutoDepthStencil = true;							//�ڵ� ���̹��� ��� ���� ( �׳� true )
		d3dpp.Flags = 0;												//�ϴ� 0
		d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;		//ȭ�� �ֻ��� ( �׳� D3DPRESENT_RATE_DEFAULT ����� �ֻ����� ���Ͻ� )
		d3dpp.hDeviceWindow = _hWnd;									//Device �� ��µ� ������ �ڵ�
		d3dpp.MultiSampleQuality = 0;									//��Ƽ ���ø� �� 
		d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;					//��Ƽ ���ø� Ÿ�� ( D3DMULTISAMPLE_NONE ��Ƽ�˸��ƽ� ������ ) 
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;			//ȭ�� ���� ���� ( �׳� D3DPRESENT_INTERVAL_ONE ����� �ֻ����� ���Ͻ� )
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;						//ȭ�� ���� ü�� ��� ( D3DSWAPEFFECT_DISCARD )
		d3dpp.Windowed = iswindow;										//â��� / ��üȭ��

		return d3dpp;
	}

	//vector<DISPLAY_SIZE> GetDeviceSize()
	//{
	//	vector<DISPLAY_SIZE> vecSize;
	//
	//	LPDIRECT3D9 d3d9;
	//	d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
	//
	//	if (d3d9 == NULL)
	//	{
	//		MessageBox(_hWnd, T("Direct3DCreate9() - FAILED"), T("FAILED"), MB_OK);
	//		return vecSize;
	//	}
	//
	//	int size = d3d9->GetAdapterModeCount(D3DADAPTER_DEFAULT, D3DFMT_X8R8G8B8);
	//	for (int i = 0; i < size; i++)
	//	{
	//		D3DDISPLAYMODE mode;
	//		DISPLAY_SIZE dissize;
	//		d3d9->EnumAdapterModes(D3DADAPTER_DEFAULT, D3DFMT_X8R8G8B8, i, &mode);
	//		dissize.width = mode.Width;
	//		dissize.height = mode.Height;
	//
	//		vecSize.push_back(dissize);
	//	}
	//
	//	return vecSize;
	//}
}