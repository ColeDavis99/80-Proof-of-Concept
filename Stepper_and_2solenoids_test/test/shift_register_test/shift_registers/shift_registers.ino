// Control 16 LEDs with 2 shift registers (and only 3 arduino pins)

int latchPin = 5;
int clockPin = 6;
int dataPin = 7;
int clearPin = 9;

int numsToDisplay[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
//uint16_t LED1 = 0b1000000000000000;


void setup(){
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clearPin, OUTPUT);

  //Low to clear registers, then leave HIGH to prevent clearing.
  digitalWrite(clearPin, LOW);
  delay(100);
  digitalWrite(clearPin, HIGH);



}




void loop(){
//  digitalWrite(latchPin, LOW);
//  shiftOut(dataPin, clockPin, MSBFIRST, LED1 >> 8);
//  shiftOut(dataPin, clockPin, MSBFIRST, LED1);
//  digitalWrite(latchPin, HIGH);
//  delay(50);
  
//  //ST_CP LOW to keep LEDs from changing while reading serial data
//  digitalWrite(latchPin, LOW);
//   
//  // Shift out the bits
//  shiftOut(dataPin, clockPin, MSBFIRST, 257);
//   
//  // ST_CP HIGH change LEDs
//  digitalWrite(latchPin, HIGH);


  for(int i=0; i<16; i++){
    // ST_CP LOW to keep LEDs from changing while reading serial data
    digitalWrite(latchPin, LOW);
   
    // Shift out the bits (Have to double down since I'm using two of them)
    shiftOut(dataPin, clockPin, MSBFIRST, numsToDisplay[i] >> 8);
    shiftOut(dataPin, clockPin, MSBFIRST, numsToDisplay[i]);

    // ST_CP HIGH change LEDs
    digitalWrite(latchPin, HIGH);
    delay(50);
  }
  
//  for(int i=0; i<256; i++){
//    // ST_CP LOW to keep LEDs from changing while reading serial data
//    digitalWrite(latchPin, LOW);
// 
//    // Shift out the bits
//    shiftOut(dataPin, clockPin, MSBFIRST, i);
// 
//    // ST_CP HIGH change LEDs
//    digitalWrite(latchPin, HIGH);
// 
//    delay(50);
//  }
//  while(1){}
}
