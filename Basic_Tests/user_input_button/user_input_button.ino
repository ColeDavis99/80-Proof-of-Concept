/*
  Testing the left and right functionality of the swtich.
*/


//Switch input pins
const int leftSwitch = 9;
const int rightSwitch = 8;

//Switch bools (for determining if switch is left or right)
bool leftState = 0;
bool rightState = 0;

// For toggling which LCD row is written to (0 = top 1 = bottom)
bool rownum = 0;

void setup()
{
    // Input switch input pins
    pinMode(leftSwitch, INPUT_PULLUP);
    pinMode(rightSwitch, INPUT_PULLUP);

    // Used for debugging
    Serial.begin(9600);
}

void loop()
{
    rightState = digitalRead(rightSwitch); // Read the state of the right switch
    leftState = digitalRead(leftSwitch);   // Read the state of the left switch

    if(rightState == 0 and leftState == 0){
      Serial.println("Left");
    }
    else if(rightState == 1 and leftState == 1){
      Serial.println("Right");
    }
    else if(rightState == 0 and leftState == 1){
      Serial.println("Neither");
    }
    else{
      Serial.println("What");
    }

    delay(1500); // Add a small delay to avoid rapid polling
}
