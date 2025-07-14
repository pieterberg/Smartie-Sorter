// Project name: Smartie Sorter 3000
// Sketch name:  calibration.ino
// Created by:   Pieter van den Berg
// Created on:   14 July 2025

// Code to calibrate and setup the Smartie Sorter 3000's mini arcade game enclosure

void setup() {
  // Begin a serial channel
  Serial.begin(9600);

  // Print the welcome message
  Serial.println("Welcome to the Smartie Sorter 3000's calibration menu");
  Serial.println();

  // Print a divider
  printDivider();
}

void loop() {
  // Print the calibration menu
  printCalibrationMenu();

}

// A function for printing the main calibration menu
void printCalibrationMenu() {

  // Create a variable for keeping track of the selected calibration option
  char current_selection = '0';

  // Print the introduction
  Serial.println("Smartie Sorter 3000 calibration menu");
  Serial.println("Please select an option...");
  Serial.println();

  // Print the list of calibration options
  Serial.println("   1. Colour sensor calibration");
  Serial.println("   2. Servo calibration");
  Serial.println("   3. EEPROM settings");
  Serial.println();

  // Read the selected calibration option
  do {
    current_selection = Serial.read();
  } while ((current_selection != '1') && (current_selection != '2') && (current_selection != '3'));

  // Print a divider
  printDivider();

  // Call the selected calibration function
  switch (current_selection) {
    case '3':
      printEEPROMMenu();
      break;      
  }
}

// A function for printing the EEPROM settings menu
void printEEPROMMenu() {

  // Create a variable for keeping track of the selected EEPROM setting
  char current_selection = '0';

  // Print the introduction
  Serial.println("EEPROM settings menu");
  Serial.println("Please select an option...");
  Serial.println();

  // Print the list of EEPROM settings
  Serial.println("   1. View the number of sorted Smarties");
  Serial.println("   2. View the number of sorted M&M's");
  Serial.println("   3. Reset the number of sorted Smarties");
  Serial.println("   4. Reset the number of sorted M&M's");
  Serial.println("   5. Return to the main menu");
  Serial.println();

  // Read the selected EEPROM setting
  do {
    current_selection = Serial.read();
  } while ((current_selection != '1') && (current_selection != '2') && (current_selection != '3') && (current_selection != '4') && (current_selection != '5'));

  // Print a divider
  printDivider();

  
  if (current_selection == '1'){
    
  } else if (current_selection == '2'){
    
  }

  // Call the selected EEPROM setting
  switch (current_selection) {
    case '1':
      viewSortedSmartie();
      break;
    case '2':
      viewSortedMMs(); 
      break;
    case '5':
      break;    
  }
}

// A function for viewing the number of sorted Smarties stored in the EEPROM
void viewSortedSmartie() {

  // Create a variable for keeping track of the selected navigational option
  char current_selection = '0';

  // Print the introduction
  Serial.println("Now displaying the number of sorted Smarties stored in the EEPROM:");
  Serial.println();

  // Print the number of sorted Smarties stored in the EEPROM
  Serial.println("   Red:     x");
  Serial.println("   Orange:  x");
  Serial.println("   Yellow:  x");
  Serial.println("   Green:   x");
  Serial.println("   Blue:    x");
  Serial.println("   Mauve:   x");
  Serial.println("   Pink:    x");
  Serial.println("   Brown:   x");
  Serial.println("   Unknown: x");
  Serial.println();

  Serial.println("Please select an option...");
  Serial.println();

  // Print the list of navigational options
  Serial.println("   1. Return to the EEPROM settings menu");
  Serial.println("   2. Return to the main menu");
  Serial.println();

  // Read the selected navigational option
  do {
    current_selection = Serial.read();
  } while ((current_selection != '1') && (current_selection != '2'));

  // Print a divider
  printDivider();

  // Call the selected navigational function
  switch (current_selection) {
    case '1':
      printEEPROMMenu();
      break;
    case '2':
      break;   
  }
}

// A function for viewing the number of sorted M&Ms stored in the EEPROM
void viewSortedMMs() {

  // Create a variable for keeping track of the selected EEPROM option
  char current_selection = '0';

  // Print the introduction
  Serial.println("Now displaying the number of sorted M&M's stored in the EEPROM:");
  Serial.println();

  // Print the number of sorted M&M's stored in the EEPROM
  Serial.println("   Red:     x");
  Serial.println("   Orange:  x");
  Serial.println("   Yellow:  x");
  Serial.println("   Green:   x");
  Serial.println("   Blue:    x");
  Serial.println("   Brown:   x");
  Serial.println("   Unknown: x");
  Serial.println();

  Serial.println("Please select an option...");
  Serial.println();

  // Print the list of navigational options
  Serial.println("   1. Return to the EEPROM settings menu");
  Serial.println("   2. Return to the main menu");
  Serial.println();

  // Read the selected navigational option
  do {
    current_selection = Serial.read();
  } while ((current_selection != '1') && (current_selection != '2'));

  // Print a divider
  printDivider();

  // Call the selected navigational function
  switch (current_selection) {
    case '1':
      printEEPROMMenu();
      break;
    case '2':
      break;   
  }
}

// A function for printing a divider between the different menus
void printDivider() {

  for (int i = 0; i < 72; i++ ) {
    Serial.print("-");
  }

  Serial.println();
  Serial.println();
}
