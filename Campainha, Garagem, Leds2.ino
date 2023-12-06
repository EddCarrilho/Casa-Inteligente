#include <Servo.h>
Servo servo1;
int state;
void setup() {
  servo1.attach(9);
  Serial.begin(9600);
  for (int i=3; i<7; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(12, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  static int state3 = 1;
  static int state4 = 1;
  int currentPosition = servo1.read();
  int buttonState = digitalRead(2);
  static int soundPlayed = 1;
  if (currentPosition == 180) {
        digitalWrite(4, !digitalRead(4));
        tone(12, 2500);
        delay(250);
        digitalWrite(4, !digitalRead(4));
        digitalWrite(5, !digitalRead(5));
        tone(12, 2000);
        delay(250);
        digitalWrite(5, !digitalRead(5));
  }
  if (buttonState == 1 && soundPlayed == 1) {
    tone(12, 1000);
    digitalWrite(6, HIGH);
    delay(500);
    noTone(12);
    soundPlayed = 0;
  }
  if (buttonState == LOW) {
    if (soundPlayed == 0) {
      tone(12, 800);
      delay(500);
      digitalWrite(6, LOW);
      noTone(12);

    soundPlayed = 1;
    }
  }
  if (Serial.available()) { 
      state = Serial.read();
  } 
    if (state == 49) {
      digitalWrite(3, !digitalRead(3));
      state = 0;
    } else if (state == 50) {
      digitalWrite(4, !digitalRead(4));
      state = 0;
      } else if (state == 51 && state3 == 1) {
      tone(12, 2000);
      servo1.write(90);
      delay(100);
      tone(12, 2500);
      servo1.write(100);
      delay(100);
      digitalWrite(4, !digitalRead(4));
      digitalWrite(5, !digitalRead(5));
      tone(12, 2000);
      servo1.write(110);
      delay(100);
      tone(12, 2500);
      servo1.write(120);
      delay(100);
      digitalWrite(4, !digitalRead(4));
      digitalWrite(5, !digitalRead(5));
      tone(12, 2000);
      servo1.write(130);
      delay(100);
      tone(12, 2500);
      servo1.write(140);
      delay(100);
      digitalWrite(4, !digitalRead(4));
      digitalWrite(5, !digitalRead(5));
      tone(12, 2000);
      servo1.write(150);
      delay(100);
      tone(12, 2500);
      servo1.write(160);
      delay(100);
      tone(12, 2000);
      servo1.write(170);
      delay(100);
      digitalWrite(4, !digitalRead(4));
      digitalWrite(5, !digitalRead(5));
      tone(12, 2500);
      servo1.write(180);
      state = 0;
      state3 = 0;
      state4 = 1;
      } else if (state == 52 && state4 == 1) {
        servo1.write(180);
        delay(100);
        tone(12, 2500);
        servo1.write(170);
        delay(100);
        digitalWrite(4, !digitalRead(4));
        digitalWrite(5, !digitalRead(5));
        tone(12, 2000);
        servo1.write(160);
        delay(100);
        tone(12, 2500);
        servo1.write(150);
        delay(100);
        digitalWrite(4, !digitalRead(4));
        digitalWrite(5, !digitalRead(5));
        tone(12, 2000);
        servo1.write(140);
        delay(100);
        tone(12, 2500);
        servo1.write(130);
        delay(100);
        digitalWrite(4, !digitalRead(4));
        digitalWrite(5, !digitalRead(5));
        tone(12, 2000);
        servo1.write(120);
        delay(100);
        tone(12, 2500);
        servo1.write(110);
        delay(100);
        tone(12, 2000);
        servo1.write(100);
        delay(100);
        digitalWrite(4, !digitalRead(4));
        digitalWrite(5, !digitalRead(5));
        tone(12, 2500);
        servo1.write(90);
        state = 0;
        state3 = 1;
        state4 = 0;
      } 
    noTone(12);
}
