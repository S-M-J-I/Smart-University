#ifndef PIEZO_H
#define PIEZO_H

int piezo = 1;
int THRESHOLDP = 500;
double sensorval = 0;

double readPiezo() {
  return analogRead(piezo);
}

#endif
