/*
  Dimmer2

  Notes

  2020/08/13 - UPDATE: browsing the online Arduino docs I found a "moving average" library. Added
  that, and with the values as below, I am getting acceptable stability. Going with this code.

  2020/08/13 - It turns out that the analog reads of a potentiometer are inherently unstable, so I am
  getting values that jump around quite a bit. For this design, that means that there is a considerable
  amount of flickering when the LED's are dimmed. AFAIK (right now), there is no easy way around this (aside
  from replacing the potentiometer with a digital one, which I would not call "easy"), so for now, I am
  going to forgo having a smooth, linear dim behavior and use discrete steps for dimming, to try to "absorb"
  the instability of the analog reads.
*/
#include "CodeSwitch.h"

#ifdef DIMMER2

// #define DEBUG

#include <Arduino.h>
#include <MovingAverage.h>

const long potPin = A0;                 // gets the potentiometer voltage
const uint8_t MOSFET_GATE_PIN = 5;      // drives the MOSFET
const int numDimmingSteps = 15;     // number of discreet dimming steps
const int maxPotValue = 4096;       // the expected max value read from the pot

long divValue;
long potValue;
long modValue;
long mappedValue;
MovingAverage<long> potAvg(20);

// the setup function runs once when you press reset or power the board
void setup() {
#ifdef DEBUG
  Serial.begin(9600);
#endif
  pinMode(MOSFET_GATE_PIN, OUTPUT);
  pinMode(potPin, INPUT);
  divValue = maxPotValue / numDimmingSteps;
}

void loop() {
  potValue = analogRead(potPin);
  potAvg.push(potValue);
  modValue = potAvg.get() / divValue;
  mappedValue = map(modValue, 0, numDimmingSteps, 0, 255); //Map value 0-N to 0-255 (PWM)
#ifdef DEBUG
  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print(", Div: ");
  Serial.print(divValue);
  Serial.print(", Mod: ");
  Serial.print(modValue);
  Serial.print(", Mapped: ");
  Serial.println(mappedValue);
#endif
  analogWrite(MOSFET_GATE_PIN, mappedValue);
  delay(10);
}

#endif // DIMMER2