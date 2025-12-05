#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keypad.h>
#include <ESP32Servo.h>
#include <WiFiEnterprise.h>
#include <WiFi.h>
#include <esp_eap_client.h>
#include <HTTPClient.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   23
#define OLED_CLK   18
#define OLED_DC    16
#define OLED_CS    17
#define OLED_RESET 5
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#define NUMFLAKES     10 // Number of snowflakes in the animation example
#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ 0b00000000, 0b11000000,
  0b00000001, 0b11000000,
  0b00000001, 0b11000000,
  0b00000011, 0b11100000,
  0b11110011, 0b11100000,
  0b11111110, 0b11111000,
  0b01111110, 0b11111111,
  0b00110011, 0b10011111,
  0b00011111, 0b11111100,
  0b00001101, 0b01110000,
  0b00011011, 0b10100000,
  0b00111111, 0b11100000,
  0b00111111, 0b11110000,
  0b01111100, 0b11110000,
  0b01110000, 0b01110000,
  0b00000000, 0b00110000 };

#define ROW_NUM     4 // four rows
#define COLUMN_NUM  4 // four columns
#define RETRY_LIMIT  20

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pin_rows[ROW_NUM]      = {13, 12, 14, 27}; // GPIO19, GPIO18, GPIO5, GPIO17 connect to the row pins
byte pin_column[COLUMN_NUM] = {26, 25, 33, 32};   // GPIO16, GPIO4, GPIO0, GPIO2 connect to the column pins

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

char userInput[4];
int userInputCount = 0;
char password[4] = {'1','2','3','4'};
bool flag = false;
bool correct = false;
float user = 1;
float id = 1;
const char* ssid = "LMH WiFi";
const char* username = "lmh23ihch";
const char* Password = "Cato0422";
static const int servoPin = 22;
Servo servo1;
bool lock = false;

void setup() {
  Serial.begin(115200);
  servo1.attach(servoPin);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);
  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
  // display.display(). These examples demonstrate both approaches...
  if (WiFiEnterprise.begin(ssid, username, Password, true)) {
    Serial.println("Connected successfully!");
    Serial.print("IP Address: ");
    Serial.println(WiFiEnterprise.localIP());
  } else {
    Serial.println("Connection failed!");
  }
  

}
void loop(){
  if (flag == false){
   Key();
   delay(100);
  }
  if (flag == true){
    WasFalse();
  }

}
void PassKey(char key) {
  ScreenSetUp();
  display.cp437(true);         // Use full 256 char 'Code Page 437' font
  display.print(key);
  Serial.println(key);

  display.display();
  //delay(2000);

  userInput[userInputCount++] = key;
  if (userInputCount == 4) {
    //Skriv et for loop hvor alle individuelle værdier i arrayet tjekkes.
    for (int i = 0; i < 4; i++){
      if(userInput[i] != password[i]){
        flag = true;
      }
    }
    if (flag == false){
      delay(100);
      ScreenSetUp();
      display.print("correct it is now open");
      display.display();
      int rtl = RETRY_LIMIT;
      delay(500);
      
      //Open a connection to the server
      HTTPClient http;
      http.begin("https://lmh-hx2-hold1.dk/lmh23ihch/upload.php");
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      //format your POST request.
      int httpResponseCode = http.POST("user=" + String(user) + "&id=" + String(id));

      if (httpResponseCode >0){
          //check for a return code - This is more for debugging.
        String response = http.getString();
        Serial.println(httpResponseCode);
        Serial.println(response);
      }
      else{
        Serial.print("Error on sending post");
        Serial.println(httpResponseCode);
      }
      //closde the HTTP request.
      http.end();
    
      //Monitor values in console for debugging.
      Serial.println("User = " + String(user));
      Serial.println("id = " + String(id));
      id++;
      servo1.write(0);
        for (int i = 0; i < 4; i++){
          userInput[i] = 0;
        }
      userInputCount = 0;

      delay(12000);
      //make some kind of, click this to lock insted of delay
      servo1.write(90);

    }  
   }
  }

void Key(){
  char key = keypad.getKey();
  lock = Locked(key);

  if (key) {
    PassKey(key);
  }
  if (lock){
    servo1.write(90);
    Serial.print("hello");
    lock = false;
  }
}

void WasFalse(){
  ScreenSetUp();
  display.println(F("Wrong input, pleas \ntry again"));

  // Reset all elements to 0
  for (int i = 0; i < 4; i++){
   userInput[i] = 0;
  }
  userInputCount = 0;

  display.display();

  servo1.write(90);
  delay(2000);
  flag = false;
  Key();
}

void ScreenSetUp(){
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
}

bool Locked(char key){
  if(key == '#'){
   return true;
  }
 else{
  return false;
 }
}