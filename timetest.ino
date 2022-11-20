// - ST7789 Clock Demo v1.0 by Oldmate6288 (https://github.com/OldMate6288)
// - Time Library: https://github.com/3tawi/PicoEspTime
// MAKE SURE YOU HAVE ST7789 & ADAFRUIT GFX LIBRARIES INSTALLED!!!

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <PicoEspTime.h>
#include <Wire.h>
#include <SPI.h>

PicoEspTime rtc;

#define PIN_LED  7  // 6 - R, 7 - G, 8 - B

#define TFT_CS   17 // Chip select
#define TFT_RST  -1 // Or set to RUN pin (-1) if no reset pin has been specified
#define TFT_DC   16 // Data command
#define TFT_MOSI 19 // Data out
#define TFT_SCLK 18 // Clock out

// For the ST7789-based displays, we will use this call
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

uint32_t lastTime; 
String   texttime;
//bool     flasher; // Unused for now, doesn't work well with the 1 min delay

byte ledState = LOW;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  ledState = LOW;
  Serial.begin(9600);
  Serial.print(F("Hello! ST7789 TFT Test"));

  tft.init(135, 240);           // Init ST7789 240x135

  // SPI speed defaults to SPI_DEFAULT_FREQ defined in the library, you can override it here
  // Note that speed allowable depends on chip and quality of wiring, if you go too fast, you
  // may end up with a black screen some times, or all the time.
  //tft.setSPISpeed(40000000);

  Serial.println(F("Initialized"));

  uint16_t time = millis();
  tft.fillScreen(ST77XX_BLACK);
  tft.setRotation( 3 );
  tft.setCursor(45, 116);
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(1);
  tft.println("PICO CLOCK V1 - BY OLDMATE");
  time = millis() - time;

  Serial.println(time, DEC);
  delay(500);
  rtc.adjust(18, 05, 00, 2022, 11, 20); // 06:05:00pm 20 Nov 2022
}
void loop() {
  
   if(millis() - lastTime >= 1000) {
    rtc.read(); 
    PrintTime();
    //SecTime();
    //flasher = !flasher; 
    lastTime = millis();
    digitalWrite(PIN_LED, LOW);
    delay(1000);
    digitalWrite(PIN_LED, HIGH);
    delay(1000);
    delay(58000); // Disable the 4 lines above and change the delay to 60000 for a one minute delay between screen refreshes (without led blinking every minute)
    }
}
void PrintTime()
{    
// formating options  https://www.cplusplus.com/reference/ctime/strftime/

    tft.fillRoundRect(50, 29, 150, 23, 8, ST77XX_WHITE);
    tft.fillRoundRect(30, 78, 190, 22, 8, ST77XX_WHITE);
    tft.setCursor(70, 30);
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(3);
    tft.println(rtc.getTime("%I:%M"));
    tft.setCursor(165, 30);
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(2);
    tft.println(rtc.getTime("%p"));
    tft.setCursor(35, 80);
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(2);
    tft.println(rtc.getTime("%a %d-%b-%Y"));
} 

void SecTime() // Unused for now until I can find a way to refresh this outside of the main loop delay
{ 
    tft.fillRoundRect(1, 110, 20, 20, 8, ST77XX_WHITE);
    tft.setCursor(5, 116);
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(1);
    tft.println(rtc.getTime("%S"));
} 
