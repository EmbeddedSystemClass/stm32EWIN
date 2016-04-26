#include "DIALOG.h"
#include "TakeMedicine.h"
#include "FRAMEWIN.h"
#include "GUI.h"
#include "led.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F103战舰开发板
//STemWin BUTTON使用
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2015/4/10
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x00) //主窗口
#define ID_BUTTON_0 (GUI_ID_USER + 0x01) 
 

static	WM_HWIN hWin1; //静态全局窗口指示符
static int index = 0 ;
static GUI_RECT Rect	={72,200,100,50};	//定义矩形显示区域 label
static char acText[] = {""};
//对话框资源表
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = 
{
	{ FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 800, 480, 0, 0x64, 0 }, //第4，5，6，7是x,y坐标,宽度、高度
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 72, 80, 100, 80, 0, 0x0, 0 },
};


//对话框回调函数
static void _cbDialog(WM_MESSAGE * pMsg) 
{
	WM_HWIN hItem;
	WM_HWIN Button;
	int     NCode;
	int     Id;

	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			//初始化对话框
			hItem = pMsg->hWin;
			FRAMEWIN_SetTitleHeight(hItem, 30);
			FRAMEWIN_SetFont(hItem, GUI_FONT_24_ASCII);
			FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
			FRAMEWIN_SetTextColor(hItem, 0x0000FFFF);
			Button = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
	switch(index) {
		case 0:
					FRAMEWIN_SetText(hItem, "take medicine");
					BUTTON_SetText(Button, "medicine");
					GUI_SetFont(&GUI_Font24_ASCII);
					GUI_SetTextMode(GUI_TM_NORMAL);	//正常模式
					GUI_SetColor(GUI_BLACK);
					GUI_DispStringInRect("Timing",&Rect,GUI_TA_LEFT);
			break;
		case 1:
					FRAMEWIN_SetText(hItem, "Environmental monitoring");
					BUTTON_SetText(Button, "monitoring");
			break;
		case 2:
					FRAMEWIN_SetText(hItem, "Voice broadcast in time");
					BUTTON_SetText(Button, "broadcast");
			break;
		case 3:
					FRAMEWIN_SetText(hItem, "Personalized voice broadcast");
					BUTTON_SetText(Button, "Personalized");
			break;
		case 4:
					FRAMEWIN_SetText(hItem, "Domestic reservation");
					BUTTON_SetText(Button, "Domestic");
			break;
		case 5:
				  FRAMEWIN_SetText(hItem, "Information feedback");
					BUTTON_SetText(Button, "feedback");
			break;
		case 6:
					FRAMEWIN_SetText(hItem, "One key alarm");
					BUTTON_SetText(Button, "alarm");
			break;
		case 7:
				  FRAMEWIN_SetText(hItem, "Activity participation");
					BUTTON_SetText(Button, "participation");
			break;
		case 8:
					FRAMEWIN_SetText(hItem, "Speech recognition");
					BUTTON_SetText(Button, "recognition");
			break;
		case 9:
					FRAMEWIN_SetText(hItem, "Remote setup");
					BUTTON_SetText(Button, "Remote setup");
			break;
	}		
			

			//初始化BUTTON0
			BUTTON_SetFont(Button, GUI_FONT_24_ASCII);
			
			break;

		case WM_NOTIFY_PARENT:
			Id    = WM_GetId(pMsg->hWinSrc);
			NCode = pMsg->Data.v;
			switch(Id) 
			{
				case ID_BUTTON_0: //BUTTON_0的通知代码
					switch(NCode) 
					{
						case WM_NOTIFICATION_CLICKED:
							break;
						case WM_NOTIFICATION_RELEASED: //按钮被按下并释放
							FRAMEWIN_Delete(hWin1);
							break;
					}
					break;
			}
			break;
		default:
			WM_DefaultProc(pMsg);
		  LED1=~LED1;
			break;
	}
}

//创建一个对话框
WM_HWIN CreateFramewin_Medicine(int i) 
{
	WM_HWIN hWin;

	switch(i) {
		case 0:
					hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, 0, 0, 0);

			break;
		case 1:
				 hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, 0, 0, 0);
			break;
		case 2:
				 hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, 0, 0, 0);
			break;
		case 3:
				 hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, 0, 0, 0);
			break;
		case 4:
				 hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, 0, 0, 0);
			break;
		case 5:
				 hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, 0, 0, 0);
			break;
		case 6:
				 hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, 0, 0, 0);
			break;
		case 7:
				 hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, 0, 0, 0);
			break;
		case 8:
			 hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, 0, 0, 0);
			break;
		case 9:
			hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, 0, 0, 0);
			break;
	}
	

	 return hWin;
}


//BUTTO演示函数
void TakeMedicine_Demo(int i)
{
		index = i;
		hWin1=CreateFramewin_Medicine(index);
	
//		while(1)   这里的while循环不能要，否则切换界面过程中会死机
//	{
//		GUI_Delay(100);
//	}
}

