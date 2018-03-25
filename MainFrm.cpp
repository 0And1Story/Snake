// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Snake.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(IDM_START, OnStart)
	ON_COMMAND(IDM_PAUSE, OnPause)
	ON_COMMAND(IDM_CONTINUE, OnContinue)
	ON_COMMAND(IDM_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


//DEL void CMainFrame::OnStart() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

//DEL void CMainFrame::OnPause() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

//DEL void CMainFrame::OnContinue() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

//DEL void CMainFrame::OnExit() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

void CMainFrame::OnStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,3000,NULL);
	AfxMessageBox("3秒后开始游戏!");
}

void CMainFrame::OnPause() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
	AfxMessageBox("暂停游戏...");
}

void CMainFrame::OnContinue() 
{
	// TODO: Add your command handler code here
	SetTimer(1,10,NULL);
}

void CMainFrame::OnExit() 
{
	// TODO: Add your command handler code here
	AfxMessageBox("退出游戏...");
	exit(0);
}

//DEL void CMainFrame::OnSetWin() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

//DEL void CMainFrame::OnSetWin() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }
