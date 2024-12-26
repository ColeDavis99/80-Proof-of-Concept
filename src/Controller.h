#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Header.h"

struct Controller
{
    // References to the objects and data needed to pour a drink
    Platform* plat;
    const Solenoid* solenoids;
    const int** drinkList;


    // Default constructor
    Controller();

    // Parameterized constructor
    Controller(Platform* arg_plat, Solenoid* arg_solenoids, const int** arg_drinkList);

    // Housekeeping stuff
    void BootUp();
    
    //Make sure all the solenoids don't open simultaneously upon bootup
    void CloseAllSolenoids();

    void ErrBodyInTheClub();


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
};
#endif
