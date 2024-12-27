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
  controller.ErrBodyInTheClub(drinkList[0]);
  while(1){}
  
/*
  controller.plat->Push(3);
  delay(1000);
  controller.ShowPosition();
  controller.plat->Pull(1);
  delay(1000);
  controller.ShowPosition();


  Serial.println(controller.drinkList[2][2]);
  delay(4000);

  controller.plat->Push(1);
  delay(3000);
  controller.plat->Pull(1);
  delay(3000);

  delay(4000);
  controller.solenoids[1].Pour(500);
  delay(4000);

  // Pour solenoid A for one second
  solenoids[0].Pour(700);
  delay(2000);

  // Pour solenoid B for one second
  solenoids[1].Pour(700);
  delay(2000);

  // Push the platform one revolution of stepper
  plat.Push(1);
  delay(1000);

  // Pull the platform one revolution of stepper
  plat.Pull(1);
  delay(1000);
*/
}
