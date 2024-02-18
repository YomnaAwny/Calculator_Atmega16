/*
 * main.c
 *
 *  Created on: Dec 9, 2023
 *      Author: Yomna Awny
 */

#include "lcd.h"
#include "keypad.h"

int main(void)
{
	unsigned char key,i=0,n,flag=0;
	int result[2]={0};
	LCD_init();
	LCD_goToRowColumn(0,0);
    while(1)
    {

		key = KeyPad_getPressedKey();
		if((key <= 9) && (key >= 0))
		{

			LCD_intgerToString(key);
			if(flag==0){
			result[i]+=key;
			flag=1;
			}

			else{result[i]*=10;
			result[i]+=key;}

			key = KeyPad_getPressedKey();
		}
		else if(key=='='){
			i=0;
			flag=0;
			switch (n)
						{case 1:
							result[i]+=result[i+1];
						   break;
						case 2:
							result[i]-=result[i+1];
							break;
						case 3:
							result[i]*=result[i+1];
							 break;
						case 4:
							result[i]/=result[i+1];
							break;}

			LCD_goToRowColumn(1,0);
			LCD_intgerToString(result[i]);
			result[0]=0;
			result[1]=0;
		}
		else if(key==13){LCD_clearScreen();}
		else
		{
			flag=0;
			i++;
			LCD_displayCharacter(key);
			switch (key)
			{case '+':
				n=1;
			   break;
			case '-':
				n=2;
				break;
			case '*':
				n=3;
				 break;
			case '%':
				n=4;
				break;}
		}
		_delay_ms(500);
    }
}

