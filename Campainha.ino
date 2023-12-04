void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(9);
  static int soundPlayed = 1;

  if (buttonState == 1 && soundPlayed == 1) {
    tone(6, 1000);
    digitalWrite(3, HIGH);
    delay(500);
    noTone(6);
    soundPlayed = 0;
  }
  if (buttonState == LOW) {
    if (soundPlayed == 0) {
      tone(6, 800);
      delay(500);
      digitalWrite(3, LOW);
      noTone(6);

    soundPlayed = 1;
    }
  }
}
