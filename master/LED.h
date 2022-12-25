#ifndef LED_H
#define LED_H

void lightUpLEDS(int *LEDs) {
  int len = sizeof(LEDs) / sizeof(LEDs[0]);
  for (int i=0; i < len; ++i) {
    digitalWrite(LEDs[i], HIGH);
  }
}


void dimDownLEDS(int *LEDs) {
  int len = sizeof(LEDs) / sizeof(LEDs[0]);
  for (int i=0; i < len; ++i) {
    digitalWrite(LEDs[i], LOW);
  }
}

#endif
