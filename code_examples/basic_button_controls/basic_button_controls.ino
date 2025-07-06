#include <FastLED.h>

#define NUM_LEDS 2
#define DATA_PIN 12
#define BUTTON_PIN 2

CRGB leds[NUM_LEDS];


void setup() {
   pinMode(BUTTON_PIN, INPUT_PULLUP);

  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.show();

  Serial.begin(9600);
}

void loop() {
  // the LEDs are turned on while the button is pressed
  if (digitalRead(BUTTON_PIN) == LOW) {
    Serial.println("Button pressed - turning LEDs ON");
    for (int i=0; i<NUM_LEDS; i++) {
      leds[i] = CRGB::Red;
    }
    FastLED.show();
   } else {
    Serial.println("Button released - turning LEDs OFF");
    FastLED.clear();
    FastLED.show();
   }
   delay(100);  // debounce delay

}
