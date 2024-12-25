#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Header.h"

class Controller
{
private:


public:
    // Default constructor
    Controller();

    // Parameterized constructor
     Controller(Platform plat, Solenoid* solenoids);

    // Moves platform away from stepper motor X revolutions
    void Push(unsigned long revs);

    // Moved platform towards stepper motor X revolutions
    void Pull(unsigned long revs);

    // Calculates the most efficient movement path for pouring drink X relative to platform's current position
    //  TODO

    // Getters
    // short int getxPos();

    // Setters
    // void setxPos(short int arg_xPos);
};
#endif
