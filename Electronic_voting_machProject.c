/*
 * Electronic_voting_machProject.c
 *
 * Created: 9/15/2023 9:16:17 PM
 *  Author: mahmo
 */ 


#include "LCD.h"
#include "Button.h"

int main(void)
{
	LCD_Init();
	Button_Init('b',3);
	Button_Init('b',4);
	Button_Init('b',5);
	Button_Init('b',6);
	Button_Init('b',7);
	unsigned char ctr1=0,ctr2=0,ctr3=0,ctr4=0;

	LCD_send_string("A=00");
	LCD_move_cursor(1,9);
	LCD_send_string("B=00");
	LCD_move_cursor(2,1);
	LCD_send_string("C=00");
	LCD_move_cursor(2,9);
	LCD_send_string("D=00");
	
    while(1)
    {
       if(Button_readStatus('B',3)==1)
	   {
		   ctr1++;
		   	LCD_move_cursor(1,4);
		   	LCD_sendChar(ctr1%10 + 48);//ones
		   	LCD_move_cursor(1,3);
		   	LCD_sendChar(ctr1/10 + 48);//tenth
		   while(Button_readStatus('B',3)==1);
	   }
	   else if (Button_readStatus('B',4)==1)
	   {
		   ctr2++;
	   		LCD_move_cursor(1,12);
	   		LCD_sendChar(ctr2%10 + 48);
	   		LCD_move_cursor(1,11);
	   		LCD_sendChar(ctr2/10 + 48);			   
		   while(Button_readStatus('B',4)==1);
	   }
	   else if (Button_readStatus('B',5)==1)
	   {
		   ctr3++;
	   		LCD_move_cursor(2,4);
	   		LCD_sendChar(ctr3%10 + 48);
	   		LCD_move_cursor(2,3);
	   		LCD_sendChar(ctr3/10 + 48);			   
		   while(Button_readStatus('B',5)==1);
	   }
	   else if (Button_readStatus('B',6)==1)
	   {
		   ctr4++;
		   LCD_move_cursor(2,12);
		   LCD_sendChar(ctr4%10 + 48);
		   LCD_move_cursor(2,11);
		   LCD_sendChar(ctr4/10 + 48);
		   while(Button_readStatus('B',6)==1);
	   }
	   else if(Button_readStatus('B',7)==1)
	   {
		   ctr1=0; ctr2=0; ctr3=0; ctr4=0;
		   	LCD_send_string("A=00");
		   	LCD_move_cursor(1,9);
		   	LCD_send_string("B=00");
		   	LCD_move_cursor(2,1);
		   	LCD_send_string("C=00");
		   	LCD_move_cursor(2,9);
		   	LCD_send_string("D=00");
		   while(Button_readStatus('B',7)==1);
	   }
    }
}