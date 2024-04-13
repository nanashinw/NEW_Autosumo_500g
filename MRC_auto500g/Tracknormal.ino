void GO(int Speed) {
  while (1) {
  if (light_L < 500 && light_R > 500) {
    motor(Speed,Speed);
    delay(200);
    motor(Speed,-Speed);
    delay(230);
  }
  if (light_L > 500 && light_R < 500) {
    motor(-Speed,-Speed);
    delay(200);
    motor(-Speed,Speed);
    delay(230);
  }
  else {
    Track(200);
  }
}
}

void Track(int Speed) {
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