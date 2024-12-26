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

    //Might be used for something eventually.
    void Init();

    // Moves platform away from stepper motor X revolutions
    void Push(unsigned long revs);

    // Moved platform towards stepper motor X revolutions
    void Pull(unsigned long revs);

    /*
    Calculates the most efficient movement path for pouring drink X relative to platform's current position
    Algorithm summary: 
    If(platform is under a solenoid that's part of the recipe)
        Pour(solenoid)
    If(There's a tie for the closest left solenoid that's part of the drink and closest right solenoid that's part of the drink)
        Move to the closest solenoid on the side whose furthest solenoid that's part of the drink is the smaller than the other side, or if that's a tie move to the closest left solenoid that's part of the drink.
    For(Solenoids_remaining_in_recipe)
        RunGreedy()
    */
    void TODO_1_or_so();
    void TODO_2_or_so();

    // Getters
    // short int getxPos();

    // Setters
    // void setxPos(short int arg_xPos);
};
#endif
