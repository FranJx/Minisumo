#include <Arduino.h>
#include <Servo.h>

// defines sensor input pins
#define SENS0 8
#define SENS1 11
#define SENS2 12
#define SENS3 13
#define SENS4 A0
#define SENS5 A1
#define SENS6 A4
#define SENS7 A5
#define SENS8 A6 // only analog inputs
#define SENS9 A7 // only analog inputs

// defines motor and servo output pins
#define MA1 10
#define MA2 9
#define MB1 5
#define MB2 6
#define SERVO 3
Servo FLAG;

// defines remote and button input pin
#define REMOTE 4
#define BTN1 2
#define BTN2 7


void setup() {
  FLAG.attach(SERVO);
  pinMode(SENS0, INPUT);
  pinMode(SENS1, INPUT);
  pinMode(SENS2, INPUT);
  pinMode(SENS3, INPUT);
  pinMode(SENS4, INPUT);
  pinMode(SENS5, INPUT);
  pinMode(SENS6, INPUT);
  pinMode(SENS7, INPUT);
  pinMode(SENS8, INPUT);
  pinMode(SENS9, INPUT);

  pinMode(REMOTE, INPUT);

  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);
  FLAG.write(0);
  Serial.begin(9600);
}

void stop(int t){
  analogWrite(MA1,255);
  analogWrite(MA2,255);
  analogWrite(MB1,255);
  analogWrite(MB2,255);
  delay(t);
}

void off(){
  analogWrite(MA1,0);
  analogWrite(MA2,0);
  analogWrite(MB1,0);
  analogWrite(MB2,0);
}

void forwards(int a, int b, int t){
  analogWrite(MA1, a);
  digitalWrite(MA2, LOW);
  analogWrite(MB1, b);
  digitalWrite(MB2, LOW);
  delay(t);
}

void backwards(int t){
  digitalWrite(MA1, LOW);
  analogWrite(MA2, 255);
  digitalWrite(MB1, LOW);
  analogWrite(MB2, 255);
  delay(t);
}

void left(int a, int b, int t){
  analogWrite(MA1,a);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, LOW);
  analogWrite(MB2, b);
  delay(t);
}

void right(int a, int b, int t){
  digitalWrite(MA1, LOW);
  analogWrite(MA2, a);
  analogWrite(MB1, b);
  digitalWrite(MB2, LOW);
  delay(t);
}

byte sensval(){
  bool FRONT_R = digitalRead(SENS6);
  byte FRONT_L = digitalRead(SENS7) * 2;
  byte RIGHT = digitalRead(SENS5) * 4;
  byte LEFT = digitalRead(SENS4) *8;
  byte total = FRONT_R + FRONT_L + RIGHT + LEFT;
  return total;
}

byte lineval(){
  bool LINE_R = digitalRead(SENS3);
  byte LINE_L = digitalRead(SENS4) * 2;
  byte total = LINE_R + LINE_R;
  return total;
}

void loop() {
  // forwards(255,255,1000);
  // stop(100);
  // backwards(300);
  while (digitalRead(REMOTE)==HIGH){
    switch (sensval()){
    case 0:
      stop(75);
      backwards(175);
      right(255, 255, 175);
      break;
    
    case 1:
      stop(25);
      backwards(150);
      right(255, 255, 100);
      break;

    case 2:
      stop(25);
      backwards(150);
      left(255, 255, 100);
      break;

    case 3:
      switch (sensval()){
        case 1:
          adelante(75,100,20);
          break;

        case 2:
          adelante(100,75,20);
          break;

        case 3:
          adelante(255,255,30);
          break;

        case 4:
          derecha(255,255,20);
          break;

        case 5:
          derecha(255,255,15);
          break;

        case 7:
          derecha(255,255,50);
          break;
          
        case 8:
          izquierda(255,255,20);
          break;

        case 10:
          izquierda(255,255,15);
          break;

        case 11:
          izquierda(255,255,50);
          break;

        case 15:
          adelante(175,175,30);
          break;

        default:
          adelante(15,15,5);
          break;
      }
      break;
    }
  }
}

