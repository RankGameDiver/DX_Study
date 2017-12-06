#pragma once

class CBaseWindow
{
protected:
	//HWND _hWnd;
	BOOL m_bIsActive;

public:
	CBaseWindow(void);
	virtual ~CBaseWindow(void);

	bool Initialize();
	void Terminate();

	__inline HWND GetHandle() const;
};

__inline HWND CBaseWindow::GetHandle() const
{
	return _hWnd;
}

