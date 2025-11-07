#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   D23
#define OLED_CLK   D18
#define OLED_DC    RX2
#define OLED_CS    D5
#define OLED_RESET TX2

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

if(!display.begin(SSD1306_SWITCHCAPVCC))
{
   Serial.println(F("SSD1306 allocation failed"));
   for(;;); // Don't proceed, loop forever
  }