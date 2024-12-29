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
  short int solenoidPos = 0;          //Helper variable
  short int platxPos = plat->getxPos();//Helper variable

  short int furthestLeft = -1;        //How far away is the leftmost solenoid used in the recipe?
  short int furthestRight = -1;       //How far away is the rightmost solenoid used in the recipe?


  Serial.print("Elements in recipe: ");
  Serial.println(size);

  //POPULATE THE THREE ARRAYS DECLARED ABOVE
  for(int i=0; i<size; i++){
    //If we're looking at a solenoid's ID
    if(i%2 == 0){
      solenoidPos = solenoids[recipe[i]].getxPos();

      xPosInRecipe[i/2] = solenoidPos;
      solInRecipe[i/2] = recipe[i];

      //Conditionally update furthestLeft and furthestRight
      if(solenoidPos > platxPos && abs(solenoidPos - platxPos) > furthestRight){
        furthestRight = abs(solenoidPos - platxPos);
      }
      else if (solenoidPos < platxPos && abs(solenoidPos - platxPos) > furthestLeft){
        furthestLeft = abs(solenoidPos - platxPos);
      }
    }
    //If we're looking at a pour duration
    else{
      secInRecipe[i/2] = recipe[i];
    }
  }

  //Run the drink pathfinding algorithm

  

  
  
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
  Serial.println();
  Serial.print("Current platform position: ");
  Serial.print(platxPos);
  Serial.println();
  Serial.print("Here is the furthest on each side: ");
  Serial.print("L: ");
  Serial.print(furthestLeft);
  Serial.print(" R: ");
  Serial.print(furthestRight);
  Serial.println();
  if(furthestLeft == -1 && furthestRight == -1){
    Serial.print("No initial move, only one solenoid in recipe, already under, execute.");
  }
  else if(furthestLeft > furthestRight && furthestRight == -1){
    Serial.print("No initial move, sort descending and execute");
  }
  else if(furthestRight > furthestLeft && furthestLeft == -1){
    Serial.print("No initial move, sort ascending and execute");    
  }
  else if(furthestLeft > furthestRight){
    Serial.print("Initial move right, sort descending and execute");
  }
  else{
    Serial.print("Initial move left, sort ascending and execute");
 }
  Serial.println("\n===================================");
  Serial.println();
};


// Returns the length of a recipe array (excluding the -1 endstop)
short int Controller::RecipeLen(int* recipe){
  int ctr = 0;
  while(recipe[ctr] != -1){
    ctr++;
  }
  return ctr;
};

// Returns whether the platform is already under a solenoid that's part of the recipe.
// bool Controller::AlreadyUnder(short int size, short int platXPos, short int* xPosInRecipe) {
//   for(short int i=0; i<size; i++){
//     if(platXPos == xPosInRecipe[i]){return true;}
//   }
//   return false;
// };
