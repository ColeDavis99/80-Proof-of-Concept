#ifndef HEADER_H
#define HEADER_H

// Shift register pins and array of solenoid IDs
extern const short int latchPin;
extern const short int clockPin;
extern const short int dataPin;
extern const int solenoidIDs[16];

// TB6600 pins - Stepper motor controller
extern const short int dirPin;
extern const short int stepPin;

// Stepper motor constants
extern const unsigned long stepsPerRev;
extern const short int stepDelay;

#endif
