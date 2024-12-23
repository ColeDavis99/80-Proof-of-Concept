#include "Header.h"
#include "Solenoid.h"

//Shift registers
const short int latchPin = 5;
const short int clockPin = 6;
const short int dataPin = 7;
const int numsToDisplay[16] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};
// uint16_t LED1 = 0b1000000000000000;



Solenoid solenoidA(numsToDisplay[0], 0);
Solenoid solenoidB(numsToDisplay[1], 0);


void setup(){
  //Shift Register Pins
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}


void loop(){
  //Pour solenoid A for one second.
    solenoidA.Pour(1000);
    delay(3000);
    solenoidB.Pour(1000);
    delay(3000);
}
