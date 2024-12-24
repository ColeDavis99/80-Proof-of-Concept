#ifndef SOLENOID_H
#define SOLENOID_H
#include "Header.h"

class Solenoid
{
private:
    int activationNum;  //The number that gets fed to the shift registers to activate this specific solenoid's relay (to pour)
    short int xPos;     //The number representing the fixed location of the solenoid. "How many revolutions away from the stepper motor am I"
    

public:
    // Default constructor
    Solenoid();

    //Parameterized constructor
    Solenoid(int arg_activationNum, short int arg_xPos);

    // Opens solenoid (pours) for X milliseconds.
    void Pour(int milliseconds);

    // Getters
    short int getxPos();
    int getactivationNum();

    // Setters
    void setxPos(short int arg_xPos);
    void setactivationNum(int arg_activationNum);
};
#endif
