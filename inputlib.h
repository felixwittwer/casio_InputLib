/*************************************************************/
/** inputlib.h - input library for fx-9860GII and GIII      **/
/** inputlib.h is free software to use                      **/
/**                                                         **/
/** @author Felix Wittwer                                   **/
/**                                                         **/
/** @file InputLib.c                                        **/
/**                                                         **/
/** @date 12-31-2022                                        **/
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
    int slidery;

    // if(currentvalue > max){
    //     currentvalue = max;
    // }else if(currentvalue < min){
    //     currentvalue = min;
    // }

    // do necessary calculatioins
    sliderrange = abs(min) + abs(max);
    unit = length/sliderrange;
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