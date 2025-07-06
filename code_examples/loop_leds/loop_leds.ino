#include <FastLED.h>

#define NUM_LEDS 8
#define DATA_PIN 12
CRGB leds[NUM_LEDS];

void setup() {
  // sets all LEDs to a red color
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  
  for (int i=0; i<NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
  }
  FastLED.show();
}

void loop() {
  // put your main code here, to run repeatedly:

}
