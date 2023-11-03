const int buttonPin = 2;
const int LEDGreen = 13;
const int LEDYellow = 12;
const int LEDRed = 11;

int buttonState = 0;
int i = 0;
bool pressed = false;

void setup() {
  pinMode(LEDGreen, OUTPUT);
  pinMode(LEDYellow, OUTPUT);
  pinMode(LEDRed, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != pressed) {
    digitalWrite(LEDGreen, HIGH);
    digitalWrite(LEDRed, LOW);
    digitalWrite(LEDYellow, LOW);
  } else {
      digitalWrite(LEDGreen, LOW);
      digitalWrite(LEDRed, HIGH);
      digitalWrite(LEDYellow, HIGH);
      delay(200);
      digitalWrite(LEDRed, LOW);
      digitalWrite(LEDYellow, LOW);
      while(digitalRead(buttonPin) != pressed && i < 4)
      {
        delay(200);
        i++;
      }
      i = 0;
  }
}
