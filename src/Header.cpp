#include "Header.h"

/*==============================
    DEFINE GLOBAL VARIABLES
==============================*/
// Shift register pins and solenoid IDs (see Header.h for more details about what a solenoid ID is)
const short int latchPin = 5;
const short int clockPin = 6;
const short int dataPin = 7;
const unsigned int solenoidIDs[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768}; // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768
// const short int solenoidPositions[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
const short int solenoidPositions[] = {148, 191, 231, 274, 315, 357, 400, 426, 426, 426, 426, 426, 426, 426, 426, 426};

// TB6600 pins - Stepper motor controller
const short int dirPin = 2;
const short int stepPin = 3;

// Stepper motor constants
const unsigned long stepsPerRev = 6400;
const short int stepDelay = 7;

// Drink Recipes
const short int drink1[] = {0,2,-1};            //Pour solenoid 0 for 2 seconds
const short int drink2[] = {3,4,-1};            //Pour solenoid 3 for 4 seconds
const short int drink3[] = {0,2,1,3,6,5,-1};
const short int drink4[] = {0,1,1,1,3,1,5,1,-1};

// ... and our drink list
const short int NUMBER_RECIPES = 4;
const short int *drinkList[NUMBER_RECIPES] = {drink1, drink2, drink3, drink4};

// ... and the names of the drinks
const char *drinkListNames[] = {
    "Drink #1",
    "Drink #2",
    "Drink #3",
    "Drink #4",
};
