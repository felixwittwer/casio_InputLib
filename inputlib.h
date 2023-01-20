/*************************************************************/
/** inputlib.h - input library for fx-9860GII and GIII      **/
/** inputlib.h is free software to use                      **/
/**                                                         **/
/** @author Felix Wittwer                                   **/
/**                                                         **/
/** @file InputLib.c                                        **/
/**                                                         **/
/** @date 01-20-2023                                        **/
/*************************************************************/

#include <stdio.h>
#include <math.h>
#include "fxlib.h"

void IL_Test(int x, int y)
{
    PrintXY(x,y,(unsigned char*)"Test",0);
}

void IL_Print_Float(int x, int y, float f)
{
    unsigned char buffer[9];
    sprintf(buffer, "%f", f);
    PrintXY(x,y,buffer,0);
}

void IL_Render_F_Button(int x, int y, unsigned char *str){
    // Maximum of four characters or three + space
    // Render_F_Button(1,58, "F 1 ");
    // Render_F_Button(23,58, "F 2 ");
    // Render_F_Button(45,58, "F 3 ");
    // Render_F_Button(67,58, "F 4 ");
    // Render_F_Button(89,58, "F 5 ");
    Bdisp_DrawLineVRAM(x, y-1, x+17, y-1);
    Bdisp_DrawLineVRAM(x-1, y-1, x-1, y+5);
    Bdisp_DrawLineVRAM(x+17, y-1, x+17, y+5);
    Bdisp_DrawLineVRAM(x+16, y-1, x+16, y+5);
    PrintMini(x,y, str, MINI_REV);

    Bdisp_ClearLineVRAM(x+17, y+4, x+15, y+6);
    Bdisp_ClearLineVRAM(x+17, y+5, x+16, y+6);
    Bdisp_SetPoint_VRAM(x+17, y+6, 0);
}

void IL_Slider_Horizontal(int x, int y, int length, int min, int max, float currentvalue, int displayvalue, int render)
{
    int sliderrange;
    float unit;
    int sliderx;

    // if(currentvalue > max){
    //     currentvalue = max;
    // }else if(currentvalue < min){
    //     currentvalue = min;
    // }

    // do necessary calculatioins
    sliderrange = abs(min) + abs(max);
    unit = length/sliderrange;
    // display slider when render=1
    Bdisp_DrawLineVRAM(x, y, x + length, y);
    if(min<0){
        sliderx = x+((min*(-1))*unit)+(currentvalue*unit);
    }else{
        sliderx = x+(currentvalue*unit);
    }

    // display slider marker when render=1
    if(render==1){
        Bdisp_DrawLineVRAM(sliderx, y+2, sliderx, y-2);
    }else{
        Bdisp_ClearLineVRAM(sliderx, y+2, sliderx, y-2);
    }

    if(displayvalue == 1){
        // display current value underneath
        IL_Print_Float(x,y+10,currentvalue);
    }
}

void IL_Slider_Vertical(int x, int y, int length, int min, int max, float currentvalue, int displayvalue, int render)
{
    int sliderrange;
    float unit;
    float test;
    int slidery;

    // if(currentvalue > max){
    //     currentvalue = max;
    // }else if(currentvalue < min){
    //     currentvalue = min;
    // }

    // do necessary calculatioins
    sliderrange = abs(min) + abs(max);
    unit = (sliderrange/length);
    // Debug for Testing
    test = 20 / 40; // result: doesn't divide correctly! so float test = 0
    // IL_Print_Float(0,0, unit);
    // IL_Print_Float(0,40, sliderrange);
    // IL_Print_Float(0,48, length);
    // IL_Print_Float(0,56, test);
    // display slider when render=1
    Bdisp_DrawLineVRAM(x, y, x, y+length);

    if(min<0){
        slidery = y+((min*(-1))*unit)+(currentvalue*unit);
    }else{
        slidery = y+(currentvalue*unit);
    }

    // display slider marker when render=1
    if(render==1){
        Bdisp_DrawLineVRAM(x-2, slidery, x+2, slidery);
    }else{
        Bdisp_ClearLineVRAM(x-2, slidery, x+2, slidery);
    }

    if(displayvalue == 1){
        // display current value underneath
        IL_Print_Float(x-2,y+length+3,currentvalue);
    }
}

void IL_Multi_Selection(int x, int y, int verticaldist, int vertcount)
{
    //generate vertical boxes -> later checkboxes
    int count = 0;
    unsigned char box[3]={0xE6,0xA5,0};
    while (count < vertcount)
    {
        // Bdisp_SetPoint_VRAM(x,y+(count * verticaldist),1);
        PrintXY(x,y+(count * verticaldist),box,0);
        Bdisp_PutDisp_DD();
        count++;
    }
}