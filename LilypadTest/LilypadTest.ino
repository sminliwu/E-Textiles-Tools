// Lilypad test bed code

// pins
const int led = 13; // onboard LED
const int dPin = 2;

bool notConnected;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(dPin, INPUT_PULLUP); // digital input, HIGH when disconnected
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
}
