int  motionIn = 8;
bool isMotion = false;

int  ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motionIn, INPUT);
  pinMode(ledPin,  OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  isMotion = digitalRead(motionIn);
  
  if (isMotion == true) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion detected");
  }
  else {
    digitalWrite(ledPin, LOW);
    Serial.println("No Motion");
  }
}
