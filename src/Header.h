#ifndef HEADER_H
#define HEADER_H

// Shift register pins and array of solenoid IDs
// The solenoidIDs array holds each unique value to feed into the shift registers to activate one (and only one) solenoid.
// The shift registers' output pins can be thought of as the binary representation of whatever number gets fed into it.
// You can see lots of shift register YouTube videos where they show the binary encoding of a number with LEDs. Same idea,
// except we're not lighting up LEDs. We're activating ONE solenoid at a time. Hence, solenoidIDs holds 1, 2, 4, 8, 2^n, ...
// since those are the numbers whose binary encoding uses a single "1" in it's encoding to represent it.
extern const short int latchPin;
extern const short int clockPin;
extern const short int dataPin;
extern const int solenoidIDs[16];

// TB6600 pins - Stepper motor controller
extern const short int dirPin;
extern const short int stepPin;

// Stepper motor constants
// This will vary depending on the spec sheet of whatever stepper motor you're using.
extern const unsigned long stepsPerRev;
extern const short int stepDelay;

#endif
