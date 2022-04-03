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

/*Declarations ----------------------------------------------------------------*/
UBYTE *BlackImage;    

/* Entry point ----------------------------------------------------------------*/
void setup()
{
  //Start display module 
  DEV_Module_Init(); 
  EPD_5IN83_V2_Init();
  EPD_5IN83_V2_Clear();
  DEV_Delay_ms(500);

  //Create a new image cache
  UWORD Imagesize = ((EPD_5IN83_V2_WIDTH % 8 == 0) ? (EPD_5IN83_V2_WIDTH / 8 ) : (EPD_5IN83_V2_WIDTH / 8 + 1)) * EPD_5IN83_V2_HEIGHT;
  if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
    printf("Failed to apply for black memory...\r\n");
    while (1);
  }
  printf("Paint_NewImage\r\n");
  Paint_NewImage(BlackImage, EPD_5IN83_V2_WIDTH, EPD_5IN83_V2_HEIGHT, 180, WHITE);
}

void loop()
{
  
  
  
  for (int i = 0; i <= NumberOfImages; i++) {   
     Paint_DrawBitMap(ImageArray[i]);
     EPD_5IN83_V2_Display(BlackImage);
     delay(NextSlideDelay * 1000);
  }
}
