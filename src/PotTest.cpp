/*
 * PotTest
 *
 * Tests reading values from potentiometer. Values are mapped from 0 -> 255.
 */

#include <Arduino.h>
#include "CodeSwitch.h"
#ifdef POT_TEST

// constants
const int ledPin = 9;  //pin 9 has PWM funtion
const int potPin = A0; //pin A0 to read analog input

// variables
int potValue;

void setup() {
    // pins setup
    pinMode(ledPin, OUTPUT);
    pinMode(potPin, INPUT);
    Serial.begin(9600);
}

void loop(){
    potValue = analogRead(potPin);          //Read and save analog value from potentiometer
    Serial.print("Pot value = ");
    potValue = map(potValue, 0, 1023, 0, 255); //Map value 0-1023 to 0-255 (PWM)
    // analogWrite(ledPin, potValue );          //Send PWM value to led
    delay(100);                          //Small delay
}

//  Turns an LED on for one second, then off for one second, repeatedly.
//
//  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
//  it is attached to digital pin 14, on MKR1000 on pin 6. LED_BUILTIN is set to
//  the correct LED pin independent of which board is used.
//  If you want to know what pin the on-board LED is connected to on your Arduino
//  model, check the Technical Specs of your board at:
//  https://www.arduino.cc/en/Main/Products
//
//  modified 8 May 2015
//  by Scott Fitzgerald
//  modified 2 Sep 2016
//  by Arturo Guadalupi
//  modified 8 Sep 2016
//  by Colby Newman
//
//  This example code is in the public domain.
//
//  http://www.arduino.cc/en/Tutorial/Blink
//*/
//#include "CodeSwitch.h"
//
//#ifdef BLINK_TEST
//
//#include <Arduino.h>
//#include <HCSR04.h>
//
//// const uint8_t LED_PIN = LED_BUILTIN;
//const uint8_t LED_PIN = 0;
//// const uint8_t MOSFET_GATE_PIN = 9;
//const uint8_t MOSFET_GATE_PIN = 5;
//const uint16_t DELAY = 500;
//int brightness = 0;
//int fadeamount = 5;
//int dimmingDelay = 50;
//int loopDelay;
//
//UltraSonicDistanceSensor distanceSensor(9, 10);  // initialize a sensor on digital pins 13 (trigger) and 12 (echo)
//float distance;
//
//// the setup function runs once when you press reset or power the board
//void setup() {
//#ifdef DEBUG
//  Serial.begin(9600);
//#endif
//  // initialize digital pin LED_BUILTIN as an output.
//  pinMode(LED_PIN, OUTPUT);
//  pinMode(MOSFET_GATE_PIN, OUTPUT);
//  loopDelay = dimmingDelay;
//}
//
//// the loop function runs over and over again forever
//void loop() {
//  analogWrite(MOSFET_GATE_PIN, brightness);
//  // brightness = brightness + fadeamount;
//  // if ((brightness <= 0) || (brightness >= 255))
//  //   fadeamount = -fadeamount;
//  delay(loopDelay);
//  distance = distanceSensor.measureDistanceCm();
//  if ((distance < 20.0) && (distance > 0.0)) {
//    brightness = brightness + fadeamount;
//    if ((brightness >= 255) || (brightness <= 0)) {
//      loopDelay = 2000; // "pause" at full on or off
//    }
//    else {
//      loopDelay = dimmingDelay;
//    }
//    if ((brightness <= 0) || (brightness >= 255)) {
//      fadeamount = -fadeamount;
//    }
//  }
//#ifdef DEBUG
//  Serial.println(distance);
//#endif
//}
#endif
