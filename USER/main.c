#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "ILI93xx.h"
#include "usart.h"	 
#include "24cxx.h"
#include "flash.h"
#include "touch.h"
#include "sram.h"
#include "timer.h"
#include "malloc.h"
#include "GUI.h"
#include "DIALOG.h"
#include "ButtonUse.h"
#include "startUp.h"
#include "sys.h"
#include "delay.h"
#include "usart.h" 
#include "led.h" 		 	 
#include "lcd.h"  
#include "key.h"     
#include "usmart.h" 
#include "malloc.h"
#include "sdio_sdcard.h"  
#include "w25qxx.h"    
#include "ff.h"  
#include "exfuns.h"   
#include "text.h"	
#include "touch.h"		
#include "usart3.h"
#include "common.h" 
#include "dht11.h" 	
/************************************************
 ALIENTEKս��STM32������STemWinʵ��
 STemWin ��ֲʵ��
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

int main(void)
{	 
	delay_init();	    	//???????	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	//??NVIC????2:2??????,2??????
	uart_init(115200);	 	//??????115200
 	LED_Init();			    //LED?????
	TFTLCD_Init();			//LCD???	
	KEY_Init();	 			//?????
ctp_dev.init();		//??????
	FSMC_SRAM_Init();		//???SRAM
	TIM3_Int_Init(999,71);	//1KHZ ???1ms 
	TIM6_Int_Init(999,719);	//10ms??
	my_mem_init(SRAMIN); 		//????????
	my_mem_init(SRAMEX);  		//????????
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC,ENABLE);//??CRC??,??STemWin???? 

	GUI_Init();
	WM_SetCreateFlags(WM_CF_MEMDEV);
	
	GUI_Init();//???????? demo???????? ?????????  

  startUp_Window(); //??????
while(1);

	
}
