#include "CodeSwitch.h"

#ifdef SERIAL_TEST

#include <Arduino.h>

void setup() {
    Serial.begin(9600);
    Serial.println("setup()");
}

void loop() {
    delay(500);
    Serial.println("loop()");
}

#endif
