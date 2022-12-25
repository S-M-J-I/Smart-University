// ARDUINO TO CONFIG INISDE MECHANISMS

/**
  10,11 for bluetooth
  8 for PIR sensor
  2,3 for fingerprint sensor
*/

#include "PIR.h"
#include "LED.h"
#include "IR.h"
#include "UserStore.h"
#include "Fingerprint.h"

SoftwareSerial bluetooth(10,11); // RX, TX => bluetooth

int LEDs[] = {12};

void setup() 
{
  // start serial communication
  Serial.begin(9600);

  pinMode(WIRSensor, INPUT); // sensor pin INPUT
  pinMode(GIRSensor, INPUT); // sensor pin INPUT
  pinMode(PIRSensor, INPUT); // sensor pin INPUT

  digitalWrite(WIRSensor, LOW);
  digitalWrite(GIRSensor, LOW);
  
  // Bluetooth begin
  bluetooth.begin(9600);
  
  // fingerprint sensor begin and find/setup
  fingerprint:
  fps.begin(57600);
  if(fps.verifyPassword()){
    Serial.println("Active");
  }else{
    Serial.println("Inactive sensor");
//     goto fingerprint;
  }
  

  // for all leds, make them output  
  for (int i : LEDs) {
    pinMode(i, OUTPUT);
  }
  
}


void loop()
{
  
  dimDownLEDS(LEDs);
  IRToggleRoomElec();


  if(_count > 0) {
    Serial.print("Count: ");
    Serial.println(_count);
    lightUpLEDS(LEDs);
  }

  if(_count == 0) {
    dimDownLEDS(LEDs);
  }

//  measurePIR(LEDs);
//  IRToggleRoomElec(LEDs);
//  bluetooth.print("Hello");
 
//  // FINGER PRINT PART

//   int choice = readID();
//   Serial.println(choice);
//
//
//
//
//  if(choice == 1) {
//     Serial.println("Enter student ID: ");
//     int id = readID();
//     Serial.println("Enter student name: ");
//     String studentName = readStudentName();
//     while(!getFingerprintEnroll(id, studentName));
//  } 
// 
//  if(choice == 2) {
//     Serial.println("Enter fingerprint: ");
//     fingerprintID = getFingerprintID();
//  }
//
//  if(choice == 3) {
//    fps.emptyDatabase();
//  }
 
  
  delay(300);
}
