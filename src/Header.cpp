#include "Header.h"

/*==============================
    DEFINE GLOBAL VARIABLES
==============================*/
// Shift register pins and solenoid IDs (see Header.h for more details about what a solenoid ID is)
const short int latchPin = 5;
const short int clockPin = 6;
const short int dataPin = 7;
const int solenoidIDs[] =       {1, 2, 4, 8, 16, 32, 64, 128, 256, 512}; // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768
const int solenoidPositions[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

// TB6600 pins - Stepper motor controller
const short int dirPin = 2;
const short int stepPin = 3;

// Stepper motor constants
const unsigned long stepsPerRev = 6400;
const short int stepDelay = 9;
