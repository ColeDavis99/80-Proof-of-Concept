#ifndef PLATFORM_H
#define PLATFORM_H

class Platform
{
private:
    //The number representing the current location of the platform's center (how many revolutions away from stepper motor it is)
    short int xPos;
    

public:
    // Default constructor
    Platform();

    //Parameterized constructor
    Platform(short int arg_xPos);

    //Moves platform away from stepper motor X revolutions
    void Push(short int revs);

    //Moves platform towards stepper motor X revolutions
    void Pull(short int revs);

    //Moves platform to a specified X coordinate
    void MoveTo(short int new_xPos);

    // Getters
    short int getxPos();

    // Setters
    void setxPos(short int arg_xPos);
};
#endif
