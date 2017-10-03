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
void Marker(LONG x,LONG y,int Index,HWND hWnd);  // pan insert function void marker
int HIndex = 1;
char H[120]={0};

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
//
//FUNCTION: MyRegisterClass()
//
// PURPOSE: Registers the window class.
//
//COMMENTS:
//
//This function and its usage is only necessary if you want this code
//to be commpatible with Win32 systems prior to the 'RegisterClassEx'
//function that was added to Windows 95.
// 
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
//
//FUNCTION: Initlnstance(HANDLE, int)
//
//PURPOSE: Saves instance handle and creates main window
//
//COMMENTS:
//
//	In this function, we save this instance handle in a global variable and
// 	create and display the main program window.
//
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
//
// PURPOSE: Processes messages for the main window.
//
// WM_COMMAND	-process the application menu
// WM_PAINT		-Paint the main window
// WM_DESTROY	-post a quit message and return
//
//
EMOJI1(HDC hdc)
{   SelectObject(hdc,CreateSolidBrush(RGB(255,232,0))); 	
	Ellipse (hdc, 75, 75, 275, 275);
    SelectObject(hdc,CreateSolidBrush(RGB(0,0,0))); //eye//	
	Ellipse (hdc, 100, 90, 175, 180);
	Ellipse (hdc, 175, 90, 250, 180);
	SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
	Ellipse (hdc, 130, 120, 145, 150);
	Ellipse (hdc, 205, 120, 220, 150);
	SelectObject(hdc,CreateSolidBrush(RGB(232,22,0)));
	 Chord(hdc,100,180,250,250,20,260,430,250);	
	
	
}



LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,
LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rt;
	char szHello[]="Hello,C-Free";
	
	switch(message)
	{
		case WM_PAINT:
			hdc = BeginPaint(hWnd,&ps);
			// TODO: Add any drawing code here...
			
			GetClientRect(hWnd,&rt);
			DrawText(hdc,szHello,strlen(szHello),&rt,DT_CENTER);
			//pan insert choice7
			Marker(50,50,Index,hWnd); 
			//
			EndPaint(hWnd,&ps);
			break;
		// pan insert choice 9
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
		case WM_CHAR:
			hdc=GetDC(hWnd);
			H[HIndex]=(TCHAR)wParam;
			HIndex++;
			TextOut(hdc,120,120,H,60);
			ReleaseDC(hWnd, hdc);
			break;
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
				case ID_FILE_SAVEAS:
						Index = 0;
					break;
				case ID_FILE_OPEN:
						Index = 1;
					break;
				case ID_FILE_CLOSE:
						Index = 2;
					break;
				case ID_FILE_INFO:
						Index = 3;
					break;
				case ID_FILE_RECENT:
					break;	
				case ID_FILE_NEW:
					break;
				case ID_FILE_PRINT:
					break;
				case ID_FILE_SAVEANDSEND:
					break;
				case ID_FILE_HELP:
					break;
				case ID_FILE_OPTIONS:
					break;
					
				case ID_EDIT_PATE:
					break;
				case ID_EDIT_CUT:
					break;
				case ID_EDIT_COPY:
					break;
				case ID_EDIT_UNDO:
					break;
				case ID_EDIT_REPEAT:
					break;
				case ID_EDIT_OFFICECLIPBOARD:
					break;
				case ID_EDIT_CLEAR:
					break;
				case ID_EDIT_SELECTALL:
					break;
				case ID_EDIT_FIND:
					break;
					
				case ID_PIC_EMO1:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,EMOJI1(hdc),NULL);
                   
                   
//			        SendMessage(hWnd,WM_PAINT,Ellipse (hdc, 75, 75, 275, 275),NULL);
//                    SendMessage(hWnd,WM_PAINT,Ellipse (hdc, 100, 90, 175, 180),NULL);  //eye//
//			     	SendMessage(hWnd,WM_PAINT,Ellipse (hdc, 175, 90, 250, 180),NULL);  //eye//
					 ReleaseDC(hWnd,hdc);
					 
					 
					 break;

					
					
			}
			break;
		//
		//case WM_KEYDOWN: 
            	//switch (wParam) 
            //	{ 
                //	case VK_LEFT: 
                    
                    // Process the LEFT ARROW key. 
                    
                   // if(Index<4)
                   // {
                    //	Index++;
                    //}else
                   // {
                    //	Index=0;
                   // }
	//	InvalidateRect(hWnd, NULL, TRUE); 
               // default:     
                    //break; 
           // }
          //  break;

		
			//TODO:Add any drawing
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

void Marker(LONG x,LONG y,HWND hWnd)
{
	HDC hdc;
		HPEN hPen;
	hdc = GetDC(hWnd);
	hPen = CreatePen(PS_DOT,1,RGB(255,0,0));
	
 SelectObject(hdc,hPen);
 MoveToEx(hdc,(int)x-10,(int)y,(LPPOINT)NULL);
 LineTo(hdc,(int)x+10,(int)y);
 MoveToEx(hdc,(int)x,(int)y-10,(LPPOINT)NULL);
 LineTo(hdc,(int)x,(int)y+10);
 
 	DeleteObject(hPen);
  ReleaseDC(hWnd,hdc);
}

void Marker(LONG x,LONG y,int Index, HWND hWnd)
{
	HDC hdc;
		HPEN hPen;
	hdc = GetDC(hWnd);
		hPen = CreatePen(PS_DOT,5,Color[Index]);
		
	SelectObject(hdc,hPen);
	MoveToEx(hdc,(int)x-10,(int)y,(LPPOINT)NULL);
	LineTo(hdc,(int)x+10,(int)y); 
    MoveToEx(hdc,(int)x,(int)y-10,(LPPOINT)NULL); 
    LineTo(hdc, (int)x,(int)y+10); 

		DeleteObject(hPen);
    ReleaseDC(hWnd, hdc); 
} 

