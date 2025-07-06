#include <FastLED.h>

#define NUM_LEDS 8
#define DATA_PIN 12
CRGB leds[NUM_LEDS];

void setup() {
  // sets the first LED of the strip to a red color
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  
  leds[0] = CRGB::Red;
  FastLED.show();
}

void loop() {
  // put your main code here, to run repeatedly:

}
