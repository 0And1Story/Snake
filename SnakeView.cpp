// SnakeView.cpp : implementation of the CSnakeView class
//

#include "stdafx.h"
#include "Snake.h"

#include "SnakeDoc.h"
#include "SnakeView.h"
#include <string.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


struct Snake
{
	int x,y;
	int len;
	int direct;
}Snake[50];

struct Food
{
	int x;
    int y;
    int isfood;
}Food;

void CSnakeView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	Snake[0].x=10;
	Snake[0].y=10;
	Snake[1].x=11;
	Snake[1].y=10;
	Snake[2].x=12;
	Snake[2].y=10;
	Snake[0].direct=3;
	Snake[0].len=3;
	Food.isfood=1;
	// TODO: Add your specialized code here and/or call the base class
}


/////////////////////////////////////////////////////////////////////////////
// CSnakeView

IMPLEMENT_DYNCREATE(CSnakeView, CView)

BEGIN_MESSAGE_MAP(CSnakeView, CView)
	//{{AFX_MSG_MAP(CSnakeView)
	ON_WM_KEYDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
	ON_COMMAND(IDM_START, OnStart)
	ON_COMMAND(IDM_PAUSE, OnPause)
	ON_COMMAND(IDM_CONTINUE, OnContinue)
	ON_COMMAND(IDM_EXIT, OnExit)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnakeView construction/destruction

CSnakeView::CSnakeView()
{
	// TODO: add construction code here

}

CSnakeView::~CSnakeView()
{
}

BOOL CSnakeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSnakeView drawing

void CSnakeView::OnDraw(CDC* pDC)
{
	CSnakeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CBrush backBrush(RGB(100,100,0));
	CBrush* pOldBrush = pDC->SelectObject(&backBrush);
	CRect rect;
	pDC->GetClipBox(&rect);
	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(),PATCOPY);
	pDC->SelectObject(pOldBrush);

	pDC->Rectangle(19,19,501,501);
	oninit();
}

/////////////////////////////////////////////////////////////////////////////
// CSnakeView printing

BOOL CSnakeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSnakeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSnakeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSnakeView diagnostics

#ifdef _DEBUG
void CSnakeView::AssertValid() const
{
	CView::AssertValid();
}

void CSnakeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSnakeDoc* CSnakeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnakeDoc)));
	return (CSnakeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSnakeView message handlers

void CSnakeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar)
	{
		case VK_UP:if(Snake[0].direct!=2)Snake[0].direct=1;break;
		case VK_DOWN:if(Snake[0].direct!=1)Snake[0].direct=2;break;
		case VK_LEFT:if(Snake[0].direct!=4)Snake[0].direct=3;break;  
		case VK_RIGHT:if(Snake[0].direct!=3)Snake[0].direct=4;break;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CSnakeView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	// TODO: Add your message handler code here and/or call default
	CString str;
	str.Format("%d,%d",point.x,point.y);
	AfxMessageBox(str);
	CView::OnRButtonDown(nFlags, point);
	CView::OnRButtonDown(nFlags, point);
	CView::OnRButtonDown(nFlags, point);
}

void CSnakeView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CDC *pDC=GetDC();
	CString soure;
 
	if(Snake[0].len==2)SetTimer(1,370,NULL);
	if(Snake[0].len==3)SetTimer(1,270,NULL);
	if(Snake[0].len==6)SetTimer(1,200,NULL);
	if(Snake[0].len==9)SetTimer(1,100,NULL);
 
	soure.Format("得分:%d!",(Snake[0].len-3)*10); 
	//撞界判断
	if(Snake[0].x*20<=37||Snake[0].y*20<=37||Snake[0].x*20>=462||Snake[0].y*20>=462)
	{
		KillTimer(1);
		AfxMessageBox(soure);
		// s=0;
	}
    //蛇身相撞判断
	if(Snake[0].len>3)
	for(int sn=Snake[0].len-1;sn>0;sn--)
	{
		if(Snake[0].x*20==Snake[sn].x*20&&Snake[0].y*20==Snake[sn].y*20)
		{
			KillTimer(1);
			AfxMessageBox(soure);
			//  s=0;
		}
	}
	///////////////////////////////////////////////////////////////////////////
	CDC *pHEAD=GetDC();
	CBrush SHead=(RGB(100,255,100));
	pHEAD->SelectObject(SHead);

	CDC *pEYE=GetDC();
	CBrush SEye=(RGB(255,0,255));
	pEYE->SelectObject(SEye);
	///////////////////////////////////////////////////////////////////////////
	pDC->SelectStockObject(WHITE_PEN);
	pDC->Rectangle(Snake[Snake[0].len-1].x*20,Snake[Snake[0].len-1].y*20,(Snake[Snake[0].len-1].x+1)*20,(Snake[Snake[0].len-1].y+1)*20);
	pHEAD->Rectangle(Snake[0].x*20,Snake[0].y*20,(Snake[0].x+1)*20,(Snake[0].y+1)*20);
	switch(Snake[0].direct)
	{
	case 1:
		pEYE->Rectangle(Snake[0].x*20+5+2,Snake[0].y*20+10,Snake[0].x*20+5+5+2,Snake[0].y*20+10+5);
		//pEYE->Rectangle(Snake[0].x*20+20,Snake[0].y*20+10,Snake[0].x*20+20+5,Snake[0].y*20+10+5);
		break;

	case 2:
		pEYE->Rectangle(Snake[0].x*20+5+2,Snake[0].y*20+15,Snake[0].x*20+5+5+2,Snake[0].y*20+15+5);
		//pEYE->Rectangle(Snake[0].x*20+20,Snake[0].y*20+15,Snake[0].x*20+20+5,Snake[0].y*20+15+5);
		break;

	case 3:
		pEYE->Rectangle(Snake[0].x*20+10,Snake[0].y*20+5+2,Snake[0].x*20+10+5,Snake[0].y*20+5+5+2);
		//pEYE->Rectangle(Snake[0].x*20+10,Snake[0].y*20+20,Snake[0].x*20+10+5,Snake[0].y*20+20+5);
		break;

	case 4:
		pEYE->Rectangle(Snake[0].x*20+15,Snake[0].y*20+5+2,Snake[0].x*20+15+5,Snake[0].y*20+5+5+2);
		//pEYE->Rectangle(Snake[0].x*20+15,Snake[0].y*20+20,Snake[0].x*20+15+5,Snake[0].y*20+20+5);
		break;

	default:
		break;
	}
	for(int i=Snake[0].len-1;i>0;i--)
	{
		Snake[i].x=Snake[i-1].x;
		Snake[i].y=Snake[i-1].y;
	}
	//行走方向判断
	if(Snake[0].direct==1)Snake[0].y--;
	if(Snake[0].direct==2)Snake[0].y++;
	if(Snake[0].direct==3)Snake[0].x--;
	if(Snake[0].direct==4)Snake[0].x++;
	pDC->SelectStockObject(BLACK_PEN);
  
	CBrush DrawBrush=(RGB(100,255,255));
	CBrush *Drawbrush=pDC->SelectObject(&DrawBrush);
	pDC->Rectangle(Snake[0].x*20,Snake[0].y*20,(Snake[0].x+1)*20,(Snake[0].y+1)*20);
	pDC->SelectObject(DrawBrush);

	//判断吃豆的条件,撞到就吃
	if(Snake[0].x*20==Food.x*20&&Snake[0].y*20==Food.y*20)
	{
		Snake[0].len++;
		Food.isfood=1;
		Snake[Snake[0].len-1].x=Snake[Snake[0].len-2].x;
		Snake[Snake[0].len-1].y=Snake[Snake[0].len-2].y;
	}
	//如果食物被吃了 就生成
	CDC *pFOOD=GetDC();
	CBrush SFood=(RGB(100,100,100));
	pFOOD->SelectObject(SFood);
	if(Food.isfood==1)
	{
		srand((unsigned)time(NULL));
		do
		{
			for(int isfo=Snake[0].len-1;isfo>=0;isfo--)
				if(Snake[0].x*20==Snake[isfo].x*20&&Snake[0].y*20==Snake[isfo].y*20)
					{
						Food.x=rand()%25;
						Food.y=rand()%25;
					}
		}
		while(Food.x*20<70||Food.y*20<70||Food.x*20>430||Food.y*20>430);
			pFOOD->Rectangle(Food.x*20,Food.y*20,(Food.x+1)*20,(Food.y+1)*20);
		Food.isfood=0;
	}
	pFOOD->Rectangle(Food.x*20,Food.y*20,(Food.x+1)*20,(Food.y+1)*20);

	CFont newfont;
	//CFont oldFont;
	newfont.CreateFont(
		20,
		10,
		0,
		0,
		FW_NORMAL,
		false,
		false,
		0,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH|FF_SWISS,
		_T("华文细黑")
	);
	/*oldFont = */pDC->SelectObject(&newfont);
	pDC->SetTextColor(RGB(255,0,0));
	pDC->TextOut(22,21,soure);

//	pDC->TextOut(21,21,soure);

	CView::OnTimer(nIDEvent);
}

void CSnakeView::OnStart() 
{
	// TODO: Add your command handler code here
	oninit();
	SetTimer(1,3000,NULL);
	AfxMessageBox("3秒后开始游戏!",MB_ICONINFORMATION);
}

void CSnakeView::OnPause() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
	AfxMessageBox("暂停游戏...",MB_ICONWARNING);
}

void CSnakeView::OnContinue() 
{
	// TODO: Add your command handler code here
	SetTimer(1,10,NULL);
}

void CSnakeView::OnExit() 
{
	// TODO: Add your command handler code here
	AfxMessageBox("退出游戏...",MB_ICONINFORMATION);
	exit(0);
}

void CSnakeView::oninit()
{
	CDC *pFLUSH=GetDC();
	CBrush FBrush=(RGB(255,50,50));
	pFLUSH->SelectObject(FBrush);
	pFLUSH->Rectangle(0,0,1000,1000);
	CBrush FBG=(RGB(255,255,255));
	pFLUSH->SelectObject(FBG);
	pFLUSH->Rectangle(20,20,500,500);
	CDC *pDC=GetDC();
	CBrush DrawBrush=(RGB(100,255,255));
	CBrush *Drawbrush=pDC->SelectObject(&DrawBrush);
	Snake[0].x=10;
	Snake[0].y=10;
	Snake[1].x=11;
	Snake[1].y=10;
	Snake[2].x=12;
	Snake[2].y=10;
	Snake[0].direct=3;
	Snake[0].len=3;
	Food.isfood=1;
	for(int i=0;i<=Snake[0].len-1;i++)
		pDC->Rectangle(Snake[i].x*20,Snake[i].y*20,(Snake[i].x+1)*20,(Snake[i].y+1)*20);
	pDC->SelectObject(DrawBrush);
}

//DEL void CSnakeView::OnSetWin() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

//DEL void CSnakeView::Paint1(int x, int y)
//DEL {
//DEL 	CDC *pDC=GetDC();
//DEL 	CBrush DrawBrush=(RGB(100,255,255));
//DEL 	CBrush *Drawbrush=pDC->SelectObject(&DrawBrush);
//DEL }

//DEL void CSnakeView::Paint2(int x, int y)
//DEL {
//DEL 
//DEL }

//DEL void CSnakeView::Paint3(int x, int y)
//DEL {
//DEL 
//DEL }

//DEL void CSnakeView::Paint4(int x, int y)
//DEL {
//DEL 
//DEL }

//DEL void CSnakeView::Paint5(int x, int y)
//DEL {
//DEL 
//DEL }

//DEL void CSnakeView::Paint6(int x, int y)
//DEL {
//DEL 
//DEL }

//DEL void CSnakeView::Paint7(int x, int y)
//DEL {
//DEL 
//DEL }

//DEL void CSnakeView::Paint8(int x, int y)
//DEL {
//DEL 
//DEL }

//DEL void CSnakeView::Paint9(int x, int y)
//DEL {
//DEL 
//DEL }

//DEL void CSnakeView::Paint0(int x, int y)
//DEL {
//DEL 
//DEL }
