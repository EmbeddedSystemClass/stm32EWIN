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
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F103ս��������
//STemWin BUTTONʹ��
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2015/4/10
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x00) //������
#define ID_FRAMEWIN_1 (GUI_ID_USER + 0x0B) //��ť�ؼ����ɵĴ���
#define ID_BUTTON_0 (GUI_ID_USER + 0x01) //��ҩ����
#define ID_BUTTON_1 (GUI_ID_USER + 0x02) //�������
#define ID_BUTTON_2 (GUI_ID_USER + 0x03) //��ʱ��������
#define ID_BUTTON_3 (GUI_ID_USER + 0x04) //���Ի���ס����������
#define ID_BUTTON_4 (GUI_ID_USER + 0x05) //����ԤԼ
#define ID_BUTTON_5 (GUI_ID_USER + 0x06) //��Ϣ����
#define ID_BUTTON_6 (GUI_ID_USER + 0x07) //һ������
#define ID_BUTTON_7 (GUI_ID_USER + 0x08) //�����
#define ID_BUTTON_8 (GUI_ID_USER + 0x09) //����ʶ��
#define ID_BUTTON_9 (GUI_ID_USER + 0x0A) //Զ������
 
static	WM_HWIN hWin;

//�Ի�����Դ��
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = 
{
	{ FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 800, 480, 0, 0x64, 0 }, //��4��5��6��7��x,y����,��ȡ��߶�
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

//�Ի���ص�����
static void _cbDialog(WM_MESSAGE * pMsg) 
{
	WM_HWIN hItem;
	int     NCode;
	int     Id;

	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			//��ʼ���Ի���
			hItem = pMsg->hWin;
			FRAMEWIN_SetTitleHeight(hItem, 30);
			FRAMEWIN_SetText(hItem, "old man helper");
			FRAMEWIN_SetFont(hItem, GUI_FONT_24_ASCII);
			FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
			FRAMEWIN_SetTextColor(hItem, 0x0000FFFF);
		
			//��ʼ��BUTTON0
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);
			BUTTON_SetText(hItem, "medicine");
			
			//��ʼ��BUTTON1
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
			BUTTON_SetText(hItem, "Environment");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//��ʼ��BUTTON2
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
			BUTTON_SetText(hItem, "VBIT");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//��ʼ��BUTTON3
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
			BUTTON_SetText(hItem, "PVB");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//��ʼ��BUTTON4
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
			BUTTON_SetText(hItem, "Domestic");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//��ʼ��BUTTON5
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);
			BUTTON_SetText(hItem, "feedback");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//��ʼ��BUTTON6
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6);
			BUTTON_SetText(hItem, "OKA");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//��ʼ��BUTTON7
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_7);
			BUTTON_SetText(hItem, "AP");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//��ʼ��BUTTON8
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_8);
			BUTTON_SetText(hItem, "SR");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

			//��ʼ��BUTTON9
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_9);
			BUTTON_SetText(hItem, "Remote");
			BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);
			
			break;

		case WM_NOTIFY_PARENT:
			Id    = WM_GetId(pMsg->hWinSrc);
			NCode = pMsg->Data.v;
			switch(Id) 
			{
				case ID_BUTTON_0: //BUTTON_0��֪ͨ����
					switch(NCode) 
					{
						case WM_NOTIFICATION_CLICKED:
							break;
						case WM_NOTIFICATION_RELEASED: //��ť�����²��ͷ�
						  TakeMedicine_Window();
							//BEEP=~BEEP;
							break;	
					}
					break;

				case ID_BUTTON_1: //BUTTON_1��֪ͨ����
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

				case ID_BUTTON_2: //BUTTON_2��֪ͨ����
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

				case ID_BUTTON_3: //BUTTON_3��֪ͨ����
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

				case ID_BUTTON_4: //BUTTON_4��֪ͨ����
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

				case ID_BUTTON_5: //BUTTON_5��֪ͨ����
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

				case ID_BUTTON_6: //BUTTON_6��֪ͨ����
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

				case ID_BUTTON_7: //BUTTON_7��֪ͨ����
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

				case ID_BUTTON_8: //BUTTON_8��֪ͨ����
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

				case ID_BUTTON_9: //BUTTON_9��֪ͨ����
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

//����һ���Ի���
WM_HWIN CreateFramewinMain(void) 
{
	WM_HWIN hWin;
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

//BUTTO��ʾ����
void ButtonUse_Demo(void)
{

	hWin=CreateFramewinMain();
	while(1)
	{
		GUI_Delay(100);
	}
}






