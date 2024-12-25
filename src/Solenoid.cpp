#include "arduino.h"
#include "Solenoid.h"
#include "Header.h"

// Default Constructor
Solenoid::Solenoid(){}

// Parameterized Constructor
Solenoid::Solenoid(int arg_activationNum, short int arg_xPos){
    setactivationNum(arg_activationNum);
    setxPos(arg_xPos);
}

// Opens solenoid (pours) for X milliseconds.
void Solenoid::Pour(int milliseconds){

  // ST_CP LOW to keep LEDs from changing while reading serial data
  digitalWrite(latchPin, LOW);

  // Shift out the bits (Have to double down since I'm using two of them)
  shiftOut(dataPin, clockPin, MSBFIRST, activationNum >> 8);
  shiftOut(dataPin, clockPin, MSBFIRST, activationNum);
  
  // ST_CP HIGH to activate shift register output
  digitalWrite(latchPin, HIGH);
  delay(milliseconds);

  // ST_CP LOW to keep LEDs from changing while reading serial data
  digitalWrite(latchPin, LOW);

  // Shift out "0" to register.
  shiftOut(dataPin, clockPin, MSBFIRST, 0);

  // Output "0" so no more solenoid activation
  digitalWrite(latchPin, HIGH);
}

// Getters
short int Solenoid::getxPos(){return xPos;};
int Solenoid::getactivationNum(){return activationNum;};

// Setters
void Solenoid::setxPos(short int arg_xPos){xPos = arg_xPos;};
void Solenoid::setactivationNum(int arg_activationNum){activationNum = arg_activationNum;};
