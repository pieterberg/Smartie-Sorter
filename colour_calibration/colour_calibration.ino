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

// Arrays of calibration options
String sensorColours[3] = {"Red", "Green", "Blue"};

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
  char currentSelection = '0';
  
  // Opens the calibration menu

  // Print the calibration menu
  Serial.println("Please enter a number to continue...");

  Serial.println();

  for (int i = 0; i < 3; i++)
  {
    Serial.print("   ");
    Serial.print(i + 1);
    Serial.print(". Calibrate ");
    Serial.print(sensorColours[i]);
    Serial.println(" frequencies");
  }

  Serial.println();
  Serial.println("   4. Calibrate Smartie colours");
  
  // Wait for selected calibration function
  do
  {
    currentSelection = Serial.read();
  } while ((currentSelection != '1') && (currentSelection != '2') && (currentSelection != '3'));
 
 if ((currentSelection == '1') || (currentSelection == '2') || (currentSelection == '3')) 
 {
    // Call the calibration function with the selected colour
    calibrateColorFrequency((currentSelection - '0') - 1);
 }

 currentSelection = '0';
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

// Calibrate the color sensor's frequencies
int calibrateColorFrequency(int selectedColour) {
  int frequencyValue = 0;
  int currentReading;

  Serial.println();
  Serial.println("-----------------------------------------------------------------");

  Serial.println();
  Serial.print("Starting frequency calibration for ");
  Serial.print(sensorColours[selectedColour]);
  Serial.println();
  Serial.print("Place ");
  Serial.print(sensorColours[selectedColour]);
  Serial.print(" in front of the sensor and enter 'c' to start calibration...");
  Serial.println(); 
  Serial.println(); 

  while(Serial.read() != 'c')
  {
    // Wait
  }

  for (int i = 0; i < 10; i++) {
    // Use the correct colour sensing function
    switch (selectedColour)
    {
    case 0:
      currentReading = readRedValue();
      break;

    case 1:
      currentReading = readGreenValue();
      break;

    case 2:
      currentReading = readBlueValue();
      break;
    }
    
    // Increase the total counter
    frequencyValue += currentReading;
 
    Serial.print("   Reading ");
    Serial.print(i + 1);
    Serial.print(":  ");
    Serial.println(currentReading);

    delay(1000);
  }

  frequencyValue /= 10;

  // Prints the average frequency for the selected colour
  Serial.println();
  Serial.print("   ");
  Serial.print(sensorColours[selectedColour]);
  Serial.print(" frequency:  ");
  Serial.print(frequencyValue);
  
  Serial.println();
  Serial.println();
  Serial.println("-----------------------------------------------------------------");
  Serial.println();

}
