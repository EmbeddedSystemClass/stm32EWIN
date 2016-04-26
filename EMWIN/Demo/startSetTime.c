#include "startSetTime.h"
#include "DIALOG.h"
#include "ButtonUse.h"
#include <stdlib.h>
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0   (GUI_ID_USER + 0x00)
#define ID_DROPDOWN_0   (GUI_ID_USER + 0x01)
#define ID_DROPDOWN_1   (GUI_ID_USER + 0x02)
#define ID_DROPDOWN_2   (GUI_ID_USER + 0x03)
#define ID_BUTTON_0   (GUI_ID_USER + 0x04)
#define ID_BUTTON_1   (GUI_ID_USER + 0x05)
#define ID_TEXT_0   (GUI_ID_USER + 0x06)
#define ID_TEXT_1   (GUI_ID_USER + 0x07)
#define ID_TEXT_2   (GUI_ID_USER + 0x08)
#define ID_DROPDOWN_3   (GUI_ID_USER + 0x0B)
#define ID_DROPDOWN_4   (GUI_ID_USER + 0x0C)
#define ID_TEXT_3   (GUI_ID_USER + 0x0D)
#define ID_TEXT_4   (GUI_ID_USER + 0x0E)
#define ID_TEXT_5   (GUI_ID_USER + 0x0F)
#define ID_TEXT_6   (GUI_ID_USER + 0x10)

static int index = 0;
static int startYear = 2016;
static int startMonth = 1;
static int startDay = 1;
static int startHour = 1;
static int startMin = 1;
WM_HWIN hItem;
int Dropitem;
int in;
int getDropIndex;
int getDropIndexMonth;
int getDropIndexDay;
int getDropIndexHour;
int getDropIndexMin;
// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 800, 480, 0, 0x0, 0 },
  { DROPDOWN_CreateIndirect, "Dropdown", ID_DROPDOWN_0, 194, 47, 135, 18, 0, 0x0, 0 },
  { DROPDOWN_CreateIndirect, "Dropdown", ID_DROPDOWN_1, 194, 130, 135, 18, 0, 0x0, 0 },
  { DROPDOWN_CreateIndirect, "Dropdown", ID_DROPDOWN_2, 196, 213, 135, 18, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 509, 398, 112, 47, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_1, 650, 399, 105, 45, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_0, 24, 45, 80, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_1, 24, 131, 80, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_2, 22, 213, 80, 20, 0, 0x64, 0 },
  { DROPDOWN_CreateIndirect, "Dropdown", ID_DROPDOWN_3, 521, 47, 136, 18, 0, 0x0, 0 },
  { DROPDOWN_CreateIndirect, "Dropdown", ID_DROPDOWN_4, 521, 130, 131, 18, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_3, 401, 47, 80, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_4, 398, 133, 80, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_5, 145, 300, 395, 54, 0, 0x64, 0 },
	{ TEXT_CreateIndirect, "Text", ID_TEXT_6, 22, 400, 91, 36, 0, 0x64, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
	WM_HWIN hItem_Drop_Years;
	WM_HWIN hItem_Drop_Month;
	WM_HWIN hItem_Drop_day;
	WM_HWIN hItem_Drop_hour;
	WM_HWIN hItem_Drop_min;
  int     NCode;
  int     Id;
	char out[10];
	int i;
	char * dropString;
	int DropdownSecItemNum;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Framewin'
    //
    hItem = pMsg->hWin;
    FRAMEWIN_SetTitleVis(hItem, 0);
    //
    // Initialization of 'Dropdown'
    //
    hItem_Drop_Years = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
	  DROPDOWN_SetListHeight(hItem_Drop_Years, 100);
	  DROPDOWN_SetItemSpacing(hItem_Drop_Years,10);
	  DROPDOWN_SetAutoScroll(hItem_Drop_Years,1);
	  DROPDOWN_SetFont(hItem_Drop_Years, GUI_FONT_13B_1);
	  DROPDOWN_AddString(hItem_Drop_Years, "2016");
	  DROPDOWN_AddString(hItem_Drop_Years, "2017");
	  DROPDOWN_AddString(hItem_Drop_Years, "2018");
		DROPDOWN_AddString(hItem_Drop_Years, "2019");
		DROPDOWN_AddString(hItem_Drop_Years, "2020");
		DROPDOWN_AddString(hItem_Drop_Years, "2021");
		DROPDOWN_AddString(hItem_Drop_Years, "2022");
		DROPDOWN_AddString(hItem_Drop_Years, "2023");
		DROPDOWN_AddString(hItem_Drop_Years, "2024");
		DROPDOWN_AddString(hItem_Drop_Years, "2025");
		DROPDOWN_AddString(hItem_Drop_Years, "2026");
		DROPDOWN_AddString(hItem_Drop_Years, "2027");
		DROPDOWN_AddString(hItem_Drop_Years, "2028");
		DROPDOWN_AddString(hItem_Drop_Years, "2029");
		DROPDOWN_AddString(hItem_Drop_Years, "2030");
		DROPDOWN_SetScrollbarWidth(hItem_Drop_Years,10);

    //
    // Initialization of 'Dropdown'
    //
    hItem_Drop_Month = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_1);
		DROPDOWN_SetListHeight(hItem_Drop_Month, 100);
	  DROPDOWN_SetItemSpacing(hItem_Drop_Month,10);
	  DROPDOWN_SetAutoScroll(hItem_Drop_Month,1);
    DROPDOWN_AddString(hItem_Drop_Month, "1");
		DROPDOWN_AddString(hItem_Drop_Month, "2");
		DROPDOWN_AddString(hItem_Drop_Month, "3");
		DROPDOWN_AddString(hItem_Drop_Month, "4");
		DROPDOWN_AddString(hItem_Drop_Month, "5");
		DROPDOWN_AddString(hItem_Drop_Month, "6");
		DROPDOWN_AddString(hItem_Drop_Month, "7");
		DROPDOWN_AddString(hItem_Drop_Month, "8");
		DROPDOWN_AddString(hItem_Drop_Month, "9");
		DROPDOWN_AddString(hItem_Drop_Month, "10");
		DROPDOWN_AddString(hItem_Drop_Month, "11");
		DROPDOWN_AddString(hItem_Drop_Month, "12");
		DROPDOWN_SetScrollbarWidth(hItem_Drop_Month,10);
		
    //
    // Initialization of 'Dropdown'
    //
    hItem_Drop_day = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_2);
    DROPDOWN_SetListHeight(hItem_Drop_day, 100);
	  DROPDOWN_SetItemSpacing(hItem_Drop_day,10);
	  DROPDOWN_SetAutoScroll(hItem_Drop_day,1);
    DROPDOWN_AddString(hItem_Drop_day, "1");
		DROPDOWN_AddString(hItem_Drop_day, "2");
		DROPDOWN_AddString(hItem_Drop_day, "3");
		DROPDOWN_AddString(hItem_Drop_day, "4");
		DROPDOWN_AddString(hItem_Drop_day, "5");
		DROPDOWN_AddString(hItem_Drop_day, "6");
		DROPDOWN_AddString(hItem_Drop_day, "7");
		DROPDOWN_AddString(hItem_Drop_day, "8");
		DROPDOWN_AddString(hItem_Drop_day, "9");
		DROPDOWN_AddString(hItem_Drop_day, "10");
		DROPDOWN_AddString(hItem_Drop_day, "11");
		DROPDOWN_AddString(hItem_Drop_day, "12");
		DROPDOWN_AddString(hItem_Drop_day, "13");
		DROPDOWN_AddString(hItem_Drop_day, "14");
		DROPDOWN_AddString(hItem_Drop_day, "15");
		DROPDOWN_AddString(hItem_Drop_day, "16");
		DROPDOWN_AddString(hItem_Drop_day, "17");
		DROPDOWN_AddString(hItem_Drop_day, "18");
		DROPDOWN_AddString(hItem_Drop_day, "19");
		DROPDOWN_AddString(hItem_Drop_day, "20");
		DROPDOWN_AddString(hItem_Drop_day, "21");
		DROPDOWN_AddString(hItem_Drop_day, "22");
		DROPDOWN_AddString(hItem_Drop_day, "23");
		DROPDOWN_AddString(hItem_Drop_day, "24");
		DROPDOWN_AddString(hItem_Drop_day, "25");
		DROPDOWN_AddString(hItem_Drop_day, "26");
		DROPDOWN_AddString(hItem_Drop_day, "27");
		DROPDOWN_AddString(hItem_Drop_day, "28");
		DROPDOWN_AddString(hItem_Drop_day, "29");
		DROPDOWN_AddString(hItem_Drop_day, "30");
		DROPDOWN_AddString(hItem_Drop_day, "31");
		DROPDOWN_SetScrollbarWidth(hItem_Drop_day,10);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetText(hItem, "ok");
    BUTTON_SetFont(hItem, GUI_FONT_20_1);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
    BUTTON_SetText(hItem, "skip");
    BUTTON_SetFont(hItem, GUI_FONT_20_1);
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetFont(hItem, GUI_FONT_20_1);
    TEXT_SetText(hItem, "year");
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetText(hItem, "month");
    TEXT_SetFont(hItem, GUI_FONT_20_1);
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetFont(hItem, GUI_FONT_20_1);
    TEXT_SetText(hItem, "day");
    //
    // Initialization of 'Dropdown'
    //
    hItem_Drop_hour = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_3);
    DROPDOWN_SetListHeight(hItem_Drop_hour, 100);
	  DROPDOWN_SetItemSpacing(hItem_Drop_hour,10);
	  DROPDOWN_SetAutoScroll(hItem_Drop_hour,1);
    DROPDOWN_AddString(hItem_Drop_hour, "1");
		DROPDOWN_AddString(hItem_Drop_hour, "2");
		DROPDOWN_AddString(hItem_Drop_hour, "3");
		DROPDOWN_AddString(hItem_Drop_hour, "4");
		DROPDOWN_AddString(hItem_Drop_hour, "5");
		DROPDOWN_AddString(hItem_Drop_hour, "6");
		DROPDOWN_AddString(hItem_Drop_hour, "7");
		DROPDOWN_AddString(hItem_Drop_hour, "8");
		DROPDOWN_AddString(hItem_Drop_hour, "9");
		DROPDOWN_AddString(hItem_Drop_hour, "10");
		DROPDOWN_AddString(hItem_Drop_hour, "11");
		DROPDOWN_AddString(hItem_Drop_hour, "12");
		DROPDOWN_AddString(hItem_Drop_hour, "13");
		DROPDOWN_AddString(hItem_Drop_hour, "14");
		DROPDOWN_AddString(hItem_Drop_hour, "15");
		DROPDOWN_AddString(hItem_Drop_hour, "16");
		DROPDOWN_AddString(hItem_Drop_hour, "17");
		DROPDOWN_AddString(hItem_Drop_hour, "18");
		DROPDOWN_AddString(hItem_Drop_hour, "19");
		DROPDOWN_AddString(hItem_Drop_hour, "20");
		DROPDOWN_AddString(hItem_Drop_hour, "21");
		DROPDOWN_AddString(hItem_Drop_hour, "22");
		DROPDOWN_AddString(hItem_Drop_hour, "23");
		DROPDOWN_AddString(hItem_Drop_hour, "24");
		DROPDOWN_SetScrollbarWidth(hItem_Drop_hour,10);
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetText(hItem, "hour");
    TEXT_SetFont(hItem, GUI_FONT_20_1);
		
		
		
		
		//
		//   drop4  min
		//
		
		hItem_Drop_min = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_4);
    DROPDOWN_SetListHeight(hItem_Drop_min, 100);
	  DROPDOWN_SetItemSpacing(hItem_Drop_min,10);
	  DROPDOWN_SetAutoScroll(hItem_Drop_min,1);
    DROPDOWN_AddString(hItem_Drop_min, "1");
		DROPDOWN_AddString(hItem_Drop_min, "2");
		DROPDOWN_AddString(hItem_Drop_min, "3");
		DROPDOWN_AddString(hItem_Drop_min, "4");
		DROPDOWN_AddString(hItem_Drop_min, "5");
		DROPDOWN_AddString(hItem_Drop_min, "6");
		DROPDOWN_AddString(hItem_Drop_min, "7");
		DROPDOWN_AddString(hItem_Drop_min, "8");
		DROPDOWN_AddString(hItem_Drop_min, "9");
		DROPDOWN_AddString(hItem_Drop_min, "10");
		DROPDOWN_AddString(hItem_Drop_min, "11");
		DROPDOWN_AddString(hItem_Drop_min, "12");
		DROPDOWN_AddString(hItem_Drop_min, "13");
		DROPDOWN_AddString(hItem_Drop_min, "14");
		DROPDOWN_AddString(hItem_Drop_min, "15");
		DROPDOWN_AddString(hItem_Drop_min, "16");
		DROPDOWN_AddString(hItem_Drop_min, "17");
		DROPDOWN_AddString(hItem_Drop_min, "18");
		DROPDOWN_AddString(hItem_Drop_min, "19");
		DROPDOWN_AddString(hItem_Drop_min, "20");
		DROPDOWN_AddString(hItem_Drop_min, "21");
		DROPDOWN_AddString(hItem_Drop_min, "22");
		DROPDOWN_AddString(hItem_Drop_min, "23");
		DROPDOWN_AddString(hItem_Drop_min, "24");
    DROPDOWN_AddString(hItem_Drop_min, "25");
		DROPDOWN_AddString(hItem_Drop_min, "26");
		DROPDOWN_AddString(hItem_Drop_min, "27");
		DROPDOWN_AddString(hItem_Drop_min, "28");
		DROPDOWN_AddString(hItem_Drop_min, "29");
		DROPDOWN_AddString(hItem_Drop_min, "30");
		DROPDOWN_AddString(hItem_Drop_min, "31");
		DROPDOWN_AddString(hItem_Drop_min, "32");
		DROPDOWN_AddString(hItem_Drop_min, "33");
		DROPDOWN_AddString(hItem_Drop_min, "34");
		DROPDOWN_AddString(hItem_Drop_min, "35");
		DROPDOWN_AddString(hItem_Drop_min, "36");
		DROPDOWN_AddString(hItem_Drop_min, "37");
		DROPDOWN_AddString(hItem_Drop_min, "38");
		DROPDOWN_AddString(hItem_Drop_min, "39");
		DROPDOWN_AddString(hItem_Drop_min, "40");
		DROPDOWN_AddString(hItem_Drop_min, "41");
		DROPDOWN_AddString(hItem_Drop_min, "42");
		DROPDOWN_AddString(hItem_Drop_min, "43");
		DROPDOWN_AddString(hItem_Drop_min, "44");
		DROPDOWN_AddString(hItem_Drop_min, "45");
		DROPDOWN_AddString(hItem_Drop_min, "46");
		DROPDOWN_AddString(hItem_Drop_min, "47");
		DROPDOWN_AddString(hItem_Drop_min, "48");
    DROPDOWN_AddString(hItem_Drop_min, "49");
		DROPDOWN_AddString(hItem_Drop_min, "50");
		DROPDOWN_AddString(hItem_Drop_min, "51");
		DROPDOWN_AddString(hItem_Drop_min, "52");
		DROPDOWN_AddString(hItem_Drop_min, "53");
		DROPDOWN_AddString(hItem_Drop_min, "54");
		DROPDOWN_AddString(hItem_Drop_min, "55");
		DROPDOWN_AddString(hItem_Drop_min, "56");
		DROPDOWN_AddString(hItem_Drop_min, "57");
		DROPDOWN_AddString(hItem_Drop_min, "58");
		DROPDOWN_AddString(hItem_Drop_min, "59");
		DROPDOWN_AddString(hItem_Drop_min, "60");
		DROPDOWN_SetScrollbarWidth(hItem_Drop_min,10);
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetText(hItem, "min");
    TEXT_SetFont(hItem, GUI_FONT_20_1);
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_5);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetFont(hItem, GUI_FONT_16B_ASCII);
    TEXT_SetText(hItem, "please set current time");
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_DROPDOWN_0: // Notifications sent by 'Dropdown'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:

        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:

				//hItemIndex = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
				//in = getDropIndex;
//			  Dropitem =  DROPDOWN_GetItemText(hItem,getDropIndex,"123",3);
//			  in = Dropitem;
						 //hItemIndex = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
			 // sprintf(out, " %d" , in);
//			  DROPDOWN_AddString(hItem,out);

			
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:

        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_DROPDOWN_1: // Notifications sent by 'Dropdown'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
				
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:

        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_DROPDOWN_2: // Notifications sent by 'Dropdown'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_0: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
				hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
				getDropIndex = DROPDOWN_GetSel(hItem);  //获取当前选择的下表
			  getDropIndex = getDropIndex + startYear;
			  hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_6);
				TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
				TEXT_SetFont(hItem, GUI_FONT_20_1);
			  sprintf(out," %d",getDropIndex);
				TEXT_SetText(hItem, out);
			
				hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_1);
				getDropIndexMonth = DROPDOWN_GetSel(hItem);
			  getDropIndexMonth = getDropIndexMonth + startMonth;
			
				hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_2);
				getDropIndexDay = DROPDOWN_GetSel(hItem);
			  getDropIndexDay = getDropIndexDay + startDay;
	
				hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_3);
				getDropIndexHour = DROPDOWN_GetSel(hItem);
			  getDropIndexHour = getDropIndexHour + startHour;		

				hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_4);
				getDropIndexMin = DROPDOWN_GetSel(hItem);
			  getDropIndexMin = getDropIndexMin + startMin;	
				
				
			  //Dropitem =  DROPDOWN_GetItemText(hItem,getDropIndex,"123",3);
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
				//index = 1;                //index为1时，删除界面
			
			
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
				index = 1;
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_DROPDOWN_3: // Notifications sent by 'Dropdown'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
				
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_DROPDOWN_4: // Notifications sent by 'Dropdown'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateFramewin
*/

//int getDropIndex;
//int getDropIndexMonth;
//int getDropIndexDay;
//int getDropIndexHour;
//int getDropIndexMin;

u8 getYear() {
	return (u8)getDropIndex;
}

u8 getMonth() {
  return (u8)getDropIndexMonth;
}

u8 getDay () {
  return (u8)getDropIndexDay;
}

u8 getHour () {
  return (u8)getDropIndexHour;
}

u8 getMin() {
  return (u8)getDropIndexMin;
}


WM_HWIN startSetTime(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}


void startSetTime_Window(void) {
	WM_HWIN hWin = startSetTime();
	while(1)
	{
		GUI_Delay(100);
		if (index == 1) {
			FRAMEWIN_Delete(hWin);
			ButtonUse_Demo();
			break;
		}
	}
	
}
// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
