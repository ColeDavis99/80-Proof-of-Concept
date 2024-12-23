#include "Header.h"
#include "Solenoid.h"
#include "Platform.h"

/*==============================
    DEFINE GLOBAL VARIABLES
==============================*/
// Shift registers
const short int latchPin = 5;
const short int clockPin = 6;
const short int dataPin = 7;
const int solenoidIDs[16] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

// TB6600 pins - Stepper motor controller
const short int dirPin = 2;
const short int stepPin = 3;

// Stepper motor constants
const unsigned long stepsPerRev = 6400;
const short int stepDelay = 9;


/*===========================
    INSTANCIATE OBJECTS
===========================*/
//Make two solenoid objects
Solenoid solenoidA(solenoidIDs[0], 0);
Solenoid solenoidB(solenoidIDs[1], 0);

//Make a platform object
Platform plat(0);

void setup(){
  //Shift register pins
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  //Stepper motor controller pins
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
}


void loop(){
  //Pour solenoid A for one second
  solenoidA.Pour(1000);
  delay(5000);

  //Pour solenoid B for one second
  solenoidB.Pour(1000);
  delay(5000);

  //Pull the platform one revolution of stepper
  plat.Pull(1);
  delay(1000);
  
  //Push the platform one revolution of stepper
  plat.Push(1);
}
