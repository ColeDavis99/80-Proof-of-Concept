#ifndef PLATFORM_H
#define PLATFORM_H
#include "Header.h"

class Platform
{
private:
    short int xPos;     //The number representing the current location of the platform's center.
    

public:
    // Default constructor
    Platform();

    //Parameterized constructor
    Platform(short int arg_xPos);

    //Moves platform away from stepper motor X revolutions
    void Push(unsigned long revs);

    //Moved platform towards stepper motor X revolutions
    void Pull(unsigned long revs);

    // Getters
    short int getxPos();

    // Setters
    void setxPos(short int arg_xPos);
};
#endif
