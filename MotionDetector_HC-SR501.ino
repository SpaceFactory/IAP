// Code sourced from http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/arduino-hc-sr501-motion-sensor-tutorial/#attachment%20wp-att-2111/0/
//Henry's Bench
// HC-SR501 Motion Detector
// Sample Sketch

int ledPin = 13;  // LED on Pin 13 of Arduino
int pirPin = 7; // Input for HC-S501

int pirValue; // Place to store read PIR Value


void setup() {
  
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
 
  digitalWrite(ledPin, LOW);
  
  
  
}

void loop() {
  pirValue = digitalRead(pirPin);
  digitalWrite(ledPin, pirValue);

}

