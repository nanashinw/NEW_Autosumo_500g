#include "Newkub.h"

//total sensor
#define numsensor 5  // ---Change here
int pin[numsensor] = { 5, 6, 2, 7, 14 };
int MAX = 1;
int MIN = 0;
unsigned long F[numsensor];
int last_value = 0;
float leftmotor, rightmotor, position, lasterror, powermotor, error;

unsigned long S[2];
int pins[2] = { A1, A2 };
int MAXS[2] = { 700, 700 };
int MINS[2] = { 300, 300 };



void setup() {
  pinMode(PWM_L, OUTPUT);
  pinMode(PWM_R, OUTPUT);
  pinMode(DIR_L, OUTPUT);
  pinMode(DIR_R, OUTPUT);
  analogWrite(PWM_L, 0);
  analogWrite(PWM_R, 0);
  digitalWrite(DIR_L, LOW);
  digitalWrite(DIR_R, LOW);

  //view function
  // view();
  // ReadObs();
  // viewBatt();


  //Start module !!!!!!
  wait_SW8();

  switch (readDipSwitch()) {
    case 0:
      GO(70);
      break;
    case 1:
      motor(100, 100);
      delay(500);
      routine_pid(70);
      break;
    case 2:
      motor(50, 50);
      delay(1000);
      break;
    default:
      break;
  }
}

void loop() {
}