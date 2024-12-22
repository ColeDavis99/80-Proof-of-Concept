//Pin 1 is your output pin for the LED.
#include "Header.h"
#include "Solenoid.h"

//Test 2: Instanciate a Solenoid object (kinda hijacking it for the LED) using the testPin variable from Header.h
Solenoid testSolenoid(testPin, whatever);
int fancyCtr = 0;

void setup(){
  //Test 1: Import the variable testPin directly from "Header.h" (success)
  pinMode(testPin, OUTPUT);
}


void loop(){
  //Test 1: Import the variable testPin directly from "Header.h" (success)
//  digitalWrite(testPin, HIGH);
//  delay(200);
//  digitalWrite(testPin, LOW);
//  delay(200);

  //Test 2: Use a function of the Solenoid object with pin argument from Header.h
  for(int i=60; i>20; i--){
    testSolenoid.Pour(i);
  }
  for(int i=20; i<60; i++){
    testSolenoid.Pour(i);
  }
}
