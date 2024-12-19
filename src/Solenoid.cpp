#include "Solenoid.h"

// Default Constructor
Solenoid::Solenoid(){}

// Parameterized Constructor
Solenoid::Solenoid(short int arg_activationNum, short int arg_xPos){
    setactivationNum(arg_activationNum);
    setxPos(arg_xPos);
}

// Opens solenoid (pours) for X milliseconds.
void Solenoid::Pour(int milliseconds){
    //TODO
}

// Getters
short int Solenoid::getxPos(){return xPos;};
short int Solenoid::getactivationNum(){return activationNum;};

// Setters
void Solenoid::setxPos(short int arg_xPos){xPos = arg_xPos;};
void Solenoid::setactivationNum(short int arg_activationNum){activationNum = arg_activationNum;};