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
  int solInRecipe[size/2];    //List of solenoids in the recipe
  int secInRecipe[size/2];    //List of pour durations in the recipe
  short int xPosInRecipe[size/2];   //List of solenoid coordinates in the recipe

  Serial.print("Elements in recipe: ");
  Serial.println(size);
  for(int i=0; i<size; i++){
    //If we're looking at a solenoid's ID
    if(i%2 == 0){     
      solInRecipe[i/2] = recipe[i];
      xPosInRecipe[i/2] = solenoids[recipe[i]].getxPos();
    }
    //If we're looking at a pour duration
    else{
      secInRecipe[i/2] = recipe[i];
    }
  }



  //Testing the output here
  Serial.print("Here are the solenoids in the recipe: ");
  for(int i=0; i<size/2; i++){
    Serial.print(solInRecipe[i]);
    Serial.print(" ");
  }
  Serial.println();
  Serial.print("Here are the solenoid positions in the recipe: ");
  for(int i=0; i<size/2; i++){
    Serial.print(xPosInRecipe[i]);
    Serial.print(" ");
  }
  Serial.println();
  Serial.print("Here are the durations in the recipe: ");
  for(int i=0; i<size/2; i++){
    Serial.print(secInRecipe[i]);
    Serial.print(" ");
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
