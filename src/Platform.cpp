#include "arduino.h"
#include "Header.h"
#include "Platform.h"

// Default Constructor
Platform::Platform(){}

// Parameterized Constructor
Platform::Platform(short int arg_xPos){
  setxPos(arg_xPos);
}

// Moves platform away from stepper motor "i" revolutions
void Platform::Push(short int revs) {
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
void Platform::Pull(short int revs){
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

void Platform::MoveTo(short int new_xPos){
  if(new_xPos > xPos){
    Serial.print("Pushing ");
    Serial.println(abs(new_xPos - xPos));
    Push(abs(new_xPos - xPos));
  }
  else{
    Serial.print("Pulling ");
    Serial.println(abs(new_xPos - xPos));
    Pull(abs(new_xPos - xPos));
  }
};

// Getters
short int Platform::getxPos() { return xPos; };

// Setters
void Platform::setxPos(short int arg_xPos) { xPos = arg_xPos; };
