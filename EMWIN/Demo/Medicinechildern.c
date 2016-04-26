#include "Medicinechildern.h"

#define ID_BUTTON_2 (GUI_ID_USER + 0x17)
#define ID_FRAMEWIN_1   (GUI_ID_USER + 0x04)

static WM_HWIN hWin_childern;

static const GUI_WIDGET_CREATE_INFO _aChildernDialogCreate[] = {
	{ FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_1, 200, 200, 220, 150, 0, 0x64, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_2, 80, 60, 50, 30, 0, 0x0, 0 },
};

static void _cbChildernDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
	int     NCode;
  int     Id;

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    hItem = pMsg->hWin;
		FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		FRAMEWIN_SetText(hItem,"Prompt");

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
		BUTTON_SetFont(hItem, GUI_FONT_13B_1);
    BUTTON_SetText(hItem, "ok");
   break;
	
	
	case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_2:
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
				FRAMEWIN_Delete(hWin_childern);
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
		}
		break;
			
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

WM_HWIN CreateFramewin_chlidern(void) {
  WM_HWIN hWin;
  hWin = GUI_CreateDialogBox(_aChildernDialogCreate, GUI_COUNTOF(_aChildernDialogCreate), _cbChildernDialog, WM_HBKWIN, 0, 0);
  return hWin;
}


void Medicine_Childer_Window(void) {

	hWin_childern = CreateFramewin_chlidern();
}
