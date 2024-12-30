#include "Header.h"

/*==============================
    DEFINE GLOBAL VARIABLES
==============================*/
// Shift register pins and solenoid IDs (see Header.h for more details about what a solenoid ID is)
const short int latchPin = 5;
const short int clockPin = 6;
const short int dataPin = 7;
const int solenoidIDs[] =       {1, 2, 4, 8, 16, 32, 64, 128, 256, 512}; // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768
const short int solenoidPositions[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};

// TB6600 pins - Stepper motor controller
const short int dirPin = 2;
const short int stepPin = 3;

// Stepper motor constants
const unsigned long stepsPerRev = 6400;
const short int stepDelay = 9;

// Drink Recipes
const int drink1[] = {1,2,-1};     //Pour solenoid 1 for 2 seconds
const int drink2[] = {3,2,-1};     //Pour solenoid 3 for 2 seconds
const int drink3[] = {0,2,1,9,8,3,4,2,2,4,5,6,-1}; //Pour solenoid 6 for 7 seconds, Pour solenoid 8 for 9 second

// ... and our drink list
const int* drinkList[3] = {drink1, drink2, drink3};
