# E-Paper-ESP32-slideshow
A simple Arduino program to cycle through images over SPI on an ESP32 microcontroller. Uses an E-paper display and ESP32 E-paper driver board from Waveshare. This project will only work with this board as it uses libraries from Waveshare to function. Based on a modified example from Waveshare. [Also includes a JPEG to HEX converter specifically for this product line.](https://github.com/Wh1teRabbitHU/ImageToEpaperConverter) Converter was not made by me, credit goes to [WhiteRabbit](https://github.com/Wh1teRabbitHU).
<br/>This will likely only work with the [board](https://www.waveshare.com/product/displays/e-paper/driver-boards/e-paper-esp32-driver-board.htm) I am using.
## Set-up
### Applying dithering and re-scaling or use [didder](https://github.com/makew0rld/didder)
Didder example command (B/W) `didder -i "*.jpg" -o "M:\Media\Downloads" --palette "black white" --recolor "black white" -x 648 -y 480 -s 80% -g edm --serpentine FloydSteinberg`
This requires Adobe Photoshop. Other imaging editing tools will probably work, it's just what I used. All it's needed for is to change the resolution to your screen size and set the colour table for dithering purposes.
#### Import image, then File -> Export -> Save for Web (Legacy)
![image](https://user-images.githubusercontent.com/64732379/161347063-66d2c573-0c0a-45e0-aea9-8d1b31fece0d.png)
#### Change the resolution to match your panel
![image](https://user-images.githubusercontent.com/64732379/161347248-11ca1a12-2e64-4c76-bf83-d1f84acc5e26.png)
#### Colour Palette Menu -> Load Colour Table
![image](https://user-images.githubusercontent.com/64732379/161347475-5b07238a-ce9f-4a92-97c8-9b42a778b27f.png)
#### Go to the Colour Table folder included, Colour Tables -> (Choose the one most suitable for your display)
![image](https://user-images.githubusercontent.com/64732379/161352089-ee440b72-90fb-45f0-9eab-4e785df5fb56.png)
#### Save, then upload to any GIF -> JPEG converter
[This one will do](https://convertio.co/gif-jpeg/)
#### Done! For now...
### Converting into HEX
#### Put the converted file into the folder: Tools and Links -> ImageToEPaperConverter
![image](https://user-images.githubusercontent.com/64732379/161354746-ce1039c8-0462-44f0-baa5-1b851f0f48fe.png)
#### Rename to ```picture.jpeg``` (Has to be .jpeg, not .jpg)
![image](https://user-images.githubusercontent.com/64732379/161354820-109d1a85-d824-4283-a74b-0fb3a0dcb88d.png)
#### In the Options folder, edit the default.json file to fit your screen (notepad will do for this). you should only need to do this once.
![image](https://user-images.githubusercontent.com/64732379/161354930-e317ab12-8703-4ff9-8f4d-292706840205.png)
#### Go up one folder, then open a terminal there (click on the directory bar and type ```cmd```)
![image](https://user-images.githubusercontent.com/64732379/161355142-a518f5a7-4751-4763-baeb-31ba7cb137db.png)
#### Run the command ```node standalone```, if it went successfully should look like the following:
![image](https://user-images.githubusercontent.com/64732379/161355206-b885dc09-6eb3-422e-bdd8-e505eceeca16.png) <br/>
If there is an error check picture file name is ```picture.jpeg```, or ask around.
#### In the output folder, grab the ```ImagesData.cpp``` file and move it to the (root directory) -> Images - Processed -> HEX. Rename if you like.
![image](https://user-images.githubusercontent.com/64732379/161355527-996bf39c-38e3-4c84-90f2-736b9630625d.png)
->
![image](https://user-images.githubusercontent.com/64732379/161356076-cffbf531-9b9e-431e-8976-51d31c1dd540.png)
#### In the Arduino IDE (linked at bottom), go to the tab Sketch -> Add file, then add the .cpp file you just made.
![image](https://user-images.githubusercontent.com/64732379/161355614-542cc6cf-f293-4ddb-80a1-f425a8ccfea1.png)
It should appear as a tab.
#### In the picture.cpp (or whatever you called it) tab, change the ```Picture``` in ```const unsigned char Picture[]``` to something that makes sense. <br/>
![image](https://user-images.githubusercontent.com/64732379/161355725-ba1aacc4-79b2-44fa-b6e3-64b49d1b3ca3.png)
-> <br/>
![image](https://user-images.githubusercontent.com/64732379/161356025-cbaf47d7-571b-4aaa-af4b-e42e9e307f35.png)
#### Then in the ImagesData **.h** tab, add ```extern const unsigned char (YourPictureName)[];```
![image](https://user-images.githubusercontent.com/64732379/161355862-e838c984-24f0-4ade-8a27-8a003d29c4c9.png)
### Configuring to your liking
#### In the main tab, highlight ```REPLACE_WITH_YOUR_DISPLAY``` (anywhere in the code) and press CRTL-F or CMD-F
![image](https://user-images.githubusercontent.com/64732379/161408658-ff209ed6-3c3d-462b-b744-adf1915e057c.png)<br/>
#### In the "Replace with:" box add your [display code](DISPLAY.md), then press "Replace All"
![image](https://user-images.githubusercontent.com/64732379/161408683-ffbe691a-6754-449b-90e6-10aa2064f7fd.png)
#### Change ```{Arduino,ShrekImg,UnionJack}``` to the names of your pictures as in [this](https://github.com/RJGns/E-Paper-ESP32-slideshow/blob/main/README.md#in-the-picturecpp-or-whatever-you-called-it-tab-change-the-picture-in-const-unsigned-char-picture-to-something-that-makes-sense-), seperated by a comma
![image](https://user-images.githubusercontent.com/64732379/161408760-a63bd1b0-830d-437d-98bd-dca623d8f786.png)
#### Change ```NumberOfImages``` to the number of images you want to cycle through
![image](https://user-images.githubusercontent.com/64732379/161408769-1706167e-6a7a-43f7-8498-50f1ad36ebc1.png)
#### Change ```NextSlideDelay``` to the amount of time inbetween slides, in seconds
![image](https://user-images.githubusercontent.com/64732379/161408787-bae818fd-d4c2-458e-9c7e-727cf5b4f5c8.png)
#### Done!
## Troubleshooting
### If error is something about ```#include "DEV_Config.h"``` does not exist or something
#### Import needed libraries from Waveshare
#### or add ```E-Paper-ESP32-slideshow\Tools and Links\E-Paper_ESP32_Driver_Board_Code\examples\esp32-waveshare-epd``` to ``` (YOUR_ARDUINO_SKETCHBOOK_DIRECTORY)/libraries```
### Image doesn't look right
#### Try a differnet display code
####  Flick the number 2 DIP switch on your board to the other position
#### Re-do photoshop steps, maybe you set the wrong resolution
### I have a colour display, but this isn't colour
#### Make sure you used the right colour table in the Photoshop steps
#### I don't have a colour display to test to see if that works, are you sure you bought a colour display?


### [Useful links](Tools%20and%20Links/README.md)
### [Display Codes](DISPLAY.md)
### [Demo Photo Frame](https://youtu.be/OXD3FgrKEKg)
