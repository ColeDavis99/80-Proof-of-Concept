//This sketch triggers a solenoid to open for one second, then closes it indefinitely.

/*=====================
        CONSTANTS 
 ======================*/
//Input pins on L298N
const int inp2_pinA = 11;
const int inp2_pinB = 10;

//ENA pin 1 of 2 on L298N
const int ena_pin1 = 7;


void setup() {
  //Sets serial printing rate
  Serial.begin(9600);  

  /*=====================
    PINMODE ASSIGNMENT
   ======================*/
  pinMode(inp2_pinA, OUTPUT);
  pinMode(inp2_pinB, OUTPUT);
  pinMode(ena_pin1, OUTPUT);
  

  /*=====================
      PIN INITIAL STATES
   ======================*/
  //No solenoid activation to start out
  digitalWrite(inp2_pinA, LOW);
  digitalWrite(inp2_pinB, LOW);
  digitalWrite(ena_pin1, HIGH);
}



void loop() {
  Serial.println("Activate solenoid 2");
  digitalWrite(inp2_pinA, LOW);
  digitalWrite(inp2_pinB, HIGH);
  delay(1000);

  Serial.println("Deactivate solenoid 2");
  digitalWrite(inp2_pinA, LOW);
  digitalWrite(inp2_pinB, LOW);

  while(1){};
}
