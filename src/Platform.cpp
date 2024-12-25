#include "arduino.h"
#include "Platform.h"
#include "Header.h"

// Default Constructor
Platform::Platform(){}

// Parameterized Constructor
Platform::Platform(short int arg_xPos){
  setxPos(arg_xPos);
}

// Moves platform away from stepper motor "i" revolutions
void Platform::Push(unsigned long revs) {
  digitalWrite(dirPin, LOW);
  for (unsigned long i = 0; i < revs; i++){
    for (unsigned long q = 0; q < stepsPerRev; q++){
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(stepDelay);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(stepDelay);
    }
    //Update current position of platform
    xPos++;
  }
};

// Moves platform towards stepper motor "i" revolutions
void Platform::Pull(unsigned long revs){
  digitalWrite(dirPin, HIGH);
  for (unsigned long i = 0; i < revs; i++){
    for (unsigned long q = 0; q < stepsPerRev; q++){
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(stepDelay);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(stepDelay);
    }
    //Update current position of platform
    xPos--;
  }
};

// Getters
short int Platform::getxPos() { return xPos; };

// Setters
void Platform::setxPos(short int arg_xPos) { xPos = arg_xPos; };
