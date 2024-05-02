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
int MAXS[2] = { 920,	918 };
int MINS[2] = { 48,	45 };



void setup() {
  pinMode(PWM_L, OUTPUT);
  pinMode(PWM_R, OUTPUT);
  pinMode(DIR_L, OUTPUT);
  pinMode(DIR_R, OUTPUT);
  pinMode(RR, INPUT_PULLUP);
  pinMode(M, INPUT_PULLUP);
  pinMode(L, INPUT_PULLUP);
  pinMode(R, INPUT_PULLUP);
  pinMode(LL, INPUT_PULLUP);
  pinMode(Light_L, INPUT);
  pinMode(Light_R, INPUT);
  analogWrite(PWM_L, 0);
  analogWrite(PWM_R, 0);
  digitalWrite(DIR_L, LOW);
  digitalWrite(DIR_R, LOW);

  //view function
  // view();
  // viewdiff();
  // viewReadObs();
  // viewBatt();
  // viewIR();
  // viewIRraw();
  

  //Start module !!!!!!
  wait_SW8();
  delay(4999);

  switch (readDipSwitch()) {
    case 0:
    while(1){
      GO(40);
    }
      break;
    case 1:
      routine_pid(70);
      break;
    case 2:
      motor(50, -50);
      delay(1000);
      motor(-50, 50);
      delay(1000);
      break;
    default:
      break;
  }
}

void loop() {

}