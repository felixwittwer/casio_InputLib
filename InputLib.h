/*************************************************************/
/** InputLib - input library for fx-9860GII and GIII        **/
/** InputLib is free software to use                        **/
/**                                                         **/
/** @author Felix Wittwer                                   **/
/**                                                         **/
/** @file InputLib.h                                        **/
/** Include header for MonochromeLib                        **/
/**                                                         **/
/** @date 12-29-2022                                        **/
/*************************************************************/

#ifndef INPUTLIB
#define INPUTLIB

/****************************************************/
/** uncomment if you want to use the functions     **/
/****************************************************/

#define IL_ALL //defines all functions

#define IL_TEST

#define IL_Slider_Horizontal



/**************************/
/** Functions prototypes **/
/**************************/


#ifdef __cplusplus
extern "C"{
#endif


void IL_Test();
// void IL_Slider_Horizontal(int x, int y, int length, int min, int max, int currentvalue);
void IL_Slider_Horizontal(int x, int y, int length);

#ifdef __cplusplus
}
#endif

#endif //INPUTLIB
