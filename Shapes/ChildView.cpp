
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "Shapes.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_SHAPE_CIRCLE, &CChildView::OnShapeCircle)
	ON_COMMAND(ID_SHAPE_SQUARE, &CChildView::OnShapeSquare)
	ON_COMMAND(ID_SHAPE_TRIANGLE, &CChildView::OnShapeTriangle)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_CIRCLE, &CChildView::OnUpdateShapeCircle)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_SQUARE, &CChildView::OnUpdateShapeSquare)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_TRIANGLE, &CChildView::OnUpdateShapeTriangle)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	                                   
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages

	CPoint points[3];
	CPaintDC dc(this);

	CRect rcClient;
	GetClientRect(&rcClient);

	int cx = rcClient.Width() / 2;
	int cy = rcClient.Height() / 2;
	CRect rcShape(cx - 45, cy - 45, cx + 45, cy + 45);

	CBrush brush(RGB(255, 0, 0));
	CBrush* pOldBrush = dc.SelectObject(&brush);

	switch (m_nShape) 
	{

	case 0: // Circle
		dc.Ellipse(rcShape);
		break;

	case 1: // Triangle
		points[0].x = cx - 45;
		points[0].y = cy + 45;
		points[1].x = cx;
		points[1].y = cy - 45;
		points[2].x = cx + 45;
		points[2].y = cy + 45;
		dc.Polygon(points, 3);
		break;

	case 2: // Square
		dc.Rectangle(rcShape);
		break;
	}
	dc.SelectObject(pOldBrush);
}

void CChildView::OnShapeCircle()
{
	m_nShape = 0;
	Invalidate();
}

void CChildView::OnShapeTriangle()
{
	m_nShape = 1;
	Invalidate();
}

void CChildView::OnShapeSquare()
{
	m_nShape = 2;
	Invalidate();
}


void CChildView::OnUpdateShapeCircle(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
}


void CChildView::OnUpdateShapeSquare(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
}


void CChildView::OnUpdateShapeTriangle(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
}
