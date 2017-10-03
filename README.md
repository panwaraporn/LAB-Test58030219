# LAB-Test58030219
#include<windows.h>
#include<tchar.h>
#include "resource.h"
// Global Variables: 
HINSTANCE hInst;		//current instance
TCHAR szTitle[] = "Easywin32";	//The title bar text
TCHAR szWindowClass[]="WinApp";		//the class name
BOOL fDraw = FALSE; POINT ptPrevious; // pan insert function fDraw
COLORREF Color[]={RGB(255,0,0),RGB(0,255,0),RGB(0,0,255),RGB(0,0,0)};
int Index;
// Forward declarations of functions included in this code module:
ATOM		MyRegisterClass(HINSTANCE hInstance);
BOOL		InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND,UINT,WPARAM,LPARAM);
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	IpCmdLine,
	int nCmdShow)
{
	//TODO: Place code here.
	MSG msg;
	//Register Class
	MyRegisterClass(hInstance);
	//Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}
	//Main message loop:
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
//FUNCTION: MyRegisterClass()
// PURPOSE: Registers the window class.
//COMMENTS:
//This function and its usage is only necessary if you want this code
//to be commpatible with Win32 systems prior to the 'RegisterClassEx'
//function that was added to Windows 95.
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style 	= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance 		= hInstance;
	wcex.hIcon			= LoadIcon(NULL,IDI_APPLICATION);
	wcex.hCursor	= LoadCursor(NULL,IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
//	wcex.lpszMenuName	= NULL;
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDR_MYMENU);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm	= LoadIcon(NULL,IDI_APPLICATION);
//	wcex.hIcon	= LoadIcon(GetModuleHandle(NULL)
MAKEINTRESOURCE(IDI_MYICON);
//	wcex.hIconSm	= (HICON)LoadImage(GetModuleHandle(NULL),
// MAKEINTRESOURCE(IDI_MYICON),IMAGE_ICON,16,16,0);
	return RegisterClassEx(&wcex);
}
//FUNCTION: Initlnstance(HANDLE, int)
//PURPOSE: Saves instance handle and creates main window
//COMMENTS:
//	In this function, we save this instance handle in a global variable and
// 	create and display the main program window.
BOOL InitInstance(HINSTANCE hInstance,int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance; // Store instance handle in our global variable
	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	CW_USEDEFAULT,0,CW_USEDEFAULT,0,NULL,NULL,hInstance,NULL);	
if(!hWnd)
{
	return FALSE;
}
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}
// FUNCTION: WndProc(HWND,unsigned,WORLD,LONG)
// PURPOSE: Processes messages for the main window.
// WM_COMMAND	-process the application menu
// WM_PAINT		-Paint the main window
// WM_DESTROY	-post a quit message and return
CLR(HDC hdc)
{
	SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
	SelectObject(hdc,CreatePen(PS_SOLID,1,RGB(255,255,255)));
	Rectangle(hdc,50,35,800,1200);
}	
PUCAHEAD(HDC hdc)
{  
	SelectObject(hdc,CreateSolidBrush(RGB(0,0,0)));		//black
	Ellipse(hdc,100,100,400,350);	//head1
	SelectObject(hdc,CreateSolidBrush(RGB(250,240,250)));	
	Ellipse(hdc,125,150,375,350);//head2
}			
PUCAHAIR(HDC hdc)
	{
	SelectObject(hdc,CreateSolidBrush(RGB(0,0,0)));		//black
	Ellipse(hdc,50,60,170,210);//hair
	Ellipse(hdc,340,60,460,210);//hair
	}
PUCABODY (HDC hdc)
{
	SelectObject(hdc,CreateSolidBrush(RGB(250,0,0)));
	SelectObject(hdc,CreatePen(PS_DASHDOTDOT,5,RGB(0,0,0)));
	Rectangle(hdc,160,320,340,500);//body
}
PUCAARM (HDC hdc)
{
	SelectObject(hdc,CreateSolidBrush(RGB(250,0,0)));
	SelectObject(hdc,CreatePen(PS_DASHDOTDOT,5,RGB(0,0,0)));
	Ellipse(hdc,140,320,200,450); //arm1
	Ellipse(hdc,300,320,360,450); //arm2
	SelectObject(hdc,CreateSolidBrush(RGB(250,240,250)));
	Ellipse(hdc,140,400,200,450); //arm1
	Ellipse(hdc,300,400,360,450); //arm2
}
PUCALEG (HDC hdc)
{
	SelectObject(hdc,CreateSolidBrush(RGB(0,0,0)));		//black
	SelectObject(hdc,CreatePen(PS_DASHDOTDOT,5,RGB(0,0,0)));
	Ellipse(hdc,260,450,330,600); //leg1
	Ellipse(hdc,170,450,240,600); //leg2
}
PUCAGAM (HDC hdc)
{
	SelectObject(hdc,CreatePen(PS_DASHDOTDOT,2,RGB(250,200,250)));
	SelectObject(hdc,CreateSolidBrush(RGB(250,200,250)));
	Ellipse(hdc,160,280,200,300); 
	Ellipse(hdc,300,280,340,300); 
}
PUCAEYE (HDC hdc)
{
	SelectObject(hdc,CreatePen(PS_DASHDOTDOT,5,RGB(0,0,0)));
	MoveToEx(hdc,150,250,NULL); //eye
	LineTo(hdc,210,260);	
	MoveToEx(hdc,350,250,NULL); //eye2
	LineTo(hdc,290,260);
}
PUCAEYEBROW (HDC hdc)
{
	SelectObject(hdc,CreatePen(PS_DASHDOTDOT,5,RGB(0,0,0)));
	Arc(hdc,140,190,220,210,220,200,140,200);//eyebrow1
	Arc(hdc,280,190,360,210,360,200,280,200);//eyebrow2
}
PUCAMOUSE (HDC hdc)
{
	SelectObject(hdc,CreatePen(PS_DASHDOTDOT,5,RGB(0,0,0)));
	Arc(hdc,240,240,260,320,240,300,280,335);//mouse
}
//----------------------------------------------------------------------------
GARULEG (HDC hdc)
{
	SelectObject(hdc,CreateSolidBrush(RGB(0,0,0)));
	Ellipse(hdc,660,400,740,600); //leg1
	Ellipse(hdc,560,400,640,600); //leg2	
}
GARUBODY (HDC hdc)
{
	SelectObject(hdc,CreateSolidBrush(RGB(0,0,0)));
	SelectObject(hdc,CreatePen(PS_DASHDOTDOT,5,RGB(20,20,20)));
	Ellipse(hdc,530,300,770,500);//body
}
GARUARM (HDC hdc)
{
	SelectObject(hdc,CreatePen(PS_DASHDOTDOT,5,RGB(20,20,20)));
	SelectObject(hdc,CreateSolidBrush(RGB(0,0,0)));
	Ellipse(hdc,520,300,580,450); //arm1
	Ellipse(hdc,720,300,780,450); //arm2
	SelectObject(hdc,CreateSolidBrush(RGB(250,0,0)));
	Ellipse(hdc,520,400,580,450); //arm1
	Ellipse(hdc,720,400,780,450); //arm2
}
GARUHEAD (HDC hdc)
{
	SelectObject(hdc,CreateSolidBrush(RGB(0,0,0)));
	Ellipse(hdc,500,100,800,350); //head
	SelectObject(hdc,CreateSolidBrush(RGB(250,240,250)));
	Ellipse(hdc,520,140,780,340); //head
}
GARUEYE (HDC hdc)
{
	SelectObject(hdc,CreatePen(PS_DASHDOTDOT,5,RGB(0,0,0)));
	SelectObject(hdc,CreateSolidBrush(RGB(250,240,250)));
	Ellipse(hdc,550,220,620,280); //eye1
	Ellipse(hdc,680,220,750,280); //eye2
	SelectObject(hdc,CreateSolidBrush(RGB(0,0,0)));
	Ellipse(hdc,580,240,600,260); //eye1
	Ellipse(hdc,700,240,720,260); //eye2
	Arc(hdc,600,300,700,350,700,320,600,320);//eyebrow1
	SelectObject(hdc,CreatePen(PS_DASHDOTDOT,10,RGB(20,20,20)));
	MoveToEx(hdc,550,210,NULL); //eye
	LineTo(hdc,620,230);
	MoveToEx(hdc,680,230,NULL); //eye
	LineTo(hdc,750,210);
}
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,
LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rt;
	char szHello[]="58030219";
	switch(message)
	{
		{ case WM_CREATE:
			  
     		CreateWindow(TEXT("button"), TEXT("CLR"),
                WS_VISIBLE | WS_CHILD,
                850, 10, 100, 30,
                hWnd, ID_PIC_CLR, NULL, NULL);
       		CreateWindow(TEXT("button"), TEXT("HEAD"),
                WS_VISIBLE | WS_CHILD,
                850, 50, 100, 30,
                hWnd, ID_PIC_PUCAHEAD, NULL, NULL);
			CreateWindow(TEXT("button"), TEXT("PUCAHAIR"),
                WS_VISIBLE | WS_CHILD,
                850, 90, 100, 30,
                hWnd, ID_PIC_PUCAHAIR, NULL, NULL);
   			CreateWindow(TEXT("button"), TEXT("PUCABODY"),
                WS_VISIBLE | WS_CHILD,
                850, 130, 100, 30,
                hWnd, ID_PIC_PUCABODY, NULL, NULL);
      		CreateWindow(TEXT("button"), TEXT("PUCAARM"),
                WS_VISIBLE | WS_CHILD,
                850, 170, 100, 30,
                hWnd, ID_PIC_PUCAARM, NULL, NULL);
        	CreateWindow(TEXT("button"), TEXT("PUCALEG"),
                WS_VISIBLE | WS_CHILD,
                850, 210, 100, 30,
                hWnd, ID_PIC_PUCALEG, NULL, NULL);
         	CreateWindow(TEXT("button"), TEXT("PUCAGAM"),
                WS_VISIBLE | WS_CHILD,
                850, 250, 100, 30,
                hWnd, ID_PIC_PUCAGAM, NULL, NULL);
        	CreateWindow(TEXT("button"), TEXT("PUCAEYE"),
                WS_VISIBLE | WS_CHILD,
                850, 290, 100, 30,
                hWnd, ID_PIC_PUCAEYE, NULL, NULL);
           CreateWindow(TEXT("button"), TEXT("PUCAEYEBROW"),
                WS_VISIBLE | WS_CHILD,
                850, 330, 100, 30,
                hWnd, ID_PIC_PUCAEYEBROW, NULL, NULL);
           CreateWindow(TEXT("button"), TEXT("PUCAMOUSE"),
                WS_VISIBLE | WS_CHILD,
                850, 370, 100, 30,
                hWnd, ID_PIC_PUCAMOUSE, NULL, NULL);
//--------------------------------------------------------------------
			CreateWindow(TEXT("button"), TEXT("GARULEG"),
                WS_VISIBLE | WS_CHILD,
                1000, 50, 100, 30,
                hWnd, ID_PIC_GARULEG, NULL, NULL);
   			CreateWindow(TEXT("button"), TEXT("GARUBODY"),
                WS_VISIBLE | WS_CHILD,
                1000, 90, 100, 30,
                hWnd, ID_PIC_GARUBODY, NULL, NULL);
			CreateWindow(TEXT("button"), TEXT("GARUARM"),
                WS_VISIBLE | WS_CHILD,
                1000, 130, 100, 30,
                hWnd, ID_PIC_GARUARM, NULL, NULL);
   			CreateWindow(TEXT("button"), TEXT("GARUHEAD"),
                WS_VISIBLE | WS_CHILD,
                1000, 170, 100, 30,
                hWnd, ID_PIC_GARUHEAD, NULL, NULL);
   			CreateWindow(TEXT("button"), TEXT("GARUEYE"),
                WS_VISIBLE | WS_CHILD,
                1000, 210, 100, 30,
                hWnd, ID_PIC_GARUEYE, NULL, NULL);
				break;
			}
		case WM_PAINT:
			hdc = BeginPaint(hWnd,&ps);
			// TODO: Add any drawing code here...
			GetClientRect(hWnd,&rt);
			DrawText(hdc,szHello,strlen(szHello),&rt,DT_CENTER); 
		//	InvalidateRect(hWnd, NULL, TRUE);
			EndPaint(hWnd,&ps);
			break;
		case WM_LBUTTONDOWN:
			fDraw = TRUE;
			ptPrevious.x = LOWORD(lParam);
			ptPrevious.y = HIWORD(lParam);
			return 0L;
		case WM_LBUTTONUP:
			if(fDraw)
			{
				hdc = GetDC(hWnd);
				MoveToEx(hdc,ptPrevious.x,ptPrevious.y,NULL);
				LineTo(hdc,LOWORD(lParam),HIWORD(lParam));
				ReleaseDC(hWnd,hdc);
			}
				fDraw = FALSE;
				return 0L;
		case WM_MOUSEMOVE:
			if(fDraw)
			{
				HDC hdc;
				HPEN hPen;
				hdc = GetDC(hWnd);
				hPen = CreatePen(PS_DOT,10,Color[Index]);
				SelectObject(hdc, hPen);
				MoveToEx(hdc,ptPrevious.x,ptPrevious.y,NULL);
				LineTo(hdc,ptPrevious.x = LOWORD(lParam),
				ptPrevious.y = HIWORD(lParam));
				ReleaseDC(hWnd,hdc);
			}
			return 0L;
		
			case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case ID_FILE_EXIT:
									PostMessage(hWnd,WM_CLOSE,0,0);
					break;
				case ID_FILE_RED:
						Index = 0;
					break;
				case ID_FILE_GREEN:
						Index = 2;
					break;
				case ID_FILE_BLUE:
						Index = 1;
					break;
				case ID_FILE_BLACK:
						Index = 3;
					break;	

				case ID_PIC_CLR:
				 hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,CLR(hdc),NULL);
					break;
				case ID_PIC_PUCAHEAD:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,PUCAHEAD(hdc),NULL);
                   break;
                case ID_PIC_PUCAHAIR:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,PUCAHAIR(hdc),NULL);
                   break;
				case ID_PIC_PUCABODY:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,PUCABODY(hdc),NULL);  
                   break;
    			case ID_PIC_PUCAARM:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,PUCAARM(hdc),NULL);
                   break;
       			case ID_PIC_PUCALEG:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,PUCALEG(hdc),NULL);
                   break;
          		case ID_PIC_PUCAGAM:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,PUCAGAM(hdc),NULL);
                   break;
            	case ID_PIC_PUCAEYE:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,PUCAEYE(hdc),NULL);
                   break;
             	case ID_PIC_PUCAEYEBROW:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,PUCAEYEBROW(hdc),NULL);
                   break;
              case ID_PIC_PUCAMOUSE:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,PUCAMOUSE(hdc),NULL);
                   break;
//---------------------------------------------------------------------------
				case ID_PIC_GARULEG:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,GARULEG(hdc),NULL);
                   break;
    			case ID_PIC_GARUBODY:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,GARUBODY(hdc),NULL);
                   break;
       			case ID_PIC_GARUARM:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,GARUARM(hdc),NULL);
                   break;
          		case ID_PIC_GARUHEAD:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,GARUHEAD(hdc),NULL);
                   break;
            	case ID_PIC_GARUEYE:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,GARUEYE(hdc),NULL);
                   break;
			}
			break;
		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd,message,wParam,lParam);
	}
	return 0;
}

#define IDR_MYMENU 101
#define IDI_MYICON 201

#define ID_FILE_EXIT 9001

#define ID_FILE_RED 9010
#define ID_FILE_GREEN 9011
#define ID_FILE_BLUE 9012
#define ID_FILE_BLACK 9013

#define ID_MESSAGE 9029

#define ID_PIC_CLR 9036
#define ID_PIC_PUCAHEAD 9031
#define ID_PIC_PUCAHAIR 9032
#define ID_PIC_PUCABODY 9033
#define ID_PIC_PUCAARM 9034
#define ID_PIC_PUCALEG 9035
#define ID_PIC_PUCAGAM 9040
#define ID_PIC_PUCAEYE 9037
#define ID_PIC_PUCAEYEBROW 9038
#define ID_PIC_PUCAMOUSE 9039

#define ID_PIC_GARULEG 9045
#define ID_PIC_GARUBODY 9041
#define ID_PIC_GARUARM 9042
#define ID_PIC_GARUHEAD 9043
#define ID_PIC_GARUEYE 9044


#include "resource.h"

IDR_MYMENU MENU
BEGIN
	POPUP "&File"
	BEGIN
		MENUITEM "E&xit",ID_FILE_EXIT
		MENUITEM "&RED",ID_FILE_RED
		MENUITEM "&GREEN",ID_FILE_BLUE
		MENUITEM "&BLUE",ID_FILE_GREEN
		MENUITEM "&BLACK",ID_FILE_BLACK

	END

END

//IDI_MYICON ICON "menu_one.ico"
