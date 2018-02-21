/*
  Pull-Chain Switch: Basic Switch Example

  Toggles an LED on/off with a pull-chain switch.

  The circuit:
  * LED attached from pin 13 to ground
    * NOTE: Many Arduinos wire the onboard LED to pin 13.
  * Pull-chain switch attached to pin 2

  created 21 Feb 2018
  by Anthony Bui

  This example code is in the public domain.
*/

const int switchPin = 2;
const int ledPin =  13;

const int initialSwitchState;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  // NOTE: Initialize the switch state here because it
  // is difficult to tell the initial state of a pull-chain switch!
  initialSwitchState = digitalRead(switchPin);
}

void loop() {
  int switchReading = digitalRead(switchPin);

  if (switchReading == initialSwitchState) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
