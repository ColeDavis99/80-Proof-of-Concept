#include "arduino.h"
#include "Header.h"
#include "Controller.h"

//Default constructor
Controller::Controller(){};

//Parameterized contructor
Controller::Controller(Platform* arg_plat, Solenoid* arg_solenoids){
  plat = arg_plat;
  solenoids = arg_solenoids;
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


// Outputs position of platform
void Controller::ShowPosition(){
  Serial.print("Position: ");
  Serial.println(plat->getxPos());
};

// Gets them shawties out on da flo
void Controller::ErrBodyInTheClub(int* recipe){
  int size = RecipeLen(recipe);
  
  Serial.print("Elements in recipe: ");
  Serial.print(size);
  for(int i=0; i<size; i++){
    Serial.print(recipe[i]);
  }
};


// Returns the length of a recipe array (excluding the -1 endstop)
int Controller::RecipeLen(int* recipe){
  int ctr = 0;
  while(recipe[ctr] != -1){
    ctr++;
  }
  return ctr;
};
