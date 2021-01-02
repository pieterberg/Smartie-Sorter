// Sketch for colour calibration of the Smarties for the Smartie Sorter
// Created by Pieter van den Berg
// on 1 January 2021
//
// Based on Skittles Sorter from How to Mechatronics
// https://howtomechatronics.com/projects/arduino-color-sorter-project/


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
  
  // Print welcome message
  Serial.println("Welcome to the calibration menu for the Arduino Smartie Sorter");
  
}

void loop() {
  char currentSelection;
  // Opens the calibration menu

  // Print the calibration menu
  Serial.println("Please enter a number to continue...");

  Serial.println();
  Serial.println("1. Calibrate white frequency");
  Serial.println("2. Calibrate black frequency");
  Serial.println("3. Calibrate smartie colours");

  // Wait for selected calibration function
  do
  {
    currentSelection = Serial.read();
  } while ((currentSelection != '1') && (currentSelection != '2'));
 
  switch (currentSelection)
    {
      case '1':
        calibrateWhiteFrequency();
        break;

      case '2':
        calibrateBlackFrequency();
        break;
      
      default:
        break;
    }
  
}

/* Color reading functions */

// Reads the red RGB value of the Smartie
int readRedValue() {
  int redFrequency;

  // Set up the colour sensor's pins to read the red frequency value
  digitalWrite(colourSensorS2, LOW);
  digitalWrite(colourSensorS3, LOW);

  // Read the red colour frequency
  redFrequency = pulseIn(colourSensorOut, LOW);
  return redFrequency;
}

// Reads the green RGB value of the Smartie
int readGreenValue() {
  int greenFrequency;

  // Set up the colour sensor's pins to read the green frequency value
  digitalWrite(colourSensorS2, HIGH);
  digitalWrite(colourSensorS3,HIGH);

  // Read the green colour frequency
  greenFrequency = pulseIn(colourSensorOut, LOW);
  return greenFrequency;
}

// Reads the blue RGB value of the Smartie
int readBlueValue() {
  int blueFrequency;

  // Set up the colour sensor's pins to read the blue frequency value
  digitalWrite(colourSensorS2, LOW);
  digitalWrite(colourSensorS3, HIGH);

  // Read the blue colour frequency
  blueFrequency = pulseIn(colourSensorOut, LOW);
  return blueFrequency;
}


/* Calibration functions */

// Calibrate the color sensor's frequency for white
int calibrateWhiteFrequency() {
  int whiteValue = 0;
  int currentReading;

  Serial.println();
  Serial.println("Starting frequency calibration for white");
  Serial.println("Place white in front of the sensor and enter 'c' to start calibration...");
  Serial.println("");

  while(Serial.read() != 'c')
  {
    // Wait
  }

  for (int i = 0; i < 10; i++) {
    // Uses the blue frequency for colour calibration
    currentReading = readBlueValue();
    whiteValue += currentReading;

    Serial.print("Reading ");
    Serial.print(i + 1);
    Serial.print(":  ");
    Serial.println(currentReading);

    delay(1000);
  }

  whiteValue /= 10;

  // Prints the average frequency for white
  Serial.println();
  Serial.print("White frequency:  ");
  Serial.print(whiteValue);
  Serial.println();
  Serial.println();
}

// Calibrate the color sensor's frequency for black
int calibrateBlackFrequency() {
  int blackValue = 0;
  int currentReading;

  Serial.println();
  Serial.println("Starting frequency calibration for black");
  Serial.println("Place black in front of the sensor and enter 'c' to start calibration...");
  Serial.println("");

  while(Serial.read() != 'c')
  {
    // Wait
  }

  for (int i = 0; i < 10; i++) {
    // Uses the blue frequency for colour calibration
    currentReading = readBlueValue();
    blackValue += currentReading;

    Serial.print("Reading ");
    Serial.print(i + 1);
    Serial.print(":  ");
    Serial.println(currentReading);

    delay(1000);
  }

  blackValue /= 10;

  // Prints the average frequency for white
  Serial.println();
  Serial.print("Black frequency:  ");
  Serial.print(blackValue);
  Serial.println();
  Serial.println();
}
