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
    #define IL_SINGLE_SELECTION
    #define IL_MULTI_SELECTION
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

#ifdef IL_SINGLE_SELECTION
void IL_Single_Selection(int x, int y, unsigned char *content)
{
    PrintXY(1,1,(unsigned char*)"Single",0); //just as a filler
}
#endif

#ifdef IL_MULTI_SELECTION
void IL_Multi_Selection(int x, int y, unsigned char *content)
{
    PrintXY(1,1,(unsigned char*)"Multi",0); //just as a filler
}
#endif