/*=====================
        CONSTANTS 
 ======================*/
//Input pins on L298N
const int inp1_pinA = 12;
const int inp1_pinB = 13;
const int inp2_pinA = 11;
const int inp2_pinB = 10;



/*=====================
       VARIABLES 
 ======================*/


void setup() {
  //Sets serial printing rate
  Serial.begin(9600);  

  /*=====================
    PINMODE ASSIGNMENT
   ======================*/
  pinMode(inp1_pinA, OUTPUT);
  pinMode(inp1_pinB, OUTPUT);
  pinMode(inp2_pinA, OUTPUT);
  pinMode(inp2_pinB, OUTPUT);
  

  /*=====================
      PIN INITIAL STATES
   ======================*/
  //No solenoid activation to start out
  digitalWrite(inp1_pinA, LOW);
  digitalWrite(inp1_pinB, LOW);
  digitalWrite(inp2_pinA, LOW);
  digitalWrite(inp2_pinB, LOW);
}



void loop() {
  //Activate solenoid 1
  digitalWrite(inp1_pinA, HIGH);
  digitalWrite(inp1_pinB, LOW);
  delay(2000);

  //Deactivate solenoid 1
  digitalWrite(inp1_pinA, LOW);
  digitalWrite(inp1_pinB, LOW);
  delay(2000);

    //Activate solenoid 2
  digitalWrite(inp1_pinA, HIGH);
  digitalWrite(inp1_pinB, LOW);
  delay(2000);

  //Deactivate solenoid 2
  digitalWrite(inp1_pinA, LOW);
  digitalWrite(inp1_pinB, LOW);
  delay(2000);

  while(1){};
}
