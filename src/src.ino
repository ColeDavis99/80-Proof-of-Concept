#include "Header.h"
#include "Solenoid.h"
#include "Platform.h"
#include "Controller.h"

/*=============================
     INSTANCIATE OBJECTS
==============================*/
// Create a platform object with current x position
Platform plat(0);

// Create the array of solenoid objects
const Solenoid solenoids[]{
//   Activation num     x positions
    {solenoidIDs[0], solenoidPositions[0]},
    {solenoidIDs[1], solenoidPositions[1]},
    {solenoidIDs[2], solenoidPositions[2]},
    {solenoidIDs[3], solenoidPositions[3]},
    {solenoidIDs[4], solenoidPositions[4]},
    {solenoidIDs[5], solenoidPositions[5]},
    {solenoidIDs[6], solenoidPositions[6]},
    {solenoidIDs[7], solenoidPositions[7]}, 
    {solenoidIDs[8], solenoidPositions[8]},
    {solenoidIDs[9], solenoidPositions[9]}
};

//Create the controller object
Controller controller(&plat, solenoids);


void setup()
{
  // Shift register pins
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  // Stepper motor controller pins
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);

  //Used for debugging
  Serial.begin(9600);

  //Make sure all the solenoids don't open first startup, stuff like that
  controller.BootUp();
}


void loop()
{
  controller.ErrBodyInTheClub(drinkList[2]);
  controller.ErrBodyInTheClub(drinkList[1]);


  while(1){}
}
