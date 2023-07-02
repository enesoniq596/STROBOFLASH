#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


#include "PWM.h"
int pwm_pin=9;
int32_t frekans=1;
int pot = A0; 
int frequency;

void setup() 
{
InitTimersSafe();
pinMode(A0, INPUT);

if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("ATA SEVINC");
  display.setCursor(0, 35);
  display.println("BITIRME  1");
  display.display(); 
  delay(2000);
 display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("");
  display.display(); 
}

void loop()
{
  Serial.begin(115200);
pot = analogRead (A0);
frekans=  map(pot,0,1023,9010,301);
Serial.println(frekans);      
SetPinFrequencySafe(pwm_pin, frekans);
pwmWrite(pwm_pin,107);
frequency=frekans/60;
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("freq");
  display.setCursor(55, 0);
  display.println(frequency);
  display.display(); 
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);
  display.println("rpm");
  display.setCursor(42, 20);
  display.println(frekans-10);
  display.display(); 
  delay(50);

}