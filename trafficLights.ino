#include <Adafruit_NeoPixel.h>
#define LED_PIN 6
#define LED_COUNT 60
#include "RunningAverage.h"

RunningAverage myRA(20);
int samples = 0;
int sensorValue, caseCount;
int Run_ave;
  Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
void setup () 
{
//  Serial.begin (9600);
  myRA.clear();
  strip.begin();
}
void loop () 
{
  sensorValue = analogRead(A0);
  myRA.addValue(sensorValue);
  Run_ave = (myRA.getAverage());
  samples++;
//  Serial.print("Running Average: ");
//  Serial.println(Run_ave);
//  Serial.println("Reading:");
  
  uint32_t empty = strip.Color(0, 0, 0);
    
    if (sensorValue > Run_ave + 70)
    {
      uint32_t red = strip.Color(255, 0, 0);
      uint32_t blue = strip.Color(0, 0, 255);
      uint32_t magenta = strip.Color(128, 0, 128);
      
      for (int i=1; i<=3 ; i++){
      strip.fill(red, 0, 20);
      strip.fill(blue, 20, 20);
      strip.fill(magenta, 40, 20);
      strip.show();
      delay(200);
      strip.fill(magenta, 0, 20);
      strip.fill(red, 20, 20);
      strip.fill(blue, 40, 20);
      strip.show();
      delay(200);
      strip.fill(blue, 0, 20);
      strip.fill(magenta, 20, 20);
      strip.fill(red, 40, 20);
      strip.show();
      delay(200);
      }
      }

  else if (sensorValue > Run_ave + 50)
    {
      uint32_t red = strip.Color(255, 0, 0);
      uint32_t blue = strip.Color(0, 0, 255);
      Serial.println(sensorValue);
      for (int i=1; i<=3 ; i++){
      strip.fill(red, 0, 20);
      strip.fill(empty, 20, 20);
      strip.fill(empty, 40, 20);
      strip.show();
      delay(200);
      strip.fill(blue, 0, 20);
      strip.fill(empty, 20, 20);
      strip.fill(empty, 40, 20);
      strip.show();
      delay(200);
      }
    }
  else if (sensorValue > Run_ave + 25)
    {
      uint32_t red = strip.Color(255, 0, 0);
      Serial.println(sensorValue);
      strip.fill(red, 0, 20);
      strip.fill(empty, 20, 20);
      strip.fill(empty, 40, 20);
      strip.show();
      delay(500);
    }
  else if (sensorValue > Run_ave + 15)
    {
      uint32_t blue = strip.Color(0, 0, 255);
      strip.fill(empty, 0, 20);
      strip.fill(blue, 20, 20);
      strip.fill(empty, 40, 20);
      strip.show();
      delay(500);
    }
   else {
    uint32_t magenta = strip.Color(128, 0, 128);
    strip.fill(empty, 0, 20);
    strip.fill(empty, 20, 20);
    strip.fill(magenta, 40, 20);
    strip.show();
    delay(200);
   }
  if (samples == 300)
  {
    samples = 0;
    myRA.clear();
  }
  }
