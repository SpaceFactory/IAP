int redPin = 2;
int yelPin = 3;
int whtPin = 4;
int grnPin = 5;
int bluPin = 6;

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

  // DEMO all LED controls

  // Blink on/off
  blinkOn();
  delay(delayLen * 5);
  blinkOff();
  delay(delayLen * 10);

  // turn on/off one by one.
  turnEmOn();
  delay(delayLen * 5);
  turnEmOff();
  delay(delayLen * 10);

  // Cycle
  cycle();
  cycle();
  cycle();

  // Now, take a few breaths...
  breath();
  breath();
  breath();

  // Shut 'em down
  blinkOff();
}

void loop() {
  // put your main code here, to run repeatedly:

  // Note from James:
  //  comment you favourite control
  //  Hint: crtl + "/" ( cmd + "/" on a mac )
  
  cycle();
//  delay(500);

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
