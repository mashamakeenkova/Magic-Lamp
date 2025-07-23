#include <FastLED.h>

#define NUM_LEDS 2
#define DATA_PIN 12
#define BUTTON_PIN 2

bool led_an = false;         // sind die LEDs an?
bool button_war = HIGH;      // waren sie vor Knopfdruck an?

CRGB leds[NUM_LEDS];

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);


}

void loop() {
  bool button_ist = digitalRead(BUTTON_PIN);
  if (button_war == HIGH && button_ist == LOW) {
    led_an = !led_an;

    if (led_an) {
      // TODO
    } else {
      // TODO
    }
    delay(500);
  }
  button_war = button_ist;
}
