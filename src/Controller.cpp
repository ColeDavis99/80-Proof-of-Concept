#include "arduino.h"
#include "Header.h"
#include "Controller.h"

//Default constructor
Controller::Controller(){};

//Parameterized contructor
Controller::Controller(Platform* arg_plat, Solenoid* arg_solenoids, const int** arg_drinkList){
  plat = arg_plat;
  solenoids = arg_solenoids;
  drinkList = arg_drinkList;
  };

// Housekeeping stuff
void Controller::BootUp(){
  CloseAllSolenoids();
};

void Controller::CloseAllSolenoids(){
  // ST_CP LOW to keep LEDs from changing while reading serial data
  digitalWrite(latchPin, LOW);
  // Shift out "0" to register.
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  // Output "0" so no more solenoid activation
  digitalWrite(latchPin, HIGH);
};
