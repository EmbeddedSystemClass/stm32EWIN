#include "startUp.h"
#include "DIALOG.h"
#include "ButtonUse.h"
#include "startSetTime.h"


#define ID_FRAMEWIN_0   (GUI_ID_USER + 0x00)
#define ID_TEXT_0   (GUI_ID_USER + 0x01)
#define ID_TEXT_1   (GUI_ID_USER + 0x02)
#define ID_TEXT_2   (GUI_ID_USER + 0x03)
#define ID_TEXT_3   (GUI_ID_USER + 0x04)



static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 800, 480, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_0, 240, 74, 279, 38, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_1, 298, 136, 152, 33, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_2, 309, 312, 142, 36, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_3, 335, 364, 81, 34, 0, 0x64, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};


static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:

    hItem = pMsg->hWin;
    FRAMEWIN_SetText(hItem, "welcome");
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetTitleVis(hItem, 0);
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetFont(hItem, GUI_FONT_20B_1);
    TEXT_SetTextColor(hItem, 0x000000FF);
    TEXT_SetText(hItem, "welcome to use our system");
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetFont(hItem, GUI_FONT_16B_1);
    TEXT_SetTextColor(hItem, 0x008000FF);
    TEXT_SetText(hItem, "The elderly assistant");
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetText(hItem, "Just a moment, please. ");
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
    TEXT_SetText(hItem, "second");
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}



WM_HWIN CreateFramewin_startUp(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

void startUp_Window(void) {

	WM_HWIN hWin  = CreateFramewin_startUp();
	GUI_Delay(5000);
	FRAMEWIN_Delete(hWin);
	startSetTime_Window();
	//char *second = "123";
}




