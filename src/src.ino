#include "Header.h"
#include "Solenoid.h"
#include "Platform.h"

// 12/24/24: Left off here (see commit message from same day): https://hackingmajenkoblog.wordpress.com/2016/02/04/the-evils-of-arduino-strings/

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
  //solenoidA.Pour(1000);
  //delay(5000);

  //Pour solenoid B for one second
  //solenoidB.Pour(1000);
  //delay(5000);

  //Push the platform one revolution of stepper
  //plat.Push(1);
  //delay(1000);
  
  //Pull the platform one revolution of stepper
  //plat.Pull(1);
  //delay(1000);
  
}
