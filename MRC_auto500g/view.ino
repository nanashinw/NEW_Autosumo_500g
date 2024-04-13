void view() {
  Serial.begin(9600);
  while (START == 0) {
    for (int i = 0; i < numsensor; i++) {
      Serial.print(nashi(pin[i]));
      Serial.print(",\t");
    }
    Serial.println("");
  }
  Serial.end();
}

void viewReadObs() {
  Serial.begin(9600);
  while (START == 0) {
    for (int i = 0; i < numsensor; i++) {
      Serial.print(F[i]);
      Serial.print(",\t");
    }
    Serial.println(ReadObs());
  }
  Serial.end();
}

void viewdiff(){
  Serial.begin(9600);
  while (START == 0) {
    Serial.println(readDipSwitch());
  }
  Serial.end();
}


float viewBatt(void)
{
  int adc = analogRead(VBATT);
  float adcVolt = (float)adc * (5.0f / 1023.0f);
  float vBatt = adcVolt * (1.0f + (10.0f / 3.9f));
  Serial.println(vBatt);
  return vBatt;
}