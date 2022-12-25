#ifndef WATERSENSOR_H
#define WATERSENSOR_H

int sensorToggler = 7;
int sensorRead = 4;
int THRESHOLDWATER = 10;

double readWaterS(){
  digitalWrite(sensorToggler, HIGH);
  Serial.println(analogRead(sensorRead));
  return analogRead(sensorRead);
}

#endif
