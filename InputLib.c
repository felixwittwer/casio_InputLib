/*************************************************************/
/** InputLib - input library for fx-9860GII and GIII        **/
/** InputLib is free software to use                        **/
/**                                                         **/
/** @author Felix Wittwer                                   **/
/**                                                         **/
/** @file InputLib.c                                        **/
/** Include header for MonochromeLib                        **/
/**                                                         **/
/** @date 12-29-2022                                        **/
/*************************************************************/

#include "InputLib.h"
#include "fxlib.h"
#include "stdlib.h"

/******************************/
/** Dependencies management  **/
/******************************/

#ifdef IL_ALL
    #define IL_TEST
    #define IL_Slider_Horizontal
#endif

/***************/
/** Functions **/
/***************/

#ifdef IL_TEST
void IL_Test()
{
    PrintXY(1,1,(unsigned char*)"Test",0);
}
#endif

// #ifdef IL_Slider_Horizontal
// void IL_Slider_Horizontal(int x, int y, int length, int min, int max, int currentvalue)
// {
//     int sliderrange;
//     float unit;
//     // necessary calculatioins
//     sliderrange = abs(min) + abs(max);
//     unit = sliderrange/length;
//     // display
//     Bdisp_DrawLineVRAM(x, y, x + length, y);

// }
// #endif

#ifdef IL_Slider_Horizontal
void IL_Slider_Horizontal(int x, int y, int length)
{
    Bdisp_DrawLineVRAM(x, y, x + length, y);
    Bdisp_PutDisp_DD();
}
#endif
