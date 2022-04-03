/* Includes ------------------------------------------------------------------*/
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "ImagesData.h"
#include <stdlib.h>

const unsigned char *test[] = {Arduino,ShrekImg,UnionJack};
const int NumberOfImages = 3;
const int NextSlideDelay = 10; // in seconds
UBYTE *BlackImage;    

/* Entry point ----------------------------------------------------------------*/
void setup()
{
  DEV_Module_Init();

  EPD_5IN83_V2_Init();
  EPD_5IN83_V2_Clear();
  DEV_Delay_ms(500);

  //Create a new image cache
  /* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
  UWORD Imagesize = ((EPD_5IN83_V2_WIDTH % 8 == 0) ? (EPD_5IN83_V2_WIDTH / 8 ) : (EPD_5IN83_V2_WIDTH / 8 + 1)) * EPD_5IN83_V2_HEIGHT;
  if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
    printf("Failed to apply for black memory...\r\n");
    while (1);
  }
  printf("Paint_NewImage\r\n");
  Paint_NewImage(BlackImage, EPD_5IN83_V2_WIDTH, EPD_5IN83_V2_HEIGHT, 180, WHITE);

  /*
    printf("Clear...\r\n");
    EPD_5IN83_V2_Clear();

    printf("Goto Sleep...\r\n");
    EPD_5IN83_V2_Sleep();
    free(BlackImage);
    BlackImage = NULL;
  */
}

void loop()
{
  //printf("Back to start of slideshow");
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);
  
  
  for (int i = 0; i <= NumberOfImages; i++) {
   // printf(array[i]);
     Paint_DrawBitMap(test[i]);
     EPD_5IN83_V2_Display(BlackImage);
     delay(NextSlideDelay * 1000);
  }
}
