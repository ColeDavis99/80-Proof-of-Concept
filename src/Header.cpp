#include "Header.h"

/*==============================
    DEFINE GLOBAL VARIABLES
==============================*/
// Shift register pins and solenoid IDs (see Header.h for more details about what a solenoid ID is)
const short int latchPin = 5;
const short int clockPin = 6;
const short int dataPin = 7;
const short int NUM_SOLENOIDS = 10;
const int solenoidIDs[NUM_SOLENOIDS]; // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768


// TB6600 pins - Stepper motor controller
const short int dirPin = 2;
const short int stepPin = 3;

// Stepper motor constants
const unsigned long stepsPerRev = 6400;
const short int stepDelay = 9;



/*===========================
    INSTANCIATE OBJECTS
===========================*/
// Make a platform object
Platform plat(0);

//Want to make an array of NUM_SOLENOIDS solenoid objects.
//Then, it should be available in Controller.cpp to use in the parameterized contructor for controller instanciation.




// Make "NUM_SOLENOIDS" number of solenoid objects.
// Solenoid solenoidA(solenoidIDs[0], 0);
// Solenoid solenoidB(solenoidIDs[1], 0);

