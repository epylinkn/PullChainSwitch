/*
  Pull-Chain Switch: Multiple States Example

  Simulating a multi-throw pull-chain switch.

  The circuit:
  * Pull-chain switch attached to pin 2

  created 21 Feb 2018
  by Anthony Bui

  This example code is in the public domain.
*/

const int switchPin = 2;

int switchState = 0;
int numSwitchStates = 3;
int oldSwitchReading;

void setup() {
  Serial.begin(9600);

  pinMode(switchPin, INPUT_PULLUP);

  // NOTE: Initialize the switch state here because it
  // is difficult to tell the initial state of a pull-chain switch!
  oldSwitchReading = digitalRead(switchPin);
}

void loop() {
  int switchReading = digitalRead(switchPin);

  if (switchReading != oldSwitchReading) {
    switchState++;
    switchState = switchState % numSwitchStates;
  }

  oldSwitchReading = switchReading;

  Serial.println("READING \t STATE");
  Serial.print(switchReading);
  Serial.print("\t");
  Serial.println(switchState);
}
