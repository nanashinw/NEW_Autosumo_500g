#include "CytronMakerSumo.h"
//https://th.cytron.io/p-maker-mini-sumo-controller-simplifying-sumo-robot-for-beginner

//My github : https://github.com/nanashinw

#define RR 14
#define M 2
#define L 6
#define R 7
#define LL 5

#define Light_L A1
#define Light_R A2

void setup() {
  // put your setup code here, to run once:
  MakerSumo.begin();
  Serial.begin(9600);
  pinMode(RR, INPUT_PULLUP);
  pinMode(M, INPUT_PULLUP);
  pinMode(L, INPUT_PULLUP);
  pinMode(R, INPUT_PULLUP);
  pinMode(LL, INPUT_PULLUP);

  pinMode(Light_L, INPUT);
  pinMode(Light_R, INPUT);

  while (digitalRead(START));
  while (!digitalRead(START));
}

void loop() {
  
  // Serial.print(analogRead(A6));

  GO(200);
}
void GO(int Speed) {
  while (1) {
    int ll = digitalRead(LL);
    int l = digitalRead(L);
    int m = digitalRead(M);
    int r = digitalRead(R);
    int rr = digitalRead(RR);
    int light_L = analogRead(Light_L);
    int light_R = analogRead(Light_R);
  if (light_L < 500 && light_R > 500) {
    MakerSumo.setMotorSpeed(MOTOR_L, -Speed);
    MakerSumo.setMotorSpeed(MOTOR_R, -Speed);
    delay(200);
    MakerSumo.setMotorSpeed(MOTOR_L, Speed);
    MakerSumo.setMotorSpeed(MOTOR_R, -Speed);
    delay(230);
  }
  if (light_L > 500 && light_R < 500) {
    MakerSumo.setMotorSpeed(MOTOR_L, -Speed);
    MakerSumo.setMotorSpeed(MOTOR_R, -Speed);
    delay(200);
    MakerSumo.setMotorSpeed(MOTOR_L, -Speed);
    MakerSumo.setMotorSpeed(MOTOR_R, Speed);
    delay(230);
  }
  else {
    Track(200);
  }
}
}
void Track(int Speed) {
  int ll = digitalRead(LL);
  int l = digitalRead(L);
  int m = digitalRead(M);
  int r = digitalRead(R);
  int rr = digitalRead(RR);
  if (ll == 1 && l == 1 && m == 0 && r == 1 && rr == 1) {
    MakerSumo.setMotorSpeed(MOTOR_L, Speed);
    MakerSumo.setMotorSpeed(MOTOR_R, Speed);
  } else if (ll == 1 && l == 0 && m == 0 && r == 0 && rr == 1) {
    MakerSumo.setMotorSpeed(MOTOR_L, Speed);
    MakerSumo.setMotorSpeed(MOTOR_R, Speed);
  } else if (ll == 1 && l == 0 && m == 0 && r == 1 && rr == 1) {
    MakerSumo.setMotorSpeed(MOTOR_L, Speed);
    MakerSumo.setMotorSpeed(MOTOR_R, Speed);
  } else if (ll == 1 && l == 0 && m == 1 && r == 1 && rr == 1) {
    MakerSumo.setMotorSpeed(MOTOR_L, -Speed);
    MakerSumo.setMotorSpeed(MOTOR_R, Speed);
    delay(50);
  } else if (ll == 0 && l == 0 && m == 1 && r == 1 && rr == 1) {
    MakerSumo.setMotorSpeed(MOTOR_L, -Speed);
    MakerSumo.setMotorSpeed(MOTOR_R, Speed);
    delay(100);
  } else if (ll == 0 && l == 1 && m == 1 && r == 1 && rr == 1) {
    MakerSumo.setMotorSpeed(MOTOR_L, -Speed);
    MakerSumo.setMotorSpeed(MOTOR_R, Speed);
    delay(150);
  } else if (ll == 1 && l == 1 && m == 0 && r == 0 && rr == 1) {
    MakerSumo.setMotorSpeed(MOTOR_L, Speed);
    MakerSumo.setMotorSpeed(MOTOR_R, Speed);
  } else if (ll == 1 && l == 1 && m == 1 && r == 0 && rr == 1) {
    MakerSumo.setMotorSpeed(MOTOR_L, Speed);
    MakerSumo.setMotorSpeed(MOTOR_R, -Speed);
    delay(50);
  } else if (ll == 1 && l == 1 && m == 1 && r == 0 && rr == 0) {
    MakerSumo.setMotorSpeed(MOTOR_L, Speed);
    MakerSumo.setMotorSpeed(MOTOR_R, -Speed);
    delay(100);
  } else if (ll == 1 && l == 1 && m == 1 && r == 1 && rr == 0) {
    MakerSumo.setMotorSpeed(MOTOR_L, Speed);
    MakerSumo.setMotorSpeed(MOTOR_R, -Speed);
    delay(150);
  } else {
    MakerSumo.setMotorSpeed(MOTOR_L, 150);
    MakerSumo.setMotorSpeed(MOTOR_R, 150);
  }
}
  // int ll = digitalRead(LL);
  // int l = digitalRead(L);
  // int m = digitalRead(M);
  // int r = digitalRead(R);
  // int rr = digitalRead(RR);

  // int light_L = analogRead(Light_L);
  // int light_R = analogRead(Light_R);

  // //Serial.println(light_L);

  // MakerSumo.setMotorSpeed(MOTOR_L, 100);
  // MakerSumo.setMotorSpeed(MOTOR_R, 100);
  //GO(200);

