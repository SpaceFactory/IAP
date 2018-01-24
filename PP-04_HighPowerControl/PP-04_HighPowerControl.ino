/*
By:    David Malott
Org:   SpaceFactory.io
Date:  January 24th 2018
Description:
  This program uses a HC-SR04 Ping / Range finder to return a distance which is then mapped to the intensity of a color LED
*/

#include "application.h"

// Assign led r,g,b to pins

int ledB = D0;
int ledG = D1;
int ledR = D2;

// Assign range finder trigger and echo to pins
int trigPin = D4;
int echoPin = D3;

// Assign the range finder distance near (lower) and far (upper) thresholds
int near = 5;
int far = 150;

// Set the duration of LED pulse

int pulseOn = 2000;
int pulseOff = 1000;

// Create an array containing basic color values

int numColors = 7;

int rgbArr[7][3] = {
    {255, 255, 255}, // WHITE
    {255,   0,   0}, // RED
    {255, 255,   0}, // YELLOW
    {255,   0, 255}, // MAGENTA
    {0,     0, 255}, // BLUE
    {0,   255, 255}, // CYAN
    {0  ,   0,   0}, // OFF (BLACK)
    };


// Run setup once

void setup() {

    // Assign LED pins
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(ledB, OUTPUT);

    // Initiate range finder
    Serial.begin(115200);

    // Assign range finder trigger and echo pins
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

// Repeat loop

void loop() {
    int dist; // Distance calculated by the range finder
    float alpha; // Alpha value mapped to distance

    // Find distance with ping(Trigger pin, Echo pin, delay (ms), visual=true|info=false)
    dist = ping(trigPin, echoPin, 0.5, true);

    // Calculate alpha with mapAlpha(distance)
    alpha = mapAlpha(dist);

    // Fade one color relative to distance
    pulseRGB(255, 255, 255, alpha, 50);

    /* Cycle through colors and blink LEDs
    for (int i = 0; i < numColors; i++ ) {
        pulseRGB(rgbArr[i][0], rgbArr[i][1], rgbArr[i][2], alpha, pulseOn);
    }*/

}

// Pulse LED using color, alpha, and duration parameters

void pulseRGB(int r, int g, int b, float alpha, int duration) {
    // Adjusts r, g, b value with alpha channel.
    r = RGBA(r, alpha);
    g = RGBA(g, alpha);
    b = RGBA(b, alpha);
    // Write hue to LED
    analogWrite(ledR, r);
    analogWrite(ledG, g);
    analogWrite(ledB, b);
    delay(duration);
}


// Map distance to alpha channel.  The alpha parameter is a number between 0.0 (fully transparent) and 1.0 (fully opaque).

float mapAlpha(int dist) {
    float alpha;
    float mapfloat;

    // Adjust the distance within the threshold if out of bounds
    if (dist < near) {
        dist = near;
    }
    else if (dist > far) {
        dist = far;
    }

    // Map an inverse relationship between distance and alpha, i.e., the closer the distance the higher the alpha
    // Use function map(input, input_min, input_max, out_min, output_max)
    mapfloat = float(map(dist, near, far, 0, 100));
    alpha = 1.0 - (mapfloat / 100.0);
    // Send a publish...
    // String data_str = String(alpha);
    // Particle.publish("Alpha:",data_str);
    return alpha;
}

// Adjusts r, g, b value with alpha channel.
// RGBA color values are an extension of RGB color values with an alpha channel - which specifies the opacity of the object.

int RGBA(int hue, float alpha) {
    int rgba;
    rgba = int(hue * alpha);
    return rgba;
}

// Initiate a ping from the range sensor and returns the distance in cm.

int ping(pin_t trig_pin, pin_t echo_pin, uint32_t wait, bool info)
{
    uint32_t duration, inches, cm;
    static bool init = false;
    if (!init) {
        pinMode(trig_pin, OUTPUT);
        digitalWriteFast(trig_pin, LOW);
        pinMode(echo_pin, INPUT);
        delay(50);
        init = true;
    }

    /* Trigger the sensor by sending a HIGH pulse of 10 or more microseconds */
    digitalWriteFast(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWriteFast(trig_pin, LOW);

    duration = pulseIn(echo_pin, HIGH);

    /* Convert the time into a distance */
    // Sound travels at 1130 ft/s (73.746 us/inch)
    // or 340 m/s (29 us/cm), out and back so divide by 2
    // Ref: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
    inches = duration / 74 / 2;
    cm = duration / 29 / 2;

    if (info) { /* Visual Output */
        Serial.printf("%2d:", inches);
        for(int x=0;x<inches;x++) Serial.print("#");
        Serial.println();
    } else { /* Informational Output */
        Serial.printlnf("%6d in / %6d cm / %6d us", inches, cm, duration);
    }
    delay(wait); // slow down the output

    return int(cm);
}
