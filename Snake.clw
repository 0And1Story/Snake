; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Snake.h"
LastPage=0

ClassCount=5
Class1=CSnakeApp
Class2=CSnakeDoc
Class3=CSnakeView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX

[CLS:CSnakeApp]
Type=0
HeaderFile=Snake.h
ImplementationFile=Snake.cpp
Filter=N

[CLS:CSnakeDoc]
Type=0
HeaderFile=SnakeDoc.h
ImplementationFile=SnakeDoc.cpp
Filter=N

[CLS:CSnakeView]
Type=0
HeaderFile=SnakeView.h
ImplementationFile=SnakeView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CSnakeView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDM_GAMEHELP
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Snake.cpp
ImplementationFile=Snake.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_GAMEHELP

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_GAMEHELP,button,1342242816

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=IDM_START
Command2=IDM_PAUSE
Command3=IDM_CONTINUE
Command4=IDM_EXIT
Command5=ID_APP_ABOUT
Command6=IDM_GAMEHELP
CommandCount=6

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=IDM_CONTINUE
Command2=IDM_EXIT
Command3=IDM_PAUSE
Command4=IDM_START
Command5=IDM_SETWIN
CommandCount=5

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=IDM_START
Command2=IDM_PAUSE
Command3=IDM_CONTINUE
Command4=IDM_EXIT
Command5=ID_APP_ABOUT
CommandCount=5

