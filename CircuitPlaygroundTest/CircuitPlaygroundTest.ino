// Circuit Playground test bed code

#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>

// pins
const int led = 13; // onboard LED
const int dPin = A2; // digital input pin
const int aPin = A3; // analog input pin
const int slideSwitch = 7; // slide switch

bool notConnected;
bool analogMode;
int analogIn;

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  pinMode(led, OUTPUT);
  pinMode(dPin, INPUT_PULLUP); // digital input, HIGH when disconnected
  pinMode(aPin, INPUT); // analog input
  pinMode(slideSwitch, INPUT_PULLUP); // slide switch to toggle analog sensing
}

void loop() {
  // put your main code here, to run repeatedly:
  // LED response if connected
  notConnected = digitalRead(dPin);
  if (!notConnected) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  // analog input logic: 
  if (digitalRead(slideSwitch)) {    
    analogIn = analogRead(aPin); // 0-1023
    Serial.println(analogIn);
    int level = analogIn/100;
    int speakerTone = analogIn/2 + 500;
    for (int i = 0; i <= level; i++) {
      CircuitPlayground.setPixelColor(i, 255, 255, 255);
    }
    // CircuitPlayground.playTone(speakerTone, 100); I REGRET THIS
    CircuitPlayground.clearPixels();
  }
}
