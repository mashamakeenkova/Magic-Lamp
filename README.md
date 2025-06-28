# Magic Lamp
TODO: add final result picture

## Required Materials
- 1 Arduino Nano
- 1 Push button
- 1 mini-USB cable
- jumper cables
- NeoPixel compatible LED strip, 5V. Note that if you want to use many LEDs, you may need to add a battery to power your circuit.
- Arduino IDE with the FastLED library installed
  
## Tutorial
### Step 1 - Creating the circuit
We will use the following diagram for our circuit. To connect the LED strip, solder the 5V input of the LED strip to the 5V output of the Arduino, the ground (GND) signals, and an output data pin (here we use D12) to the data input. Make sure to use the pin you have selected here in your code later. To connect the button, we connect one pin of the button to ground, and the other to a data output, here D2. Note that we do not need to use a resistor here, as we will define the button pin, pin 2, as `INPUT_PULLUP` in the code later.
![wiring_diagram](https://github.com/user-attachments/assets/4098d28b-34ca-4aad-843e-2d1779231f4c)

### Step 2 - Basic Code Setup
To program our LEDs, we will use the `FastLED` library. In the Arduino IDE, you can include the corresponding header file using `#include<FastLED.h>`. It may make sense to define some metrics at this stage that will not change for different light designs, such as the pins used and the number of LEDs on the strip that you have connected.
```cpp
#define NUM_LEDS 8    // number of LEDs present in your strip
#define BUTTON_PIN 2  // pin for the button
#define DATA_PIN 12   // data pin for the LED strip

CRGB leds[NUM_LEDS];  // array to access the individual LEDs
```
Next, we want to define a setup function, which will run once when the program is loaded onto our Arduino. Here we want to define the kinds of pins we want to use and initialize the LEDs. 
```
void setup() {
  pinMode(DATA_PIN, OUTPUT);           // define LED as an output
  pinMode(BUTTON_PIN, INPUT_PULLUP);   // define button as input with pull-up so we don't need a resistor
  
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}
```
Now that the setup is complete, you can write the `loop` function that is executed repeatedly while the Arduino is on. This is the function where you would want to check if a button is pressed, and react to such actions. For some ideas regarding possible designs, have a look at the `/code-examples` directory.

### Step 3 - 3D printing
TODO

### Step 4 - Assembly
TODO
