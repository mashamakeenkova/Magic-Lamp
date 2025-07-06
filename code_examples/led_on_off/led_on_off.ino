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
  FastLED.clear();
  FastLED.show();

}

void loop() {
  bool button_ist = digitalRead(BUTTON_PIN);
  if (button_war == HIGH && button_ist == LOW) {
    led_an = !led_an;

    if (led_an) {
     turnOnLeds();
    } else {
     turnOffLeds();
    }
    delay(50);
  }
  button_war = button_ist;
}

void turnOnLeds() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
  }
  FastLED.show();
}

void turnOffLeds() {
  FastLED.clear();
  FastLED.show();
}
