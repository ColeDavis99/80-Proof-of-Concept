#ifndef HEADER_H
#define HEADER_H
#include "Solenoid.h"
#include "Platform.h"
#include "Controller.h"


/*==============================
    DECLARE GLOBAL VARIABLES
==============================*/

// Shift register pins and array of solenoid IDs:
// The solenoidIDs array holds each unique value to feed into the shift registers to activate one (and only one) solenoid.
// The shift registers' output pins can be thought of as the binary representation of whatever number gets fed into it.
// You can see lots of shift register YouTube videos where they show the binary encoding of a number with LEDs. Same idea,
// except we're not lighting up LEDs. We're activating ONE solenoid at a time. Hence, solenoidIDs holds 1, 2, 4, 8, 2^n, ...
// since those are the numbers whose binary encoding uses a single "1" in it's encoding to represent it.
extern const short int latchPin;
extern const short int clockPin;
extern const short int dataPin;
extern const int solenoidIDs[];         // Holds each solenoids' activation value. This value, or "ID", is what's fed into the shift registers to pour a bottle
extern const int solenoidPositions[];   // solenoidPositions[3] will hold the x axis position value for the Solenoid object found at solenoids[3] for example

// TB6600 pins - Stepper motor controller
extern const short int dirPin;
extern const short int stepPin;

// Stepper motor constants
// This will vary depending on the spec sheet of whatever stepper motor you're using.
extern const unsigned long stepsPerRev;
extern const short int stepDelay;


// Drink Recipes
/* For example a recipe array containing [0,1,4,1,9,4] is interpreted as:

    1) Solenoid 0 is in the recipe     [0,x,x,x,x,x]            
    2) Pour it for one second          [x,1,x,x,x,x]
    3) Solenoid 4 is in the recipe     [x,x,4,x,x,x]
    4) Pour it for one second          [x,x,x,1,x,x]
    5) Solenoid 9 is in the recipe     [x,x,x,x,9,x]
    6) Pour it for 4 seconds           [x,x,x,x,x,4]

    Cool, 6 ints can tell us how to pour a drink with 3 different ingredients.
*/
extern const int drink1[];
extern const int drink2[];
extern const int drink3[];

extern const int *drinkList[];

#endif
