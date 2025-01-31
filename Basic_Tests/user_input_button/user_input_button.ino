/*
  Test reading in user input from a button via the analogue in A5 port.
*/

int readPin = A5;
int pinVal;

void setup(){
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}


void loop(){
  pinVal = analogRead(A5);
  delay(100);
  Serial.println(pinVal);
}
