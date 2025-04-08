#include "Arduino.h"
#include "Wire.h"
#include "LiquidCrystal_I2C.h"
#include "Header.h"
#include "Solenoid.h"
#include "Platform.h"
#include "Controller.h"

/*=============================
     INSTANCIATE OBJECTS
==============================*/

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
    {solenoidIDs[9], solenoidPositions[9]},
    {solenoidIDs[10], solenoidPositions[10]},
    {solenoidIDs[11], solenoidPositions[11]},
    {solenoidIDs[12], solenoidPositions[12]},
    {solenoidIDs[13], solenoidPositions[13]},
    {solenoidIDs[14], solenoidPositions[14]},
    {solenoidIDs[15], solenoidPositions[15]}
};

// Create a platform object with current x position
// Platform plat(0);
Platform plat(solenoids[2].getxPos());

// Create the controller object
Controller controller(&plat, solenoids);

// initialize the liquid crystal library
// the first parameter is  the I2C address
// the second parameter is how many rows are on your screen
// the  third parameter is how many columns are on your screen
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Switch input pins
const int leftSwitch = 9;
const int rightSwitch = 8;

//Button input pin
const int buttonPin = 10;

//Switch bools (for determining if switch is left or right)
bool leftState = 0;
bool rightState = 0;

//Counter to keep track of which drink is showing on LCD (indexes into drinkListNames[])
int drinkListIndex = 0;


void setup()
{
    // Shift register pins
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);

    // Stepper motor controller pins
    pinMode(dirPin, OUTPUT);
    pinMode(stepPin, OUTPUT);

    // Input switch input pins
    pinMode(leftSwitch, INPUT_PULLUP);
    pinMode(rightSwitch, INPUT_PULLUP);

    // Input button input pin
    pinMode(buttonPin, INPUT_PULLUP);

    // Used for debugging
    Serial.begin(9600);

    // Make sure all the solenoids don't open first startup, stuff like that
    controller.BootUp();

    // initialize lcd screen then turn on the backlight
    lcd.init();
    lcd.backlight();
}

void loop()
{

    rightState = digitalRead(rightSwitch); // Read the state of the right switch
    leftState = digitalRead(leftSwitch);   // Read the state of the left switch


    if (rightState == 0 and leftState == 0) // Left on switch
    {   if(drinkListIndex == 0){drinkListIndex = NUMBER_RECIPES;} //Prevent walking off array
        drinkListIndex--;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print(drinkListNames[drinkListIndex]);
    }
    else if (rightState == 1 and leftState == 1) // Right on switch
    {
        if (drinkListIndex == NUMBER_RECIPES-1){drinkListIndex = -1;} // Prevent walking off array
        drinkListIndex++;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print(drinkListNames[drinkListIndex]);
    }
    else if (rightState == 0 and leftState == 1) // No switch input
    {
        ;//No op
    }

    // Pour button was pressed
    if(digitalRead(buttonPin) == 0){
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("Pouring");
        lcd.setCursor(0,1);
        lcd.print(drinkListNames[drinkListIndex]);
        controller.ErrBodyInTheClub(drinkList[drinkListIndex]);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(drinkListNames[drinkListIndex]);
    }
    delay(200); // Add a small delay to avoid rapid polling




    // controller.plat->Pull(400);
    // controller.plat->Push(40);
    // while(1){};









    // controller.ErrBodyInTheClub(drinkList[2]);

    // controller.plat->Pull(5);
    //start 400, then 405, 410, 415 had bind.
    // controller.plat->Pull(50);

    // controller.plat->MoveTo(solenoids[7].getxPos());
    // delay(1000);

    //Output one shift register output at a time then looparooni
    // for(int i=0; i<16; i++)
    // {
    //     solenoids[i].Pour(300);
    // }


    // while(1){};
    
    /*
      controller.plat->MoveTo(solenoids[2].getxPos());
      delay(1000);
      solenoids[2].Pour(1000);

      controller.plat->MoveTo(solenoids[1].getxPos());
      delay(1000);
      solenoids[1].Pour(1000);

      controller.plat->MoveTo(solenoids[3].getxPos());
      delay(1000);
      solenoids[3].Pour(1000);

      controller.plat->MoveTo(solenoids[2].getxPos());
      delay(1000);
      solenoids[2].Pour(1000);

      controller.plat->MoveTo(solenoids[5].getxPos());
      delay(1000);
      solenoids[5].Pour(1000);

      controller.plat->MoveTo(solenoids[4].getxPos());
      solenoids[4].Pour(1000);

      controller.plat->MoveTo(solenoids[6].getxPos());
      solenoids[4].Pour(1000);
    */

    // controller.plat->Push(3);
    // controller.plat->Pull(400);

    // 43 steps between each one?

    // Solenoid 0 = 145
    // Solenoid 1 = 188
    // Solenoid 2 = 231
    // Solenoid 3 = 274
    // Solenoid 4 = 317
    // Solenoid 5 = 360
    // Solenoid 6 = 403
    // Solenoid 7 = 403 + ? (there was a bind so we don't know yet)

    /*
    //controller.ErrBodyInTheClub(drinkList[1]);

    solenoids[0].Pour(750);
    delay(2000);
    solenoids[1].Pour(750);
    delay(2000);
    */
}