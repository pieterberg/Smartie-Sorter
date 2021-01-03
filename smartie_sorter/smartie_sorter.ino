// Arduino Smartie Sorter Project
// Created by Pieter van den Berg
// on 1 January 2021
//
// Based on Skittles Sorter from How to Mechatronics
// https://howtomechatronics.com/projects/arduino-color-sorter-project/


// Calibration settings
// Use colour_calibration.ino to calibrate the following values
    const int redMaxFrequency = 1419;
    const int greenMaxFrequency = 1351;
    const int blueMaxFrequency = 1109;

    const int redMinFrequency = 1773;
    const int greenMinFrequency = 2464;
    const int blueMinFrequency = 2217;

// Colour Sensor's pins
const int colourSensorS0 = 6;
const int colourSensorS1 = 5;
const int colourSensorS2 = 4;
const int colourSensorS3 = 3;
const int colourSensorLED = 7;
const int colourSensorOut = 2;


void setup() {
  // Set up Colour Sensor's pins
  pinMode(colourSensorS0, OUTPUT);
  pinMode(colourSensorS1, OUTPUT);
  pinMode(colourSensorS2, OUTPUT);
  pinMode(colourSensorS3, OUTPUT);
  pinMode(colourSensorLED, OUTPUT);
  pinMode(colourSensorOut, INPUT);

  // Set scaling frequency of colour sensor to 2%
  digitalWrite(colourSensorS0, LOW);
  digitalWrite(colourSensorS1, HIGH);

  digitalWrite(colourSensorLED, HIGH);

  // Begin a serial channel
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  Serial.print("red: ");
  Serial.print(readRedValue());
  Serial.print("  green: ");
  Serial.print(readGreenValue());
  Serial.print("  blue: ");
  Serial.println(readBlueValue());

  delay(1000);
}

// Reads the red RGB value of the Smartie
int readRedValue() {
  int redFrequency;
  int redRGBValue;

  // Set up the colour sensor's pins to read the red frequency value
  digitalWrite(colourSensorS2, LOW);
  digitalWrite(colourSensorS3, LOW);

  // Read the red colour frequency
  redFrequency = pulseIn(colourSensorOut, LOW);

  // Map the frequency to a RGB value
  redRGBValue = map(redFrequency, redMaxFrequency, redMinFrequency, 255, 0);
  return redRGBValue;
}

// Reads the green RGB value of the Smartie
int readGreenValue() {
  int greenFrequency;
  int greenRGBValue;

  // Set up the colour sensor's pins to read the green frequency value
  digitalWrite(colourSensorS2, HIGH);
  digitalWrite(colourSensorS3,HIGH);

  // Read the green colour frequency
  greenFrequency = pulseIn(colourSensorOut, LOW);

  // Map the frequency to a RGB value
  greenRGBValue = map(greenFrequency, greenMaxFrequency, greenMinFrequency, 255, 0);
  return greenRGBValue;
}

// Reads the blue RGB value of the Smartie
int readBlueValue() {
  int blueFrequency;
  int blueRGBValue;


  // Set up the colour sensor's pins to read the blue frequency value
  digitalWrite(colourSensorS2, LOW);
  digitalWrite(colourSensorS3, HIGH);

  // Read the blue colour frequency
  blueFrequency = pulseIn(colourSensorOut, LOW);

  // Map the frequency to a RGB value
  blueRGBValue = map(blueFrequency, blueMaxFrequency, blueMinFrequency, 255, 0);
  return blueRGBValue;
}
