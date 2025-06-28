#include <stdio.h>
#include <stdlib.h>
#include<FastLED.h>

#define NUM_LEDS 8    // number of led present in your strip
#define BUTTON_PIN 2  // pin for the button
#define DATA_PIN 12   // digital pin of your arduino


CRGB leds[NUM_LEDS];
int status = false;   // set status to false by default

void setup() {
  pinMode(DATA_PIN, OUTPUT);           // define LED as an output
  pinMode(BUTTON_PIN, INPUT_PULLUP);   // define button as input with pull-up so we don't need resistor
  
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}


void loop() {
   if (!digitalRead(BUTTON_PIN) == true) {
    status = !status;
   }
  toggle(status);
  delay(100);
}

void toggle(bool status){
  if (status == true) {
    red_moving();
  } else {
    off();
  }
}

void red_moving() {
  for (int i = 0; i < NUM_LEDS; i++) {
      if (!digitalRead(BUTTON_PIN) == true) {
        off();
        delay(100); 
        return;
      }
      leds[i] = CRGB::Red;
      FastLED.show();
      delay(100);
      leds[i] = CRGB::Black;
      FastLED.show();
   }
 }

void off() {
  status = false;
  for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Black;
   }
   FastLED.show();
}
