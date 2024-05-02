#include "Newkub.h"

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
    motor(-100,-100);
    delay(275);
    motor(100,-100);
    delay(275);
  }
  if (light_L > 500 && light_R < 500) {
    motor(-100,-100);
    delay(275);
    motor(-100,100);
    delay(275);
  }
  else {
    Track(100);
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
    motor(Speed,Speed);
  } else if (ll == 1 && l == 0 && m == 0 && r == 0 && rr == 1) {
    motor(Speed,Speed);
  } else if (ll == 1 && l == 0 && m == 0 && r == 1 && rr == 1) {
    motor(Speed,Speed);
  } else if (ll == 1 && l == 0 && m == 1 && r == 1 && rr == 1) {
    motor(-Speed,Speed);
    delay(50);
  } else if (ll == 0 && l == 0 && m == 1 && r == 1 && rr == 1) {
    motor(-Speed,Speed);
    delay(100);
  } else if (ll == 0 && l == 1 && m == 1 && r == 1 && rr == 1) {
    motor(-Speed,Speed);
    delay(150);
  } else if (ll == 1 && l == 1 && m == 0 && r == 0 && rr == 1) {
    motor(Speed,Speed);
  } else if (ll == 1 && l == 1 && m == 1 && r == 0 && rr == 1) {
    motor(Speed,-Speed);
    delay(50);
  } else if (ll == 1 && l == 1 && m == 1 && r == 0 && rr == 0) {
    motor(Speed,-Speed);
    delay(100);
  } else if (ll == 1 && l == 1 && m == 1 && r == 1 && rr == 0) {
    motor(Speed,-Speed);
    delay(150);
  } else {
    motor(50,50);
  }
}