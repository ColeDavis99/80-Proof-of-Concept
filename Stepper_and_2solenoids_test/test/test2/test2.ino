//This sketch is for bidirection stepper motor control and activating 2 solenoids

// L298N pins - Solenoid controller
const int solTrgPinA1 = 10; //4 trigger pins
const int solTrgPinA2 = 11;
const int solTrgPinB1 = 12;
const int solTrgPinB2 = 13;
const int solEnaPinA = 7;   //2 ENA pins (constant 5v)
const int solEnaPinB = 8;

// TB6600 pins - Stepper motor controller
const int dirPin = 2;
const int stepPin = 3;

// Stepper motor constants
const long stepsPerRev = 6400;
const int stepDelay = 9;



void setup(){
    //Set pinmodes
    pinMode(solTrgPinA1, OUTPUT);
    pinMode(solTrgPinA2, OUTPUT);
    pinMode(solTrgPinB1, OUTPUT);
    pinMode(solTrgPinB2, OUTPUT);
    pinMode(solEnaPinA, OUTPUT);
    pinMode(solEnaPinB, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(stepPin, OUTPUT);

    //Activate ENA pins for L298N
    digitalWrite(solEnaPinA, HIGH);
    digitalWrite(solEnaPinB, HIGH);

    //Initial L298N state
    digitalWrite(solTrgPinA1, LOW);
    digitalWrite(solTrgPinA2, LOW);
    digitalWrite(solTrgPinB1, LOW);
    digitalWrite(solTrgPinB2, LOW);
}



void loop(){
    //One clockwise revolution
    digitalWrite(dirPin, HIGH);
    for(long i=0; i<stepsPerRev; i++){
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(stepDelay);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(stepDelay);
    }
    delay(1000);

    // One counter-clockwise revolution
    digitalWrite(dirPin, LOW);
    for (long i=0; i<stepsPerRev; i++)
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(stepDelay);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(stepDelay);
    }
    delay(1000);

    //Open & close solenoid A
    digitalWrite(solTrgPinA1, LOW);
    digitalWrite(solTrgPinA2, HIGH);
    delay(1000);
    digitalWrite(solTrgPinA1, LOW);
    digitalWrite(solTrgPinA2, LOW);
    delay(1000);

    //Open & close solenoid B
    digitalWrite(solTrgPinB1, LOW);
    digitalWrite(solTrgPinB2, HIGH);
    delay(1000);
    digitalWrite(solTrgPinB1, LOW);
    digitalWrite(solTrgPinB2, LOW);
    delay(1000);


    //Stops the stepper motor from sitting there and squealing without movement.
    digitalWrite(stepPin, LOW);
    digitalWrite(dirPin, LOW);

    while(1){}
}
