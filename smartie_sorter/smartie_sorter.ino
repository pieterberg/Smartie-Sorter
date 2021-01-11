// Arduino Smartie Sorter Project
// Created by Pieter van den Berg
// on 1 January 2021
//
// Based on Skittles Sorter from How to Mechatronics
// https://howtomechatronics.com/projects/arduino-color-sorter-project/

// Calibration settings
// Use the calibration functions to calibrate the following values
const int redMaxFrequency = 239;
const int greenMaxFrequency = 219;
const int blueMaxFrequency = 163;

const int redMinFrequency = 345;
const int greenMinFrequency = 324;
const int blueMinFrequency = 240;

// Colour Sensor's pins
const int colourSensorS0 = 6;
const int colourSensorS1 = 5;
const int colourSensorS2 = 4;
const int colourSensorS3 = 3;
const int colourSensorLED = 7;
const int colourSensorOut = 2;

// Arrays of calibration options
bool isCalibrating = false;
String sensorCalibrationOptions[2] = {"White", "Black"};
String smartieColours[9] = {"Red", "Orange", "Yellow", "Green", "Blue", "Mauve", "Pink", "Brown", "No"};

// The RGB values for each Smartie colour
const int redSmartieRedRGB = 197;
const int redSmartieGreenRGB = 142;
const int redSmartieBlueRGB = 147;

const int orangeSmartieRedRGB = 220;
const int orangeSmartieGreenRGB = 173;
const int orangeSmartieBlueRGB = 154;

const int yellowSmartieRedRGB = 240;
const int yellowSmartieGreenRGB = 205;
const int yellowSmartieBlueRGB = 164;

const int greenSmartieRedRGB = 186;
const int greenSmartieGreenRGB = 172;
const int greenSmartieBlueRGB = 149;

const int blueSmartieRedRGB = 162;
const int blueSmartieGreenRGB = 156;
const int blueSmartieBlueRGB = 169;

const int mauveSmartieRedRGB = 173;
const int mauveSmartieGreenRGB = 165;
const int mauveSmartieBlueRGB = 183;

const int pinkSmartieRedRGB = 204;
const int pinkSmartieGreenRGB = 169;
const int pinkSmartieBlueRGB = 184;

const int brownSmartieRedRGB = 155;
const int brownSmartieGreenRGB = 125;
const int brownSmartieBlueRGB = 115;

const int noSmartieRedRGB = 255;
const int noSmartieGreenRGB = 255;
const int noSmartieBlueRGB = 255;

// Tolerance for Smartie colour detecion
const int tolerance = 12;

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
  Serial.println("Welcome to the menu for the Arduino Smartie Sorter");
  Serial.println("Enter 'c' to enter the calibration");
  Serial.println("Enter 'q' to cancel calibration");

  printDivider();
}

void loop() {

  // Open the calibration menu if 'c' is entered 
  if (Serial.read() == 'c')
  {
    isCalibrating = true;
  }

  if (isCalibrating)
  {
    printDivider();
    openCalibrationMenu();
  }
  else 
  {
    detectSmartieColour();
  }

  delay(1000);
}

// Reads the red RGB value of the Smartie
int readRedValue(bool readRGB) {
  int redFrequency;
  int redRGBValue;

  // Set up the colour sensor's pins to read the red frequency value
  digitalWrite(colourSensorS2, LOW);
  digitalWrite(colourSensorS3, LOW);

  // Read the red colour frequency
  redFrequency = pulseIn(colourSensorOut, LOW);

  if (readRGB)
  {
    // Map the frequency to a RGB value and return it
    redRGBValue = mapFrequencyToRGB(redFrequency, 0);
    return redRGBValue;
  }
  else 
  {
    return redFrequency;
  }
}

// Reads the green RGB value of the Smartie
int readGreenValue(bool readRGB) {
  int greenFrequency;
  int greenRGBValue;

  // Set up the colour sensor's pins to read the green frequency value
  digitalWrite(colourSensorS2, HIGH);
  digitalWrite(colourSensorS3, HIGH);

  // Read the green colour frequency
  greenFrequency = pulseIn(colourSensorOut, LOW);

  if (readRGB)
  {
    // Map the frequency to a RGB value and return it
    greenRGBValue = mapFrequencyToRGB(greenFrequency, 1);
    return greenRGBValue;
  }
  else 
  {
    return greenFrequency;
  }
}

// Reads the blue RGB value of the Smartie
int readBlueValue(bool readRGB) {
  int blueFrequency;
  int blueRGBValue;

  // Set up the colour sensor's pins to read the blue frequency value
  digitalWrite(colourSensorS2, LOW);
  digitalWrite(colourSensorS3, HIGH);

  // Read the blue colour frequency
  blueFrequency = pulseIn(colourSensorOut, LOW);

  if (readRGB)
  {
    // Map the frequency to a RGB value and return it
    blueRGBValue = mapFrequencyToRGB(blueFrequency, 2);
    return blueRGBValue;
  }
  else 
  {
    return blueFrequency;
  }
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
   return;
  }

  Serial.println("\t\tRed\tGreen\tBlue");

  for (int i = 0; i < 10; i++) {
    // Read the frequency given off by each diode
    currentRedReading = readRedValue(false);
    currentGreenReading = readGreenValue(false);
    currentBlueReading = readBlueValue(false);
    
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
}

// Print divider
void printDivider() {
  Serial.println();

  for (int i = 0; i < 72 ; i++) {
    Serial.print("-");
  }

  Serial.println();
}

// Print the calibration menu 
void openCalibrationMenu() {
  char currentSelection = '0';
  
  // Print the calibration menu
  Serial.println("Welcome to the Smartie Sorter calibration menu");
  Serial.println("Please enter a number to continue...");

  // Print the options
  Serial.println(); 
  Serial.println("   1. Calibrate white frequency");
  Serial.println("   2. Calibrate black frequency");
  Serial.println("   3. Calibrate Smartie colours");
  
  // Wait for selected calibration function
  do
  {
    currentSelection = Serial.read();
  } while ((currentSelection != '1') && (currentSelection != '2') && (currentSelection != '3') && (currentSelection != 'q'));
 
 // Call the correct calibration function
 if ((currentSelection == '1') || (currentSelection == '2')) 
 {
    // Call the calibration function with the selected colour
    calibrateColorFrequency((currentSelection - '0') - 1);
 }

  if (currentSelection == '3') {
    OpenSmartieColourCalibrationMenu();
  }
 
 // Exit the calibration menu
 if (currentSelection == 'q')
 {
    isCalibrating = false;
    printDivider();
    return;
 } 
}

// Print the Smartie colour calibration menu
void OpenSmartieColourCalibrationMenu() {
  char currentSelection = '0';

  do{
    // Print a divider before the Smartie colour calibration menu
    printDivider();
    
    // Print the calibration menu
    Serial.println("Smartie Colour Calibration");
    Serial.println("Please select a colour to calibrate...");

    // Print the options
    Serial.println(); 
    Serial.println("   1. Calibrate Red");
    Serial.println("   2. Calibrate Orange");
    Serial.println("   3. Calibrate Yellow");
    Serial.println("   4. Calibrate Green");
    Serial.println("   5. Calibrate Blue");
    Serial.println("   6. Calibrate Mauve");
    Serial.println("   7. Calibrate Pink");
    Serial.println("   8. Calibrate Brown");
    Serial.println("   9. Calibrate No Smartie");

    do
    {
      currentSelection = Serial.read();
    } while ((currentSelection != '1') && (currentSelection != '2') && (currentSelection != '3') && (currentSelection != '4') && (currentSelection != '5') && (currentSelection != '6') && (currentSelection != '7') && (currentSelection != '8') && (currentSelection != '9') && (currentSelection != 'q'));

    if ((currentSelection == '1') || (currentSelection == '2') || (currentSelection == '3') || (currentSelection == '4') || (currentSelection == '5') || (currentSelection == '6') || (currentSelection == '7') || (currentSelection == '8') || (currentSelection == '9'))
    {
      calibrateSmartieColours((currentSelection - '0') - 1);
    }
  } while (currentSelection != 'q');
 
}

// Function to calibrate the RGB vaue of the Smarties
void calibrateSmartieColours(int selectedColour) {
  int redRGBValue = 0;
  int greenRGBValue = 0;
  int blueRGBValue = 0;

  int currentRedReading;
  int currentGreenReading;
  int currentBlueReading;

  char currentSelection;

  printDivider();

  Serial.print("Starting colour calibration for ");
  Serial.print(smartieColours[selectedColour]); 
  Serial.print(" Smartie");
  Serial.println();
  Serial.print("Place ");
  Serial.print(smartieColours[selectedColour]);
  Serial.print(" Smartie in front of the sensor and enter 'c' to start calibration...");
  Serial.println(); 
  Serial.println(); 

  do
  {
    currentSelection = Serial.read();
  } while((currentSelection != 'c') && (currentSelection != 'q'));

  // Return to calibration menu if 'q' is entered
  if (currentSelection == 'q'){  
   Serial.print("Canceling calibration for ");
   Serial.print(smartieColours[selectedColour]);
   Serial.println();
   return;
  }

  Serial.println("\t\tRed\tGreen\tBlue");

  for (int i = 0; i < 10; i++) {
    // Read the frequency given off by each diode
    currentRedReading = readRedValue(true);
    currentGreenReading = readGreenValue(true);
    currentBlueReading = readBlueValue(true);
    
    // Increase the total counter
    redRGBValue += currentRedReading;
    greenRGBValue += currentGreenReading;
    blueRGBValue += currentBlueReading;
 
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

  // Find the average frequency for each diode
  redRGBValue /= 10;
  greenRGBValue /= 10;
  blueRGBValue /= 10;

  // Prints the average frequency for the selected colour
  Serial.println();
  Serial.print("   ");
  Serial.print(smartieColours[selectedColour]);

  if (selectedColour == 8) {
    Serial.print(" S. RGB ");
  }
  else {
    Serial.print(" RGB");

    for (unsigned int i = 0; i < 6 - (smartieColours[selectedColour]).length() ; i++)
    {
      Serial.print(" ");
    }
  } 

  Serial.print(":\t");
  Serial.print(redRGBValue);
  Serial.print("\t");
  Serial.print(greenRGBValue);
  Serial.print("\t");
  Serial.print(blueRGBValue);
  Serial.println();
}

// Function to detect which colour Smartie is placed in front of the colour sensor
int detectSmartieColour() {
  int redRGBValue = 0;
  int greenRGBValue = 0;
  int blueRGBValue = 0;

  int currentRedReading;
  int currentGreenReading;
  int currentBlueReading;

  // Read the RGB value of the Smartie in fornt of the sensor
  for (int i = 0; i < 10; i++) {
    // Read the frequency given off by each diode
    currentRedReading = readRedValue(true);
    currentGreenReading = readGreenValue(true);
    currentBlueReading = readBlueValue(true);
    
    // Increase the total counter
    redRGBValue += currentRedReading;
    greenRGBValue += currentGreenReading;
    blueRGBValue += currentBlueReading;

    delay(10);
  }

  // Find the average frequency for each diode
  redRGBValue /= 10;
  greenRGBValue /= 10;
  blueRGBValue /= 10;

  // Determine which colour is placed in front of the sensor
  if ((redRGBValue > redSmartieRedRGB - tolerance) && (redRGBValue < redSmartieRedRGB + tolerance) && (greenRGBValue > redSmartieGreenRGB - tolerance) && (greenRGBValue < redSmartieGreenRGB + tolerance) && (blueRGBValue > redSmartieBlueRGB - tolerance) && (blueRGBValue < redSmartieBlueRGB + tolerance))
  {
    // Smartie is red
    Serial.println("Red");
  }
  else if ((redRGBValue > orangeSmartieRedRGB - tolerance) && (redRGBValue < orangeSmartieRedRGB + tolerance) && (greenRGBValue > orangeSmartieGreenRGB - tolerance) && (greenRGBValue < orangeSmartieGreenRGB + tolerance) && (blueRGBValue > orangeSmartieBlueRGB - tolerance) && (blueRGBValue < orangeSmartieBlueRGB + tolerance))
  {
    // Smartie is orange
    Serial.println("Orange");
  }
  else if ((redRGBValue > yellowSmartieRedRGB - tolerance) && (redRGBValue < yellowSmartieRedRGB + tolerance) && (greenRGBValue > yellowSmartieGreenRGB - tolerance) && (greenRGBValue < yellowSmartieGreenRGB + tolerance) && (blueRGBValue > yellowSmartieBlueRGB - tolerance) && (blueRGBValue < yellowSmartieBlueRGB + tolerance))
  {
    // Smartie is yellow
    Serial.println("Yellow");
  }
  else if ((redRGBValue > greenSmartieRedRGB - tolerance) && (redRGBValue < greenSmartieRedRGB + tolerance) && (greenRGBValue > greenSmartieGreenRGB - tolerance) && (greenRGBValue < greenSmartieGreenRGB + tolerance) && (blueRGBValue > greenSmartieBlueRGB - tolerance) && (blueRGBValue < greenSmartieBlueRGB + tolerance))
  {
    // Smartie is green
    Serial.println("Green");
  }
  else if ((redRGBValue > blueSmartieRedRGB - tolerance) && (redRGBValue < blueSmartieRedRGB + tolerance) && (greenRGBValue > blueSmartieGreenRGB - tolerance) && (greenRGBValue < blueSmartieGreenRGB + tolerance) && (blueRGBValue > blueSmartieBlueRGB - tolerance) && (blueRGBValue < blueSmartieBlueRGB + tolerance))
  {
    // Smartie is blue
    Serial.println("Blue");
  }
  else if ((redRGBValue > mauveSmartieRedRGB - tolerance) && (redRGBValue < mauveSmartieRedRGB + tolerance) && (greenRGBValue > mauveSmartieGreenRGB - tolerance) && (greenRGBValue < mauveSmartieGreenRGB + tolerance) && (blueRGBValue > mauveSmartieBlueRGB - tolerance) && (blueRGBValue < mauveSmartieBlueRGB + tolerance))
  {
    // Smartie is mauve
    Serial.println("Mauve");
  }
  else if ((redRGBValue > pinkSmartieRedRGB - tolerance) && (redRGBValue < pinkSmartieRedRGB + tolerance) && (greenRGBValue > pinkSmartieGreenRGB - tolerance) && (greenRGBValue < pinkSmartieGreenRGB + tolerance) && (blueRGBValue > pinkSmartieBlueRGB - tolerance) && (blueRGBValue < pinkSmartieBlueRGB + tolerance))
  {
    // Smartie is pink
    Serial.println("Pink");
  }
  else if ((redRGBValue > brownSmartieRedRGB - tolerance) && (redRGBValue < brownSmartieRedRGB + tolerance) && (greenRGBValue > brownSmartieGreenRGB - tolerance) && (greenRGBValue < brownSmartieGreenRGB + tolerance) && (blueRGBValue > brownSmartieBlueRGB - tolerance) && (blueRGBValue < brownSmartieBlueRGB + tolerance))
  {
    // Smartie is brown
    Serial.println("Brown");
  }
  else
  if ((redRGBValue > noSmartieRedRGB - tolerance) && (redRGBValue < noSmartieRedRGB + tolerance) && (greenRGBValue > noSmartieGreenRGB - tolerance) && (greenRGBValue < noSmartieGreenRGB + tolerance) && (blueRGBValue > noSmartieBlueRGB - tolerance) && (blueRGBValue < noSmartieBlueRGB + tolerance))
  {
    // No Smartie
    Serial.println("No Smartie");
  }
  else
  {
    // Unknown
    Serial.println("Unknown");
  }
  








}
