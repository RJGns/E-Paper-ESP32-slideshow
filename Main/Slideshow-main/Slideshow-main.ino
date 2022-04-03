/* Includes -------------------------------------------------------------------*/
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "ImagesData.h"
#include <stdlib.h>

/*Config ----------------------------------------------------------------------*/
const unsigned char *ImageArray[] = {Arduino,ShrekImg,UnionJack};
const int NumberOfImages = 3;
const int NextSlideDelay = 60; // in seconds
//Highlight this ->  REPLACE_WITH_YOUR_DISPLAY then press CRTL-F or CMD-F

/*Declarations ----------------------------------------------------------------*/
UBYTE *BlackImage;    

/* Entry point ----------------------------------------------------------------*/
void setup()
{
  //Start display module 
  DEV_Module_Init(); 
   REPLACE_WITH_YOUR_DISPLAY_Init();
   REPLACE_WITH_YOUR_DISPLAY_Clear();
  DEV_Delay_ms(500);

  //Create a new image cache
  UWORD Imagesize = (( REPLACE_WITH_YOUR_DISPLAY_WIDTH % 8 == 0) ? ( REPLACE_WITH_YOUR_DISPLAY_WIDTH / 8 ) : ( REPLACE_WITH_YOUR_DISPLAY_WIDTH / 8 + 1)) *  REPLACE_WITH_YOUR_DISPLAY_HEIGHT;
  if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
    printf("Failed to apply for black memory...\r\n");
    while (1);
  }
  printf("Paint_NewImage\r\n");
  Paint_NewImage(BlackImage,  REPLACE_WITH_YOUR_DISPLAY_WIDTH,  REPLACE_WITH_YOUR_DISPLAY_HEIGHT, 180, WHITE);
}

void loop()
{
  //Loop through ImageArray, then wait for NextSlideDelay, then repeat.
  for (int i = 0; i <= NumberOfImages; i++) {   
     Paint_DrawBitMap(ImageArray[i]);
     REPLACE_WITH_YOUR_DISPLA_Display(BlackImage);
     delay(NextSlideDelay * 1000);
  }
}
