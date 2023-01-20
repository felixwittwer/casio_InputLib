/*****************************************************************/
/*                                                            					  */
/*   CASIO fx-9860G SDK Library                           			  */
/*                                                               				  */
/*   File name : [ProjectName].c                               		  */
/*                                                              				  */
/*   Copyright (c) 2006 CASIO COMPUTER CO., LTD.                  */
/*                                                               				  */
/*****************************************************************/
#include "fxlib.h"
#include "inputlib.h"
#include "math.h"


//****************************************************************************
//  AddIn_main (Sample program main function)
//
//  param   :   isAppli   : 1 = This application is launched by MAIN MENU.
//                        : 0 = This application is launched by a strip in eACT application.
//
//              OptionNum : Strip number (0~3)
//                         (This parameter is only used when isAppli parameter is 0.)
//
//  retval  :   1 = No error / 0 = Error
//
//****************************************************************************
int AddIn_main(int isAppli, unsigned short OptionNum)
{
	unsigned int key;
	float currentvalue ;

	Bdisp_AllClr_DDVRAM();
	IL_Render_F_Button(1, 58, "DEL ");
	currentvalue = 0;

	while(1){
		GetKey(&key);

		Bdisp_AllClr_DDVRAM();
		IL_Render_F_Button(1, 58, "DEL ");

		if(key==KEY_CTRL_F1){
			PopUpWin(4);
            		PrintXY(12,8, (unsigned char*)"Delete All?",0);
          			PrintXY(30,24, (unsigned char*)"Yes:[F1]",0);
            		PrintXY(30,32, (unsigned char*)"No :[F6]",0);
            		while(1){
                			GetKey(&key);
                			if(key==KEY_CTRL_F1){
                   				currentvalue = 0;
					Bdisp_AllClr_DDVRAM();
                    				break;
               			 }else if(key==KEY_CTRL_F6){
					Bdisp_AllClr_DDVRAM();
                   		 		break;
                			}
            		}
		}

		if(key == KEY_CTRL_RIGHT){
			currentvalue = currentvalue+1;
		}else if(key == KEY_CTRL_LEFT){
			currentvalue = currentvalue-1;
		}

		if(currentvalue>10){
			currentvalue = 10;
		}else if(currentvalue < 0){
			currentvalue = 0;
		}
		
		IL_Slider_Horizontal(30, 20, 40, 0, 10, currentvalue, 1, 1);
//		IL_Slider_Vertical(90, 10, 40, 0, 20, currentvalue, 1, 1);
		IL_Multi_Selection(10, 5, 6, currentvalue);		


	}

	return 1;
}




//****************************************************************************
//**************                            	        			        ****************
//**************                 Notice!                 			        ****************
//**************                                           			        ****************
//**************  Please do not change the following source.  ****************
//**************                                            				****************
//****************************************************************************


#pragma section _BR_Size
unsigned long BR_Size;
#pragma section


#pragma section _TOP

//****************************************************************************
//  InitializeSystem
//
//  param   :   isAppli   : 1 = Application / 0 = eActivity
//              OptionNum : Option Number (only eActivity)
//
//  retval  :   1 = No error / 0 = Error
//
//****************************************************************************
int InitializeSystem(int isAppli, unsigned short OptionNum)
{
    return INIT_ADDIN_APPLICATION(isAppli, OptionNum);
}

#pragma section

