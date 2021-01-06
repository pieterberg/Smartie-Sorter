// Arduino Smartie Sorter Project
// Created by Pieter van den Berg
// on 1 January 2021
//
// Based on Skittles Sorter from How to Mechatronics
// https://howtomechatronics.com/projects/arduino-color-sorter-project/

// Calibration settings
// Use the calibration functions to calibrate the following values
const int redMaxFrequency = 106;
const int greenMaxFrequency = 117;
const int blueMaxFrequency = 90;

const int redMinFrequency = 446;
const int greenMinFrequency = 574;
const int blueMinFrequency = 487;

// Colour Sensor's pins
const int colourSensorS0 = 6;
const int colourSensorS1 = 5;
const int colourSensorS2 = 4;
const int colourSensorS3 = 3;
const int colourSensorLED = 7;
const int colourSensorOut = 2;

// Arrays of calibration options
String sensorCalibrationOptions[2] = {"White", "Black"};
String smartieColours[8] = {"Red", "Orange", "Yellow", "Green", "Blue", "Mauve", "Pink", "Brown"};

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
  bool isCalibrating = false;

  // Print the calibration menu
  Serial.println("Please enter a number to continue...");

  Serial.println();

  for (int i = 0; i < sizeof(sensorCalibrationOptions)/sizeof(sensorCalibrationOptions[0]); i++)
  {
    Serial.print("   ");
    Serial.print(i + 1);
    Serial.print(". Calibrate ");
    Serial.print(sensorCalibrationOptions[i]);
    Serial.println(" frequencies");
  }

  Serial.println();
  Serial.println("   3. Calibrate Smartie colours");
  
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

  // Serial.print("red: ");
  // Serial.print(readRedValue());
  // Serial.print("  green: ");
  // Serial.print(readGreenValue());
  // Serial.print("  blue: ");
  // Serial.println(readBlueValue());

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
  redRGBValue = mapFrequencyToRGB(redFrequency, 0);

  return redRGBValue;
}

// Reads the green RGB value of the Smartie
int readGreenValue() {
  int greenFrequency;
  int greenRGBValue;

  // Set up the colour sensor's pins to read the green frequency value
  digitalWrite(colourSensorS2, HIGH);
  digitalWrite(colourSensorS3, HIGH);

  // Read the green colour frequency
  greenFrequency = pulseIn(colourSensorOut, LOW);

  // Map the frequency to a RGB value
  greenRGBValue = mapFrequencyToRGB(greenFrequency, 1);

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
  blueRGBValue = mapFrequencyToRGB(blueFrequency, 2);

  return blueRGBValue;
}

// Maps the read frequency to a RGB value
int mapFrequencyToRGB(int frequency, int colour) {
  int RGBValue;

  // Map the frequency to the cprresponding RGB value
  switch (colour)
  {
    case 0:
      RGBValue = map(frequency, redMaxFrequency, redMinFrequency, 255, 0);
      break;

    case 1:
      RGBValue = map(frequency, greenMaxFrequency, greenMinFrequency, 255, 0);
      break;

    case 2:
      RGBValue = map(frequency, blueMaxFrequency, blueMinFrequency, 255, 0);
      break;

    default:
      break;
  }

  // Limit the upper and lower values
  if (RGBValue > 255) {
    RGBValue = 255;
  }

  if (RGBValue < 0) {
    RGBValue = 0;
  }

  return RGBValue;
}

// Calibrate the color sensor's frequencies
void calibrateColorFrequency(int selectedColour) {
  int redFrequency = 0;
  int greenFrequency = 0;
  int blueFrequency = 0;

  int currentRedReading;
  int currentGreenReading;
  int currentBlueReading;

  char currentSelection;

  printDivider();

  Serial.print("Starting frequency calibration for ");
  Serial.print(sensorCalibrationOptions[selectedColour]);
  Serial.println();
  Serial.print("Place ");
  Serial.print(sensorCalibrationOptions[selectedColour]);
  Serial.print(" in front of the sensor and enter 'c' to start calibration...");
  Serial.println(); 
  Serial.println(); 

  do
  {
    currentSelection = Serial.read();
  } while((currentSelection != 'c') && (currentSelection != 'q'));

  // Return if 'q' is entered
  if (currentSelection == 'q'){  
   Serial.print("Canceling calibration for ");
   Serial.print(sensorCalibrationOptions[selectedColour]);
   Serial.println();
   printDivider();
   return;
  }

  Serial.println("\t\tRed\tGreen\tBlue");

  for (int i = 0; i < 10; i++) {
    // Read the frequency given off by each diode
    currentRedReading = readRedValue();
    currentGreenReading = readGreenValue();
    currentBlueReading = readBlueValue();
    
    // Increase the total counter
    redFrequency += currentRedReading;
    greenFrequency += currentGreenReading;
    blueFrequency += currentBlueReading;
 
    Serial.print("   Reading ");
    Serial.print(i + 1);

    // Aligns spacing before colon
    if (i!= 9) {
      Serial.print(" ");
    }
    
    Serial.print(":\t");
    Serial.print(currentRedReading);
    Serial.print("\t");
    Serial.print(currentGreenReading);
    Serial.print("\t");
    Serial.println(currentBlueReading);

    delay(1000);
  }

  // Find the average frewuency for each diode
  redFrequency /= 10;
  greenFrequency /= 10;
  blueFrequency /= 10;

  // Prints the average frequency for the selected colour
  Serial.println();
  Serial.print("   ");
  Serial.print(sensorCalibrationOptions[selectedColour]);
  Serial.print(" freq:\t");
  Serial.print(redFrequency);
  Serial.print("\t");
  Serial.print(greenFrequency);
  Serial.print("\t");
  Serial.print(blueFrequency);
  
  Serial.println();
  printDivider();
}

// Print divider
void printDivider() {
  Serial.println();

  for (int i = 0; i < 72 ; i++) {
    Serial.print("-");
  }

  Serial.println();
}
