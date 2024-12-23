#include "arduino.h"
#include "Platform.h"

// Default Constructor
Platform::Platform(){}

// Parameterized Constructor
Platform::Platform(short int arg_xPos){
  setxPos(arg_xPos);
}

// Moves platform away from stepper motor X revolutions
void Platform::Push(unsigned long revs) {
  digitalWrite(dirPin, LOW);
  for (unsigned long i = 0; i < stepsPerRev * revs; i++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelay);
  }
};

// Moved platform towards stepper motor X revolutions
void Platform::Pull(unsigned long revs){
  digitalWrite(dirPin, HIGH);
  for (unsigned long i = 0; i < stepsPerRev * revs; i++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelay);
  }
};

// Getters
short int Platform::getxPos() { return xPos; };

// Setters
void Platform::setxPos(short int arg_xPos) { xPos = arg_xPos; };
