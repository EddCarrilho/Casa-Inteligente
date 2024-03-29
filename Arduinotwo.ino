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
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
}

void loop() {

  luzQuarto();
  luzSala();
  bluetooth();
  campainha();
  //sensorluminosidade();
  garagemFechando();
  garagemAberta();
  noTone(12);
}
  void bluetooth() {
    if (Serial.available()) { 
      state = Serial.read();
    }
  }
  void campainha() {
    int buttonState = digitalRead(2);
    static int soundPlayed = 1;
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
  }
  void luzQuarto() {
    if (state == 49) {
      digitalWrite(3, !digitalRead(3));
      state = 0;
    }
  }
  void luzSala() {
    if (state == 50) {
      digitalWrite(4, !digitalRead(4));
      state = 0;
    }
  }
  void garagemAberta() {
    static int state3 = 1;
    int currentPosition = servo1.read();
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
    if (state == 51 && state3 == 1) {
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
    }
  }
  void garagemFechando() {
    static int state3 = 1;
    if (state == 52) {
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
    }
  }