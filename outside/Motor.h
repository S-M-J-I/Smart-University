#ifndef MOTOR_H
#define MOTOR_H
#include <Servo.h>

Servo serv2;

void turnon(){
  Serial.println("ON");
  serv2.write(185);
}

void turnoff(){
  Serial.println("OFF");
  serv2.write(95);
}


#endif