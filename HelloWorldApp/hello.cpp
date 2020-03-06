#include <afxwin.h>
#include "pch.h"
#include "hello.h"

HelloApp helloApp;

/////////////////////////////////////////////////////////////////////////
// CMyApp member functions

BOOL HelloApp::InitInstance()
{
	m_pMainWnd = new CMainWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////
// CMainWindow message map and member functions

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()

CMainWindow::CMainWindow()
{
	Create(NULL, _T("The Hello Application"));
}

void CMainWindow::OnPaint()
{
	CPaintDC dc(this);

	CRect rect;
	GetClientRect(&rect);

	dc.DrawText(_T("Hello, MFC World!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}
