int ledPin = 2;
int buttonPin = 25;

int brightPotPin = A0;
int brightPotValue = 0;
int brightnessLed = 0;

int commit = 1;

bool buttonState = LOW;
bool lastButtonState = LOW;
bool buttonOn = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  brightPotValue = analogRead(A0);
  brightnessLed = map(brightPotValue, 0, 1023, 0, 255);
  lastButtonState = buttonState;
  buttonState = digitalRead(buttonPin);

  if (lastButtonState == LOW and buttonState == HIGH) {
    buttonOn = !buttonOn;
    delay(5);
  } else if (lastButtonState == HIGH and buttonState == LOW) {
    delay(5);
  }

  if (buttonOn == true) {
    analogWrite(ledPin, brightnessLed);
  }
  else {
    analogWrite(ledPin, 0);
  }
}
