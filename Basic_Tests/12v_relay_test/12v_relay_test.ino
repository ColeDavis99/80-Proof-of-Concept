const int sigPin = 13;
const int vccPin = 9;


void setup() {
  pinMode(sigPin, OUTPUT);
  pinMode(vccPin, OUTPUT);

  digitalWrite(vccPin, HIGH);
}

void loop() {
  digitalWrite(sigPin, HIGH);
  delay(4000);
  digitalWrite(sigPin, LOW);
  delay(4000);
}
