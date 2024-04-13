void tn(float Speed, float Kp, float Kd) {
  position = ReadObs();
  error = position - 2000;
  powermotor = (Kp * error) + (Kd * (error - lasterror));
  lasterror = error;
  leftmotor = Speed + powermotor;
  rightmotor = Speed - powermotor;
  if (leftmotor > 100) leftmotor = 100;
  if (leftmotor < -100) leftmotor = -100;
  if (rightmotor > 100) rightmotor = 100;
  if (rightmotor < -100) rightmotor = -100;
  motor(leftmotor, rightmotor);
}

void routine_pid(int Speed) {
  while (1) {
  ReadIR();
  if (S[0] > 400 && S[0] < 400) {
    motor(Speed,Speed);
    delay(200);
    motor(Speed,-Speed);
    delay(230);
  }
  if (S[0] < 400 && S[0] > 400) {
    motor(-Speed,-Speed);
    delay(200);
    motor(-Speed,Speed);
    delay(230);
  }
  else {
    tn(70, 0.025, 0.2);
  }
}
}