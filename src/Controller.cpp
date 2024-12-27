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





// GETS THEM SHAWTIES OWN DA FLO
void Controller::ErrBodyInTheClub(int* recipe){
  short int size = RecipeLen(recipe);

  short int solInRecipe[size/2];      //List of solenoid IDs in the recipe
  short int secInRecipe[size/2];      //List of pour durations in the recipe
  short int xPosInRecipe[size/2];     //List of solenoid coordinates in the recipe

  short int alreadyUnder;             //Is the platform already under a solenoid that needs to be poured?



  Serial.print("Elements in recipe: ");
  Serial.println(size);

  //Populate the three arrays declared above
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


  //Run the drink pathfinding algorithm
  //Input: List of solenoid coordinates and platform's current coordinates
  //Output: Modify the order of values found in solInRecipe and secInRecipe to chronologically be the path the platform takes

  //If platform is aready under a solenoid that's in that recipe
  alreadyUnder = AlreadyUnder(size/2, plat->getxPos(), xPosInRecipe);
  

  

  //Testing the output here
  Serial.print("AlreadyUnder? ");
  Serial.println(alreadyUnder);
  
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
short int Controller::RecipeLen(int* recipe){
  int ctr = 0;
  while(recipe[ctr] != -1){
    ctr++;
  }
  return ctr;
};

// Returns the solenoid index that the platform is already under, if that solenoid is part of the recipe.
bool Controller::AlreadyUnder(short int size, short int platXPos, short int* xPosInRecipe) {
  for(short int i=0; i<size; i++){
    if(platXPos == xPosInRecipe[i]){return true;}
  }
  return false;
};
