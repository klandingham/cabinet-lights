/*
 * Tests to see if the distance sensor works by itself.
 * I wrote this because I am getting erratic readings in the main program,
 * and suspect there may be some interaction between other outputs and
 * the sensor.
 */
#include "CodeSwitch.h"

#ifdef DIST_SENSOR_TEST

#include <Arduino.h>
#include <HCSR04.h>

const uint8_t LED_PIN = 0;
const uint8_t MOSFET_GATE_PIN = 5;
const uint16_t DELAY = 500;
int brightness = 0;
int fadeamount = 5;
int dimmingDelay = 500;
int loopDelay = 1000;

UltraSonicDistanceSensor distanceSensor(9, 10);  // initialize a sensor on digital pins 13 (trigger) and 12 (echo)

double distance;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(MOSFET_GATE_PIN, OUTPUT);
  loopDelay = dimmingDelay;
}

void loop() {
  delay(loopDelay);
  distance = distanceSensor.measureDistanceCm();
  Serial.print("Measured distance = ");
  Serial.println(distance);
} // loop()
#endif
