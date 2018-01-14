#define trigPin 12
#define echoPin 13

int redPin = 2;
int yelPin = 3;
int whtPin = 4;
int grnPin = 5;
int bluPin = 6;

int sonarIn = 8;

int allLEDs[] = {redPin, yelPin, whtPin, grnPin, bluPin};

int delayLen = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Define if the pins are input or output
  pinMode(redPin, OUTPUT);
  pinMode(yelPin, OUTPUT);
  pinMode(whtPin, OUTPUT);
  pinMode(grnPin, OUTPUT);
  pinMode(bluPin, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Test LEDs

  // Blink on/off
  blinkOn();
  delay(delayLen * 5);
  blinkOff();
  delay(delayLen * 10);

  // Shut 'em down
  blinkOff();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance >= 250 || distance <= 0) {
    Serial.println("Out of range");
  }
  else {
    // Use this line for the Serial Plotter
    Serial.println(distance);
  }

  // ** Note from James **
  // useRange(distance, min, max)
  // distance = the distance received by the rangefinder (cm)
  // min = the distance where all LEDs will be off
  // max = the distance where all LEDs will be on
  useRange(distance, 5, 40);
  delay(500);

}


void turnEmOn() {
  // This function will turn on your LEDs
  // turn LEDs on
  digitalWrite(redPin, HIGH);
  delay(delayLen);
  digitalWrite(yelPin, HIGH);
  delay(delayLen);
  digitalWrite(whtPin, HIGH);
  delay(delayLen);
  digitalWrite(grnPin, HIGH);
  delay(delayLen);
  digitalWrite(bluPin, HIGH);
  delay(delayLen);
}

void turnEmOff() {
  // This function will turn on your LEDs
  // turn LEDs on
  digitalWrite(redPin, LOW);
  delay(delayLen);
  digitalWrite(yelPin, LOW);
  delay(delayLen);
  digitalWrite(whtPin, LOW);
  delay(delayLen);
  digitalWrite(grnPin, LOW);
  delay(delayLen);
  digitalWrite(bluPin, LOW);
  delay(delayLen);
}

void cycle() {
  // turn LEDs on
  blinkOff();
  digitalWrite(redPin, HIGH);
  delay(delayLen);
  digitalWrite(yelPin, HIGH);
  delay(delayLen);
  digitalWrite(whtPin, HIGH);
  delay(delayLen);
  digitalWrite(grnPin, HIGH);
  delay(delayLen);
  digitalWrite(bluPin, HIGH);
  delay(delayLen);
  digitalWrite(redPin, LOW);
  delay(delayLen);
  digitalWrite(yelPin, LOW);
  delay(delayLen);
  digitalWrite(whtPin, LOW);
  delay(delayLen);
  digitalWrite(grnPin, LOW);
  delay(delayLen);
  digitalWrite(bluPin, LOW);
  delay(delayLen);
}

void breath() {
  // This function will turn on your LEDs
  // turn LEDs on
  blinkOff();
  digitalWrite(redPin, HIGH);
  delay(delayLen * 1.5);
  digitalWrite(yelPin, HIGH);
  delay(delayLen * 1.5);
  digitalWrite(whtPin, HIGH);
  delay(delayLen * 1.5);
  digitalWrite(grnPin, HIGH);
  delay(delayLen * 1.5);
  digitalWrite(bluPin, HIGH);
  delay(delayLen * 5);
  // Start turning them off
  digitalWrite(bluPin, LOW);
  delay(delayLen * 1.5);
  digitalWrite(grnPin, LOW);
  delay(delayLen * 1.5);
  digitalWrite(whtPin, LOW);
  delay(delayLen * 1.5);
  digitalWrite(yelPin, LOW);
  delay(delayLen * 1.5);
  digitalWrite(redPin, LOW);
  delay(delayLen * 1.5);
}

void blinkOn() {
  digitalWrite(redPin, HIGH);
  digitalWrite(yelPin, HIGH);
  digitalWrite(whtPin, HIGH);
  digitalWrite(grnPin, HIGH);
  digitalWrite(bluPin, HIGH);
}

void blinkOff() {
  digitalWrite(redPin, LOW);
  digitalWrite(yelPin, LOW);
  digitalWrite(whtPin, LOW);
  digitalWrite(grnPin, LOW);
  digitalWrite(bluPin, LOW);
}

void turnXLEDsOn(int x) {
  for (int i = 0; i < x; i++) {
    digitalWrite(allLEDs[i], HIGH);
  }
}

void useRange(long subjectDistance, long _min, long _max) {
  //  Serial.println("remapping values");
  int numLEDs = int(map(subjectDistance, _min, _max, 0, 6));
  blinkOff();
  turnXLEDsOn(numLEDs);
}

