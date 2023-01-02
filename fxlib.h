/*****************************************************************/
/*                                                               */
/*   CASIO fx-9860G SDK Library                                  */
/*                                                               */
/*   File name : fxlib.h                                         */
/*                                                               */
/*   Copyright (c) 2006 CASIO COMPUTER CO., LTD.                 */
/*                                                               */
/*****************************************************************/
#ifndef __FXLIB_H__
#define __FXLIB_H__

#include "dispbios.h"
#include "filebios.h"
#include "keybios.h"

#ifdef __GNUC__
    #define DEPRECATED(func) func __attribute__ ((deprecated))
#else
    #define DEPRECATED(func) func
#endif

// Prototypes

/**
 * Clear the whole area of VRAM and/or DD (Display Driver).
 */
void Bdisp_AllClr_DD(void);

/**
 * Clear the whole area of VRAM and/or DD (Display Driver).
 */
void Bdisp_AllClr_VRAM(void);

/**
 * Clear the whole area of VRAM and/or DD (Display Driver).
 */
void Bdisp_AllClr_DDVRAM(void);


/**
 * Clear the specified area of VRAM and/or DD (Display Driver).
 * @param pArea This is a pointer to the DISPBOX structure. The DISPBOX structure defines a rectangle. The structure specifies
 * the coordinates of two points: the upper-left and lower-right corners of the rectangle. The sides of the rectangle
 * extend from these two points and are parallel to the x-axis and the y-axis.
 */
void Bdisp_AreaClr_DD(const DISPBOX *pArea);

/**
 * Clear the specified area of VRAM and/or DD (Display Driver).
 * @param pArea This is a pointer to the DISPBOX structure. The DISPBOX structure defines a rectangle. The structure specifies
 * the coordinates of two points: the upper-left and lower-right corners of the rectangle. The sides of the rectangle
 * extend from these two points and are parallel to the x-axis and the y-axis.
 */
void Bdisp_AreaClr_VRAM(const DISPBOX *pArea);

/**
 * Clear the specified area of VRAM and/or DD (Display Driver).
 * @param pArea This is a pointer to the DISPBOX structure. The DISPBOX structure defines a rectangle. The structure specifies
 * the coordinates of two points: the upper-left and lower-right corners of the rectangle. The sides of the rectangle
 * extend from these two points and are parallel to the x-axis and the y-axis.
 */
void Bdisp_AreaClr_DDVRAM(const DISPBOX *pArea);

/**
 * Reverses the specified area of VRAM.
 * @param x1 (0 ~ 127) This is the x coordinate of the upper-left corner.
 * @param y1 (0 ~ 63) This is the y coordinate of the upper-left corner.
 * @param x2 (0 ~ 127) This is the x coordinate of the lower-right corner.
 * @param y2 (0 ~ 63) This is the y coordinate of the lower-right corner.
 */
void Bdisp_AreaReverseVRAM(int x1, int y1, int x2, int y2);

/**
 * Get the bitmap data of all screens from VRAM or DD (Display Driver).
 * @param pData This is a pointer to the area where the bitmap is stored. You should be securing the area of the size in 1024
 * bytes
 */
void Bdisp_GetDisp_DD(unsigned char *pData);

/**
 * Get the bitmap data of all screens from VRAM or DD (Display Driver).
 * @param pData This is a pointer to the area where the bitmap is stored. You should be securing the area of the size in 1024
 * bytes
 */
void Bdisp_GetDisp_VRAM(unsigned char *pData);

/**
 * Transfers all bitmap data from VRAM to DD (Display Driver).
 * @remarks The Bdisp_PutDisp_DD function is called in the GetKey function too.
 */
void Bdisp_PutDisp_DD(void);

/**
 * Transfers the specified area from VRAM to DD (Display Driver).
 * @param PutDispArea This is a pointer to the DISPBOX structure. The DISPBOX structure defines a rectangle. The structure specifies
 * the coordinates of two points: the upper-left and lower-right corners of the rectangle. The sides of the rectangle
 * extend from these two points and are parallel to the x-axis and the y-axis.
 */
void Bdisp_PutDispArea_DD(const DISPBOX *PutDispArea);

/**
 * Set or erase a dot at the specified position of VRAM and/or DD (Display Driver).
 * @param x (0~127) This is the x coordinate of the specified position.
 * @param y (0~63) This is the y coordinate of the specified position.
 * @param point If you set point to 1 then the dot is made black. If you set point to 0 then the dot is cleared.
 */
void Bdisp_SetPoint_DD(int x, int y, unsigned char point);

/**
 * Set or erase a dot at the specified position of VRAM and/or DD (Display Driver).
 * @param x (0~127) This is the x coordinate of the specified position.
 * @param y (0~63) This is the y coordinate of the specified position.
 * @param point If you set point to 1 then the dot is made black. If you set point to 0 then the dot is cleared.
 */
void Bdisp_SetPoint_VRAM(int x, int y, unsigned char point);

/**
 * Set or erase a dot at the specified position of VRAM and/or DD (Display Driver).
 * @param x (0~127) This is the x coordinate of the specified position.
 * @param y (0~63) This is the y coordinate of the specified position.
 * @param point If you set point to 1 then the dot is made black. If you set point to 0 then the dot is cleared.
 */
void Bdisp_SetPoint_DDVRAM(int x, int y, unsigned char point);

/**
 * Checks a dot at the specified position of VRAM.
 * @param x (0~127) This is the x coordinate of the specified position.
 * @param y (0~63) This is the y coordinate of the specified position.
 * @return If the dot at the specified position is black then this function returns 1. If the dot at the specified position is white
 * then this function returns 0.
 */
int Bdisp_GetPoint_VRAM(int x, int y);

/**
 * Copy a bitmap from a source rectangle to VRAM and/or DD (Display Driver).
 * @param WriteGraph This is the pointer to the DISPGRAPH structure.
 * @code{.cpp}
 * typedef struct tag_GRAPHDATA{ // Declared in dispbios.h.
 *     int width; // bitmap width
 *     int height; // bitmap height
 *     unsigned char *pBitmap; // pointer to bitmap data
 * } GRAPHDATA;
 *
 * typedef struct tag_DISPGRAPH{ // Declared in dispbios.h.
 *     int x; // x coordinate of the upper-left corner
 *     int y; // y coordinate of the upper-left corner
 *     GRAPHDATA GraphData; // pointer to structure data
 *     WRITEMODIFY WriteModify; // write modification graphic (declared in dispbios.h)
 *     WRITEKIND WriteKind; // kind of writing (declared in dispbios.h)
 * } DISPGRAPH;
 * @endcode
 * @remarks The bitmap data format is monochrome. The monochrome bitmap uses a one-bit, one- pixel format. Each scan is a
 * multiple of 8 bits. If the corresponding bit in the bitmap is 1, the pixel is set to black. If the corresponding bit in
 * the bitmap is zero, the pixel is set to white. Pixels are stored starting in the top left corner going from left to right
 * and then row by row from the top the bottom.
 */
void Bdisp_WriteGraph_DD(const DISPGRAPH *WriteGraph);

/**
 * Copy a bitmap from a source rectangle to VRAM and/or DD (Display Driver).
 * @param WriteGraph This is the pointer to the DISPGRAPH structure.
 * @code{.cpp}
 * typedef struct tag_GRAPHDATA{ // Declared in dispbios.h.
 *     int width; // bitmap width
 *     int height; // bitmap height
 *     unsigned char *pBitmap; // pointer to bitmap data
 * } GRAPHDATA;
 *
 * typedef struct tag_DISPGRAPH{ // Declared in dispbios.h.
 *     int x; // x coordinate of the upper-left corner
 *     int y; // y coordinate of the upper-left corner
 *     GRAPHDATA GraphData; // pointer to structure data
 *     WRITEMODIFY WriteModify; // write modification graphic (declared in dispbios.h)
 *     WRITEKIND WriteKind; // kind of writing (declared in dispbios.h)
 * } DISPGRAPH;
 * @endcode
 * @remarks The bitmap data format is monochrome. The monochrome bitmap uses a one-bit, one- pixel format. Each scan is a
 * multiple of 8 bits. If the corresponding bit in the bitmap is 1, the pixel is set to black. If the corresponding bit in
 * the bitmap is zero, the pixel is set to white. Pixels are stored starting in the top left corner going from left to right
 * and then row by row from the top the bottom.
 */
void Bdisp_WriteGraph_VRAM(const DISPGRAPH *WriteGraph);

/**
 * Copy a bitmap from a source rectangle to VRAM and/or DD (Display Driver).
 * @param WriteGraph This is the pointer to the DISPGRAPH structure.
 * @remarks The bitmap data format is monochrome. The monochrome bitmap uses a one-bit, one- pixel format. Each scan is a
 * multiple of 8 bits. If the corresponding bit in the bitmap is 1, the pixel is set to black. If the corresponding bit in
 * the bitmap is zero, the pixel is set to white. Pixels are stored starting in the top left corner going from left to right
 * and then row by row from the top the bottom.
 *
 * @code{.cpp}
 * typedef struct tag_GRAPHDATA{ // Declared in dispbios.h.
 *     int width; // bitmap width
 *     int height; // bitmap height
 *     unsigned char *pBitmap; // pointer to bitmap data
 * } GRAPHDATA;
 *
 * typedef struct tag_DISPGRAPH{ // Declared in dispbios.h.
 *     int x; // x coordinate of the upper-left corner
 *     int y; // y coordinate of the upper-left corner
 *     GRAPHDATA GraphData; // pointer to structure data
 *     WRITEMODIFY WriteModify; // write modification graphic (declared in dispbios.h)
 *     WRITEKIND WriteKind; // kind of writing (declared in dispbios.h)
 * } DISPGRAPH;
 * @endcode
 */
void Bdisp_WriteGraph_DDVRAM(const DISPGRAPH *WriteGraph);

/**
 * Get the bitmap data of the specified area from VRAM or DD (Display Driver).
 * @param ReadArea This is a pointer to the DISPBOX structure. The DISPBOX structure defines a rectangle. The structure specifies
 * the coordinates of two points: the upper-left and lower-right corners of the rectangle. The sides of the rectangle
 * extend from these two points and are parallel to the x-axis and the y-axis.
 * @param ReadData This is a pointer to the area where the bitmap is stored.
 */
void Bdisp_ReadArea_DD(const DISPBOX *ReadArea, unsigned char *ReadData);

/**
 * Get the bitmap data of the specified area from VRAM or DD (Display Driver).
 * @param ReadArea This is a pointer to the DISPBOX structure. The DISPBOX structure defines a rectangle. The structure specifies
 * the coordinates of two points: the upper-left and lower-right corners of the rectangle. The sides of the rectangle
 * extend from these two points and are parallel to the x-axis and the y-axis.
 * @param ReadData This is a pointer to the area where the bitmap is stored.
 */
void Bdisp_ReadArea_VRAM(const DISPBOX *ReadArea, unsigned char *ReadData);

/**
 * Draws a line to VRAM.
 * @param x1 (0 ~ 127) This is the x coordinate of the line's starting point.
 * @param y1 (0 ~ 63) This is the y coordinate of the line's starting point.
 * @param x2 (0 ~ 127) This is the x coordinate of the line's ending point.
 * @param y2 (0 ~ 63) This is the y coordinate of the line's ending point.
 */
void Bdisp_DrawLineVRAM(int x1, int y1, int x2, int y2);

/**
 * Draws a white line to VRAM.
 * @param x1 (0 ~ 127) This is the x coordinate of the line's starting point.
 * @param y1 (0 ~ 63) This is the y coordinate of the line's starting point.
 * @param x2 (0 ~ 127) This is the x coordinate of the line's ending point.
 * @param y2 (0 ~ 63) This is the y coordinate of the line's ending point.
 */
void Bdisp_ClearLineVRAM(int x1, int y1, int x2, int y2);

/**
 * Makes settings for the location of the display cursor.
 * @param x (1 ~ 21) This is the x position of the display cursor.
 * @param y (1 ~ 8) This is the y position of the display cursor.
 */
void locate(int x, int y);

/**
 * Displays a character string at the current position of the display cursor.
 * @param str This is the pointer to a character string. The character string must be null-terminated.
 * @remarks After you call the Print function, the cursor position is moved to the right of the last character.
 */
void Print(const unsigned char *str);

/**
 * Displays a character string in reversed color at the current position of the display cursor.
 * @param str This is the pointer to a character string. The character string must be null-terminated.
 * @remarks After you call the PrintRev function, the cursor position is moved to the right of the last character.
 */
void PrintRev(const unsigned char *str);

/**
 * Displays one character at the current position of the display cursor
 * @param c This is the pointer to a character string. The character string must be null-terminated.
 * @remarks After you call the PrintC function, the cursor position is moved to the right of the last character.
 */
void PrintC(const unsigned char *c);

/**
 * Displays one character in reversed color at the current position of the display cursor.
 * @param str This is the pointer to a character string. The character string must be null-terminated.
 * @remarks After you call the PrintRevC function, the cursor position is moved to the right of the last character.
 */
void PrintRevC(const unsigned char *str);

/**
 * Displays a character string from the current position of the display cursor to the specified
 * ending x position. If the character string ends before the ending position, the space up to the specified position is
 * padded with blanks.
 * @param str This is the pointer to a character string. The character string must be null-terminated.
 * @param max (1 ~ 21) This is the ending x position.
 * @remarks After you call the PrintLine function, the cursor position is moved to the right of the last character.
 */
void PrintLine(const unsigned char *str, int max);

/**
 * Displays a character string in reversed color from the current position of the display cursor
 * to the specified ending x position. If the character string ends before the ending position, the space up to the
 * specified position is padded with blanks.
 * @param str This is the pointer to a character string. The character string must be null-terminated.
 * @param max (1 ~ 21) This is the ending x position.
 * @remarks After you call the PrintRLine function, the cursor position is moved to the right of the last character
 */
void PrintRLine(const unsigned char *str, int max);

/**
 * Displays a character string at the specified position.
 * @param x (0 ~ 127) This is the x coordinate of the upper-left corner of the string
 * @param y (0 ~ 63) This is the y coordinate of the upper-left corner of the string
 * @param str This is the pointer to a character string. The character string must be null-terminated.
 * @param type If you set the type to 0 then the character string is displayed in normal color. If you set the type to 1 then the
 * character string is displayed in reverse color
 */
void PrintXY(int x, int y, const unsigned char *str, int type);

/**
 * Displays a small font character string at the specified position.
 * @param x (0 ~ 127) This is the x coordinate of the upper-left corner of the string
 * @param y (0 ~ 63) This is the y coordinate of the upper-left corner of the string
 * @param str This is the pointer to a character string. The character string must be null-terminated.
 * @param type This is the drawing type. The following definitions are declared in dispbios.h.
 * <br>
 * <b>MINI_OVER</b>     Overwrite (fill)<br>
 * <b>MINI_OR</b>       OR<br>
 * <b>MINI_REV</b>      Reverse color<br>
 * <b>MINI_REVOR</b>    OR in reverse color<br>
 * @return <i>undocumented</i>
 */
int PrintMini(int x, int y, const unsigned char *str, int type);

/**
 * Saves a screen image in the system area.
 * @param num This is the number of the save area. The following definitions are declared in dispbios.h.
 * <br>
 * SAVEDISP_PAGE1 <br>
 * SAVEDISP_PAGE2 <br>
 * SAVEDISP_PAGE3 <br>
 * @remarks The screen image is copied from VRAM. The image of the DD (Display Driver) is not copied.
 */
void SaveDisp(unsigned char num);

/**
 * Restores a screen image in the system area.
 * @param num This is the number of the save area. The following definitions are declared in dispbios.h.
 * <br>
 * SAVEDISP_PAGE1 <br>
 * SAVEDISP_PAGE2 <br>
 * SAVEDISP_PAGE3 <br>
 * @remarks Even if you call this function, the screen image is not displayed. You should call the Bdisp_PutDisp_DD function
 * too.
 */
void RestoreDisp(unsigned char num);

/**
 * The PopUpWin function displays a popup window of the specified size of lines. Also, the inside of the popup
 * window is cleared.
 * @param n (1~5) This is the number of lines of the popup window.
 * @remarks To display the contents (string, etc.) of a window, use the Locate function or the Print function.
 */
void PopUpWin(int n);

/**
 * Opens an existing file.
 * @param filename This is the pointer to a null-terminated string that names the file to be opened.
 * @param mode <p>The mode parameter specifies the action to open.
 * The following definitions are declared in filebios.h.</p>
 * <p><b>_OPENMODE_READ</b>             Opens the file for reading only.</p>
 * <p><b>_OPENMODE_READ_SHARE</b>       Opens the file and denies read access to other processes.</p>
 * <p><b>_OPENMODE_WRITE</b>            Opens the file for writing only.</p>
 * <p><b>_OPENMODE_READWRITE</b>        Opens the file for reading and writing.</p>
 * <p><b>_OPENMODE_READWRITE_SHARE</b>  Opens the file with exclusive mode, denying both read and write access
 *                                      to other processes.</p>
 * @return If the function succeeds, the return value specifies a file handle. It is greater than or equal to 0.
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks <p>This function opens a file in Storage Memory or the SD card.
 * To open the file in Main Memory, call the <i>Bfile_OpenMainMemory</i> function.</p>
 * <p>If you open a file in <b>Storage Memory</b>, the pathname to the file is the following string.
 * FONTCHARACTER PathName[]={'¥¥','¥¥','f','l','s','0','¥¥','f','i','l','e','n','a','m','e','.','e','x','t',0};
 * The root directory (¥¥fls0¥) means Storage Memory area. This name is fixed.</p>
 * <p>If you open a file in <b>SD card</b>, the pathname to the file is the following string.
 * FONTCHARACTER PathName[]={'¥¥','¥¥','c','r','d','0','¥¥','f','i','l','e','n','a','m','e','.','e','x','t',0};
 * The root directory (¥¥crd0¥) means SD card area. This name is fixed.</p>
 * The capital letter and the small letter of the file name are <b>identified</b>.
 * To <b>close the file after use</b>, call the <i>Bfile_CloseFile</i> function.
 * <b>Only four</b> files can be opened at the same time.
 */
int Bfile_OpenFile(const FONTCHARACTER *filename, int mode);

/**
 * Opens an existing file
 * @param name This is the pointer to a null-terminated string that names the file to be opened.
 * The file name is limited to eight characters.
 * @return If the function succeeds, the return value specifies a file handle. It is greater than or equal to 0.
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks This function opens a file in Main Memory.
 * To open the file in Storage Memory or the SD card, call the <i>Bfile_OpenFile</i> function.
 * You do not need to specify the folder. You only have to set only the file name to this parameter.
 * Ex. unsigned char name[]={“Settings”};
 * The capital letter and the small letter of the file name are <b>distinguished</b>.
 * To <b>close the file after use</b>, call the <i>Bfile_CloseFile</i> function.
 * <b>Only four</b> files can be opened at the same time.
 */
int Bfile_OpenMainMemory(const unsigned char *name);

/**
 * Reads data from a file, starting at the position indicated by the file pointer. After the
 * read operation has been completed, the file pointer is adjusted by the number of bytes actually read.
 * @param HANDLE This is the handle of the file to read. HANDLE should be the handle opened by the Bfile_OpenFile or
 * Bfile_OpenMainMemory function.
 * @param buf This is the pointer to the buffer that receives the data read from the file.
 * @param size This is the number of bytes to be read from the file.
 * @param readpos This is the starting position to read. If the readpos parameter is -1, this function reads data from the position
 * indicated by the file pointer. If the readpos parameter greater than or equal to 0, this function reads data from
 * the position indicated by the readpos parameter.
 * @return If the function succeeds, this function returns the number of bytes actually read. It is greater than or equal to 0.
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks If you read the Windows file, the multi byte data is stored in Little Endian format. To use this data, you should
 * convert the multi byte data into the Big Endian format.
 */
int Bfile_ReadFile(int HANDLE, void *buf, int size, int readpos);

/**
 * Writes data to a file. The function starts writing data to the file at the position
 * indicated by the file pointer. After the write operation has been completed, the file pointer is adjusted by the
 * number of bytes actually written.
 * @param HANDLE This is the handle of the file to write. HANDLE should be the handle opened by the Bfile_OpenFile or
 * Bfile_OpenMainMemory function.
 * @param buf This is the pointer to the buffer containing the data to be written to the file.
 * @param size This is the number of bytes to write to the file.
 * @return If the function succeeds, this function returns the position indicated by the file pointer.
 * It is greater than or equal to 0.
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks If you use a file that is written by this function on the PC, you should save the multi byte data in the Little Endian
 * format.
 */
int Bfile_WriteFile(int HANDLE, const void *buf, int size);

/**
 * Moves the file pointer of an open file.
 * @param HANDLE This is the file handle whose file pointer will be moved HANDLE should be the handle opened by the
 * Bfile_OpenFile or Bfile_OpenMainMemory function.
 * @param pos This is the number of bytes to move file pointer.
 * @return If the function succeeds, this function returns the number of bytes that can continuously be read.
 * It is greater than or equal to 0.
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks The starting point for the file pointer move is the beginning of the file. The file pointer is at the head of the file
 * immediately after the file was opened.
 */
int Bfile_SeekFile(int HANDLE, int pos);

/**
 * Closes an open file handle.
 * @param HANDLE This is the handle of the file to close. HANDLE should be the handle opened by the Bfile_OpenFile or
 * Bfile_OpenMainMemory function.
 * @return If the function succeeds, this function returns 0.
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks Only four files can be opened at the same time.
 */
int Bfile_CloseFile(int HANDLE);

/**
 * Retrieves the size of the free space, in bytes, of the specified device.
 * @param devicetype This is the type of device. The following definitions are declared in filebios.h.
 * <br>
 * <b>DEVICE_MAIN_MEMORY</b>    Main Memory<br>
 * <b>DEVICE_STORAGE</b>        Storage Memory<br>
 * <b>DEVICE_SD_CARD</b>        SD card (only fx-9860G SD model)<br>
 * @param freebytes This is the pointer to the size of the free space.
 * @return If the function succeeds, this function returns 0.
 * If the function fails, the return value is an error code. It is a negative value.
 */
int Bfile_GetMediaFree(enum DEVICE_TYPE devicetype, int *freebytes);

/**
 * Retrieves the size, in bytes, of the specified file.
 * @param HANDLE This is the handle of the file whose size will be retrieved. HANDLE should be the handle opened by the
 * Bfile_OpenFile or Bfile_OpenMainMemory function.
 * @return If the function succeeds, the return value is the file size.
 * If the function fails, the return value is an error code. It is a negative value.
 */
int Bfile_GetFileSize(int HANDLE);

/**
 * Creates the file.
 * @param filename This is the pointer to a null-terminated string that names the file to be created.
 * @param size This is the size of the file to be created. This parameter is only used when you create a file in Storage Memory.
 * @return If the function succeeds, the return value is 0.
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks <p>This function creates a file in Storage Memory or the SD card.
 * To create the file in Main Memory, call the <i>Bfile_CreateMainMemory</i> function.
 * If you write data into a created file, you should call the <i>Bfile_OpenFile</i> function and <i>Bfile_WriteFile</i> function too.</p>
 * <p>If you create a file in <b>Storage Memory</b>, the pathname to the file is the following string.
 * FONTCHARACTER PathName[]={'¥¥','¥¥','f','l','s','0','¥¥','f','i','l','e','n','a','m','e','.','e','x','t',0};
 * The root directory (¥¥fls0¥) means Storage Memory area. This name is fixed.</p>
 * <p>If you create a file in <b>SD card</b>, the pathname to the file is the following string.
 * FONTCHARACTER PathName[]={'¥¥','¥¥','c','r','d','0','¥¥','f','i','l','e','n','a','m','e','.','e','x','t',0};
 * The root directory (¥¥crd0¥) means SD card area. This name is fixed.</p>
 * The capital letter and the small letter of the file name are identified.
 */
int Bfile_CreateFile(const FONTCHARACTER *filename, int size);

/**
 * Creates a new directory.
 * @param pathname This is the pointer to a null-terminated string that specifies the path of the directory to be created.
 * @return If the function succeeds, the return value is 0.
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks <p>This function creates a directory in Storage Memory or the SD card.
 * You cannot create a directory in Main Memory.</p>
 * <p>If you create a directory in <b>Storage Memory</b>, the pathname to the directory is the following string.
 * FONTCHARACTER PathName[]={'¥¥','¥¥','f','l','s','0','¥¥','d','i','r','n','a','m','e',0};
 * The root directory (¥¥fls0¥) means Storage Memory area. This name is fixed.</p>
 * <p>If you create a directory in <b>SD card</b>, the pathname to the directory is the following string.
 * FONTCHARACTER PathName[]={'¥¥','¥¥','c','r','d','0','¥¥','d','i','r','n','a','m','e',0};
 * The root directory (¥¥crd0¥) means SD card area. This name is fixed.</p>
 * The capital letter and the small letter of the file name are identified.
 * The directory can be created under only the route directory.
 */
int Bfile_CreateDirectory(const FONTCHARACTER *pathname);

/**
 * Creates the file.
 * @param name This is the pointer to a null-terminated string that names the file to be created.
 * The file name is limited to eight characters.
 * @return If the function succeeds, the return value is 0.
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks This function creates a file in Main Memory.
 * To create the file in Storage Memory or the SD card, call the <i>Bfile_CreateFile</i> function.
 * You do not need to specify the folder. You only have to set only the file name to this parameter.
 * Ex. unsigned char name[]={“Settings”};
 * The capital letter and the small letter of the file name are distinguished.
 */
int Bfile_CreateMainMemory(const unsigned char *name);

/**
 * Renames the specified file.
 * @param oldname This is the pointer to a null-terminated string that specifies the file to rename.
 * @param newname This is the pointer to a null-terminated string that specifies the new name of the file.
 * The file name is limited to eight characters.
 * @return If the function succeeds, the return value is 0.
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks This function renames a file in Main Memory.
 * To rename the file in Storage Memory or the SD card, call the <i>Bfile_RenameFile</i> function.
 * You do not need to specify the folder. You only have to set only the file name to this parameter.
 * Ex. unsigned char name[]={“Settings”};
 * The capital letter and the small letter of the file name are distinguished.
 */
int Bfile_RenameMainMemory(const unsigned char *oldname, const unsigned char *newname);

/**
 * Deletes an existing file.
 * @param filename This is the pointer to a null-terminated string that specifies the file to delete.
 * @return If the function succeeds, the return value is 0.
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks <p>This function deletes a file in Storage Memory or the SD card.
 * To delete the file in Main Memory, call the <i>Bfile_DeleteMainMemory</i> function.</p>
 * <p>If you delete a directory in <b>Storage Memory</b>, the pathname to the directory is the following string.
 * FONTCHARACTER PathName[]={'¥¥','¥¥','f','l','s','0','¥¥','f','i','l','e','n','a','m','e','.','e','x','t',0};
 * The root directory (¥¥fls0¥) means Storage Memory area. This name is fixed.</p>
 * <p>If you delete a directory in <b>SD card</b>, the pathname to the directory is the following string.
 * FONTCHARACTER PathName[]={'¥¥','¥¥','c','r','d','0','¥¥','f','i','l','e','n','a','m','e','.','e','x','t',0};
 * The root directory (¥¥crd0¥) means SD card area. This name is fixed.</p>
 * The capital letter and the small letter of the file name are identified.
 */
int Bfile_DeleteFile(const FONTCHARACTER *filename);

/**
 * Deletes an existing directory.
 * @param pathname This is the pointer to a null-terminated string that specifies the directory to delete.
 * @return If the function succeeds, the return value is 0.
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks This function deletes a directory in Storage Memory.
 * <b>You cannot delete a directory in Main Memory and the SD card.</b>
 * <p>If you delete a directory in Storage Memory, the pathname to the file is the following string.
 * FONTCHARACTER PathName[]={'¥¥','¥¥','f','l','s','0','¥¥','d','i','r','n','a','m','e',0};
 * The root directory (¥¥fls0¥) means Storage Memory area. This name is fixed.</p>
 * The capital letter and the small letter of the file name are identified.
 */
int Bfile_DeleteDirectory(const FONTCHARACTER *pathname);

/**
 * Deletes an existing file.
 * @param name This is the pointer to a null-terminated string that specifies the file to delete.
 * @return If the function succeeds, the return value is 0.
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks This function deletes a file in Main Memory.
 * To delete the file in Storage Memory or the SD card, call the <i>Bfile_DeleteFile</i> function.
 * You do not need to specify the folder. You only have to set only the file name to this parameter.
 * Ex. unsigned char name[]={“Settings”};
 * The capital letter and the small letter of the file name are distinguished.
 */
int Bfile_DeleteMainMemory(const unsigned char *name);

/**
 * Searches a directory for a file whose name matches the specified filename.
 * Examines subdirectory names as well as filenames.
 * @param pathname This is the pointer to a null-terminated string that specifies a valid directory or path and filename,
 * which can contain wildcard characters “*”.
 * @param FindHandle If this function success, the return value is a search handle used in a subsequent call
 * to <i>Bfile_FindNext</i> or <i>Bfile_FindClose</i>.
 * @param foundfile This is the pointer to the buffer that receives the found file or subdirectory
 * @param fileinfo This is the pointer to the FILE_INFO structure that receives information about the found file or subdirectory.
 * @code
 * typedef struct tag_FILE_INFO // declared in filebios.h
 * {
 *     unsigned short id; // file index
 *     unsigned short type; // file type (declared in filebios.h.)
 *     unsigned long fsize; // file size
 *     unsigned long dsize; // data size (except file header)
 *     unsigned int property; // the file has not been completed, except when property is 0.
 *     unsigned long address; // top address of data (Don’t directly access this address.)
 * } FILE_INFO;
 * @endcode
 * @return If the function succeeds, the return value is 0. When a specified file is not found, this function returns
 * IML_FILEERR_ENUMRATEEND (declared in filebios.h).
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks This function finds files and subdirectories in Storage Memory or the SD card.
 * <b>You cannot find files and subdirectories in Main Memory</b>.
 * <p>If you find the Bitmap files in <b>Storage Memory</b>, the pathname is the following string.
 * FONTCHARACTER PathName[]={'¥¥','¥¥','f','l','s','0','¥¥','*','.','b','m','p',0};
 * The root directory (¥¥fls0¥) means Storage Memory area. This name is fixed.</p>
 * <p>If you find the Bitmap files in <b>SD card</b>, the pathname is the following string.
 * FONTCHARACTER PathName[]={'¥¥','¥¥','c','r','d','0','¥¥','*','.','b','m','p',0};
 * The root directory (¥¥crd0¥) means SD card area. This name is fixed.</p>
 * The capital letter and the small letter of the file name are identified.
 * When the search handle is no longer needed, close it by using the Bfile_FindClose function. <b>Only four search
 * handles can be opened at the same time.</b>
 */
int Bfile_FindFirst(const FONTCHARACTER *pathname, int *FindHandle, FONTCHARACTER *foundfile, FILE_INFO *fileinfo);

/**
 * Continues a file search from a previous call to the <i>Bfile_FindFirst</i> function.
 * @param FindHandle This is a search handle returned by a previous call to the Bfile_FindFirst function.
 * @param foundfile This is the pointer to the buffer that receives the found file or subdirectory
 * @param fileinfo This is the pointer to the FILE_INFO structure that receives information about the found file or subdirectory.
 * @code
 * typedef struct tag_FILE_INFO // declared in filebios.h
 * {
 *     unsigned short id; // file index
 *     unsigned short type; // file type (declared in filebios.h.)
 *     unsigned long fsize; // file size
 *     unsigned long dsize; // data size (except file header)
 *     unsigned int property; // the file has not been completed, except when property is 0.
 *     unsigned long address; // top address of data (Don’t directly access this address.)
 * } FILE_INFO;
 * @endcode
 * @return If the function succeeds, the return value is 0. When a specified file is not found, this function returns
 * IML_FILEERR_ENUMRATEEND (declared in filebios.h).
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks This function finds files and subdirectories in Storage Memory or the SD card. You cannot find files and
 * subdirectories in Main Memory.
 */
int Bfile_FindNext(int FindHandle, FONTCHARACTER *foundfile, FILE_INFO *fileinfo);

/**
 * Closes the specified search handle. The <i>Bfile_FindFirst</i> and <i>Bfile_FindNext</i>
 * functions use the search handle to locate files with names that match a given name.
 * @param FindHandle This is a search handle. This handle must have been previously opened by the <i>Bfile_FindFirst</i> function.
 * @return If the function succeeds, the return value is 0.
 * If the function fails, the return value is an error code. It is a negative value.
 * @remarks Only four search handles can be opened at the same time.
 */
int Bfile_FindClose(int FindHandle);

/**
 * Sets the repetition interval of the key.
 * @param FirstCount This is time from pushing the key to the input of the first repetition key.
 * This parameter is the time in milliseconds divided by 25.
 * @param NextCount This is the interval time of the repetition key.
 * This parameter is the time in milliseconds that was divided by 25.
 * @remarks The cursor key is the only key that can be set for repetition. Other keys will not repeat even if they are
 * continuously pressed.
 */
void Bkey_Set_RepeatTime(long FirstCount, long NextCount);

/**
 * Gets the repetition interval of the key.
 * @param FirstCount This is the pointer to time from pushing the key to the input of the first repetition key.
 * This parameter is the time in milliseconds divided by 25.
 * @param NextCount This is the pointer to the interval time of the repetition key.
 * This parameter is the time in milliseconds divided by 25.
 * @remarks The cursor key is the only key that can be set for repetition. Other keys will not repeat even if they are
 * continuously pressed.
 */
void Bkey_Get_RepeatTime(long *FirstCount, long *NextCount);

/**
 * Sets the default key repetition interval.
 * @remarks This function sets the time from pushing the key to starting key repeats to 500 milliseconds, and sets the interval
 * time of repetition key to 125 milliseconds.
 * The cursor key is the only key that can be set for repetition. Other keys will not repeat even if they are
 * continuously pressed.
 */
void Bkey_Set_RepeatTime_Default(void);

/**
 * Performs a key wait and returns a value indicating the pressed key.
 * @param sel <p>This is the type of waiting for key. The following definitions are declared in keybios.h.</p>
 * <p><b>KEYWAIT_HALTON_TIMEROFF</b>    If there are no characters in the key buffer, this function waits until a
 *                                      character arrives and then returns immediately.</p>
 * <p><b>KEYWAIT_HALTOFF_TIMEROFF</b>   If there are no characters in the key buffer, this function returns
 *                                      immediately.</p>
 * <p><b>KEYWAIT_HALTON_TIMERON</b>     If no character arrives within the time specified by the time parameter, this
 *                                      function times out.</p>
 * @param time This is the time out period in seconds.
 * This parameter is used only when the first parameter is <b>KEYWAIT_HALTON_TIMERON</b>.
 * @param menu If you set 0 to the <u>menu</u>, the menu key performs Main-Menu.
 * If you set 1 to the <u>menu</u>, the menu key returns the key code.
 * @param keycode If the function succeeds, the function returns key code.
 * @return <p>The function will return the following values. The following definitions are declared in keybios.h.</p>
 * <p><b>KEYREP_NOEVENT</b>     Because there are no characters in the key buffer, this function returned immediately.</p>
 * <p><b>KEYREP_KEYEVENT</b>    Keycode will be set.</p>
 * <p><b>KEYREP_TIMEREVENT</b>  This function returned because time seconds passed.</p>
 * @remarks The Auto Power Off event is also handled by this function. If an Auto Power Off event occurs the application will
 * not be notified. Once the calculator is turned back on control is returned to the GetKeyWait function.
 */
int GetKeyWait(int sel, int time, int menu, unsigned int *keycode);

/**
 * Checks whether the specified key is pressed.
 * @param keycode This is a key code of the key that you check.
 * @return If the specified key is pressed, the return value is 1.
 * If the specified key is not pressed, the return value is 0.
 * @remarks When you wait events only by this function, the calculator never turns off.
 * Only use this function when you need to wait for key input to continue.
 * @deprecated The "IsKeyDown" function in "fx-9860G SDK Libraries" has been deprecated and is now
 * unsupported in "USB POWER GRAPHIC 2" version of "fx-9860GII(SD)",
 * "GRAPH75(95)" and "fx-9860G AU PLUS".
 * Instead of "IsKeyDown", please use "GetKey" or "Bkey_GetKeyWait" (new function).
 */
int DEPRECATED(IsKeyDown(int keycode));

/**
 * Checks whether the specified key was completely released.
 * @param keycode This is a key code of the key that you check.
 * @return If the specified key was completely released, the return value is 1.
 * If the specified key was completely released, the return value is 0.
 */
int IsKeyUp(int keycode);

/**
 * Performs a key wait and returns a value indicating the pressed key.
 * @param keycode The function returns key code into the keycode.
 * @return If a character key was pressed, the return value is 1.
 * If a control key was pressed, the return value is 0.
 * @remarks If there are no characters in the key buffer, this function waits until a character arrives and then returns
 * immediately.
 * Even if the menu key pressed, this function does not return menu key code.
 * The system processes the menu key event.
 * Off event, Auto Power Off event, and contrast adjustment are also handled by this function. If an off or Auto
 * Power Off event occurs the application will not be notified. Once the calculator is turned back on control is
 * returned to the GetKey function.
 */
int GetKey(unsigned int *keycode);

/**
 * Creates a timer with the specified time-out value.
 * @param ID This parameter specifies a timer identifier. The following defines are declared in timer.h.
 * <br>
 * ID_USER_TIMER1<br>
 * ID_USER_TIMER2<br>
 * ID_USER_TIMER3<br>
 * ID_USER_TIMER4<br>
 * ID_USER_TIMER5<br>
 * @param elapse This parameter specifies the time-out value, in milliseconds. It is set at 25ms intervals.
 * @param hander This is the pointer to the function to be notified when the time-out value elapses.
 * @return If the function succeeds, the return value is a timer identifier. This is the same as the first parameter.
 * If the function fails, the return value is a negative value. In this case, the specified timer in use or parameter is
 * illegal.
 * @remarks Do not do time-consuming processes in the timer handler.
 */
int SetTimer(int ID, int elapse, void (*hander)(void));

/**
 * Destroys the specified timer.
 * @param ID This is specifies the timer to be destroyed.
 * This parameter must be the timer identifier returned by <i>SetTimer</i>.
 * @return If the function succeeds, the return value is a timer identifier. This is same as first parameter.
 * If the function fails, the return value is a negative value. In this case, parameter is illegal.
 */
int KillTimer(int ID);

/**
 * Suspends the execution of the current thread for a specified interval.
 * @param millisecond This is specifies the time, in milliseconds, for which to suspend execution.
 */
void Sleep(int millisecond);

/**
 * Registers the handler that is called when the application terminates.
 * @param callback This is the pointer to the function to be called when the application is closing.
 */
void SetQuitHandler(void (*callback)(void));

int INIT_ADDIN_APPLICATION(int isAppli, unsigned short OptionNum);


#endif
