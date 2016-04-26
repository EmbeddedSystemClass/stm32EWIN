#include "DIALOG.h"
#include "ButtonUse.h"
#include "TakeMedicine.h"
#include "FramewinDLG.h"
#include "Environment.h"
#include "HouseKeeping.h"
#include "ActivityParticipation.h"
#include "InformationBak.h"
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
#define ID_FRAMEWIN_1 (GUI_ID_USER + 0x0B) //按钮控件生成的窗口
#define ID_BUTTON_0 (GUI_ID_USER + 0x01) //吃药提醒
#define ID_BUTTON_1 (GUI_ID_USER + 0x02) //环境监测
#define ID_BUTTON_2 (GUI_ID_USER + 0x03) //及时语音播报
#define ID_BUTTON_3 (GUI_ID_USER + 0x04) //个性化居住地语音播报
#define ID_BUTTON_4 (GUI_ID_USER + 0x05) //家政预约
#define ID_BUTTON_5 (GUI_ID_USER + 0x06) //信息反馈
#define ID_BUTTON_6 (GUI_ID_USER + 0x07) //一键报警
#define ID_BUTTON_7 (GUI_ID_USER + 0x08) //活动参与
#define ID_BUTTON_8 (GUI_ID_USER + 0x09) //语音识别
#define ID_BUTTON_9 (GUI_ID_USER + 0x0A) //远程设置
 
static	WM_HWIN hWin;

//对话框资源表
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = 
{
	{ FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 800, 480, 0, 0x64, 0 }, //第4，5，6，7是x,y坐标,宽度、高度
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 72, 80, 100, 80, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_1, 72*3, 80, 100, 80, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_2, 72*5, 80, 100, 80, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_3, 72*7, 80, 100, 80, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_4, 72*9, 80, 100, 80, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_5, 72, 80*4, 100, 80, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_6, 72*3, 80*4, 100, 80, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_7, 72*5, 80*4, 100, 80, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_8, 72*7, 80*4, 100, 80, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_9, 72*9, 80*4, 100, 80, 0, 0x0, 0 },
};

//对话框回调函数
static void _cbDialog(WM_MESSAGE * pMsg) 
{
	WM_HWIN hItem;
	int     NCode;
	int     Id;

	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			//初始化对话框
			hItem = pMsg->hWin;
			FRAMEWIN_SetTitleHeight(hItem, 30);
			FRAMEWIN_SetText(hItem, "old man helper");
			FRAMEWIN_SetFont(hItem, GUI_FONT_24_ASCII);
			FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
			FRAMEWIN_SetTextColor(hItem, 0x0000FFFF);
		
			//初始化BUTTON0
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);
			BUTTON_SetText(hItem, "medicine");
			
			//初始化BUTTON1
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
			BUTTON_SetText(hItem, "Environment");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//初始化BUTTON2
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
			BUTTON_SetText(hItem, "VBIT");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//初始化BUTTON3
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
			BUTTON_SetText(hItem, "PVB");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//初始化BUTTON4
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
			BUTTON_SetText(hItem, "Domestic");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//初始化BUTTON5
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);
			BUTTON_SetText(hItem, "feedback");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//初始化BUTTON6
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6);
			BUTTON_SetText(hItem, "OKA");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//初始化BUTTON7
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_7);
			BUTTON_SetText(hItem, "AP");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//初始化BUTTON8
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_8);
			BUTTON_SetText(hItem, "SR");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//初始化BUTTON9
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_9);
			BUTTON_SetText(hItem, "Remote");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);
			
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
						  TakeMedicine_Window();
							//BEEP=~BEEP;
							break;	
					}
					break;

				case ID_BUTTON_1: //BUTTON_1的通知代码
					switch(NCode) 
					{
						case WM_NOTIFICATION_CLICKED:
							break;
						case WM_NOTIFICATION_RELEASED:
							environment_Window();
						
							//LED1=~LED1;
							break;
					}
					break;

				case ID_BUTTON_2: //BUTTON_2的通知代码
					switch(NCode) 
					{
						case WM_NOTIFICATION_CLICKED:
							break;
						case WM_NOTIFICATION_RELEASED:
							TakeMedicine_Demo(2);
							//LED1=~LED1;
							break;
					}
					break;

				case ID_BUTTON_3: //BUTTON_3的通知代码
					switch(NCode) 
					{
						case WM_NOTIFICATION_CLICKED:
							break;
						case WM_NOTIFICATION_RELEASED:
					
								TakeMedicine_Demo(3);
							//LED1=~LED1;
							break;
					}
					break;

				case ID_BUTTON_4: //BUTTON_4的通知代码
					switch(NCode) 
					{
						case WM_NOTIFICATION_CLICKED:
							break;
						case WM_NOTIFICATION_RELEASED:
						
							Housekeeping_Window();
							//LED1=~LED1;
							break;
					}
					break;

				case ID_BUTTON_5: //BUTTON_5的通知代码
					switch(NCode) 
					{
						case WM_NOTIFICATION_CLICKED:
							break;
						case WM_NOTIFICATION_RELEASED:
								InfomationBak_Window();
							//LED1=~LED1;
							break;
					}
					break;

				case ID_BUTTON_6: //BUTTON_6的通知代码
					switch(NCode) 
					{
						case WM_NOTIFICATION_CLICKED:
							break;
						case WM_NOTIFICATION_RELEASED:
								TakeMedicine_Demo(6);
							//LED1=~LED1;
							break;
					}
					break;

				case ID_BUTTON_7: //BUTTON_7的通知代码
					switch(NCode) 
					{
						case WM_NOTIFICATION_CLICKED:
							break;
						case WM_NOTIFICATION_RELEASED:
							Activity_Window();
							//LED1=~LED1;
							break;
					}
					break;

				case ID_BUTTON_8: //BUTTON_8的通知代码
					switch(NCode) 
					{
						case WM_NOTIFICATION_CLICKED:
							break;
						case WM_NOTIFICATION_RELEASED:
							TakeMedicine_Demo(8);
							//LED1=~LED1;
							break;
					}
					break;

				case ID_BUTTON_9: //BUTTON_9的通知代码
					switch(NCode) 
					{
						case WM_NOTIFICATION_CLICKED:
							break;
						case WM_NOTIFICATION_RELEASED:
								TakeMedicine_Demo(9);
							//LED1=~LED1;
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
WM_HWIN CreateFramewinMain(void) 
{
	WM_HWIN hWin;
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

//BUTTO演示函数
void ButtonUse_Demo(void)
{

	hWin=CreateFramewinMain();
	while(1)
	{
		GUI_Delay(100);
	}
}






