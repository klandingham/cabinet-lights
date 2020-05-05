#include "CodeSwitch.h"

#ifdef DIMMER

/*
  Dims and brightens LED strip(s) using a distance sensor.
*/

#include <Arduino.h>
#include <HCSR04.h>

// const uint8_t LED_PIN = LED_BUILTIN;
const uint8_t LED_PIN = 0;
// const uint8_t MOSFET_GATE_PIN = 9;
const uint8_t MOSFET_GATE_PIN = 5;
const uint16_t DELAY = 500;
int brightness = 0;     // controls MOSFET gate
int fadeamount = 10;    // amount by which brightness changes per loop
int dimmingDelay = 25;  // time in mS for each level change
int pauseDelay = 2000;  // mS time input is ignored (used by flash routine)
int flashDelay = 250;   // mS time of one flash

UltraSonicDistanceSensor distanceSensor(9, 10);  // initialize a sensor on digital pins 13 (trigger) and 12 (echo)
double distance;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOSFET_GATE_PIN, OUTPUT);
}

// Flash the LED's - used to give a visual indication of having reached a brightness limit.
void flashLEDs(bool endON) {
    Serial.println("FLASH");
    if (endON) {
        brightness = 255;
        analogWrite(MOSFET_GATE_PIN, 0);
        delay(flashDelay);
        analogWrite(MOSFET_GATE_PIN, brightness);
        delay(pauseDelay);
    }
    else {
        brightness = 0;
        analogWrite(MOSFET_GATE_PIN, 20);
        delay(flashDelay);
        analogWrite(MOSFET_GATE_PIN, brightness);
        delay(pauseDelay);
    }
    delay(pauseDelay);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("Setting brightness = ");
  Serial.println(brightness);
  analogWrite(MOSFET_GATE_PIN, brightness);
  // brightness = brightness + fadeamount;
  // if ((brightness <= 0) || (brightness >= 255))
  //   fadeamount = -fadeamount;
  delay(dimmingDelay);
  distance = distanceSensor.measureDistanceCm();
  Serial.print("Measured distance = ");
  Serial.println(distance);
  // Note: sensor I am using sometimes reports 0.5 with nothing in its
  // range! This causes the LEDs to fade a little after reaching full
  // brightness. To remedy this, I am changing the minimum distance
  // from 0 to 2.0.

  if ((distance < 40.0) && (distance > 2.0)) {
    Serial.print("Adjusted brightness = ");
    Serial.println(brightness);
    brightness = brightness + fadeamount;
    if (brightness <= 0) {
        flashLEDs(false);
    }
    else if (brightness >= 255) {
        flashLEDs(true);
    }
    if ((brightness <= 0) || (brightness >= 255)) {
      fadeamount = -fadeamount;
    }
  }
} // loop()

#endif
