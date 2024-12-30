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
  Serial.println("Beginning new drink");
  short int size = RecipeLen(recipe);
  short int solInRecipe[size/2];      //List of solenoid IDs in the recipe
  short int secInRecipe[size/2];      //List of pour durations in the recipe
  short int xPosInRecipe[size/2];     //List of solenoid coordinates in the recipe
  short int solenoidPos = 0;          //Helper variable
  short int platxPos = plat->getxPos();//Helper variable

  short int furthestLeft = -1;        //How far away from platform is the leftmost solenoid used in the recipe?
  short int furthestRight = -1;       //How far away from platform is the rightmost solenoid used in the recipe?


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

  //Sort solInRecipe asc or desc. secInRecipe gets sorted based on solInRecipe's sort to ensure pour durations don't get scrambled.
  if (furthestLeft == -1 && furthestRight == -1){
    Serial.println("No initial move, only one solenoid in recipe, already under, execute.");
  }
  else if (furthestLeft > furthestRight && furthestRight == -1){
    Serial.println("No initial move, sort descending and execute");
    SelectionSort(solInRecipe, secInRecipe, size/2, 'd');
  }
  else if (furthestRight > furthestLeft && furthestLeft == -1){
    Serial.println("No initial move, sort ascending and execute");
    SelectionSort(solInRecipe, secInRecipe, size/2, 'a');
  }
  else if (furthestLeft > furthestRight){
    Serial.println("Initial move right, sort descending and execute");
    SelectionSort(solInRecipe, secInRecipe, size/2, 'd');
  }
  else{
    Serial.println("Initial move left, sort ascending and execute");
    SelectionSort(solInRecipe, secInRecipe, size/2, 'a');
  }
  

  //TODO 12/29/24: Move the platform according to solInRecipe and pour according to secInRecipe
  for(short int i=0; i<size/2; i++){
    //Move to the solenoid
    Serial.print("Moving to ");
    Serial.print(solenoids[solInRecipe[i]].getxPos());
    Serial.print(" from ");
    Serial.println(plat->getxPos());
    plat->MoveTo(solenoids[solInRecipe[i]].getxPos());

    Serial.println("\nPouring solenoid ");
    Serial.print(solInRecipe[i]);
    Serial.print(" for ");
    Serial.print(secInRecipe[i]);
    Serial.println(" seconds ");
    solenoids[solInRecipe[i]].Pour(secInRecipe[i]);
  }
  Serial.println("Drink complete.");
  Serial.println("==============================\n\n");
};


// Returns the length of a recipe array (excluding the -1 endstop)
short int Controller::RecipeLen(int* recipe){
  int ctr = 0;
  while(recipe[ctr] != -1){
    ctr++;
  }
  return ctr;
};


// Basic selection sort. Pass an "a" or "d" for ascending or descending.
// Sorting logic is based on solInRecipe, and secInRecipe array mimics the swaps that happen to it (due to how I set up recipes)
void Controller::SelectionSort(short int* solInRecipe, short int* secInRecipe, short int size, char ascOrDesc){
  short int temp = 0;
  short int idx = 0;

  for (short int i = 0; i < size; i++)
  {
    idx = i;

    for (short int q = i + 1; q < size; q++)
    {
      if(ascOrDesc == 'a'){
//        Serial.println("ASCEND");
        if (solInRecipe[q] < solInRecipe[idx]){idx = q;}
      }
      if(ascOrDesc == 'd'){
//        Serial.print("DESCEND");
        if (solInRecipe[q] > solInRecipe[idx]){idx = q;}
      }
    }

    // SWAPPEM
//    Serial.println("Swapping");
//    Serial.print(solInRecipe[i]);
//    Serial.print(" and ");
//    Serial.println(solInRecipe[idx]);
    temp = solInRecipe[i];
    solInRecipe[i] = solInRecipe[idx];
    solInRecipe[idx] = temp;

    temp = secInRecipe[i];
    secInRecipe[i] = secInRecipe[idx];
    secInRecipe[idx] = temp;    
  }

  for(int i=0; i<size; i++){
    Serial.print(solInRecipe[i]);
    Serial.print(", ");
  }
  
};
