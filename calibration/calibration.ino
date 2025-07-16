// Project name: Smartie Sorter 3000
// Sketch name:  calibration.ino
// Created by:   Pieter van den Berg
// Created on:   14 July 2025

// Code to calibrate and setup the Smartie Sorter 3000's mini arcade game enclosure

#include <EEPROM.h>
#include <math.h>

// Add the EEPROM addresses for the total number of sorted Smarties
const byte eeAddressTotalNumberOfSortedSmartiesRed     = 0;
const byte eeAddressTotalNumberOfSortedSmartiesOrange  = 2;
const byte eeAddressTotalNumberOfSortedSmartiesYellow  = 4;
const byte eeAddressTotalNumberOfSortedSmartiesGreen   = 6;
const byte eeAddressTotalNumberOfSortedSmartiesBlue    = 8;
const byte eeAddressTotalNumberOfSortedSmartiesMauve   = 10;
const byte eeAddressTotalNumberOfSortedSmartiesPink    = 12;
const byte eeAddressTotalNumberOfSortedSmartiesBrown   = 14;
const byte eeAddressTotalNumberOfSortedSmartiesUnknown = 16;

// Add the EEPROM addresses for the total number of sorted M&M's
const byte eeAddressTotalNumberOfSortedMMsRed     = 18;
const byte eeAddressTotalNumberOfSortedMMsOrange  = 20;
const byte eeAddressTotalNumberOfSortedMMsYellow  = 22;
const byte eeAddressTotalNumberOfSortedMMsGreen   = 24;
const byte eeAddressTotalNumberOfSortedMMsBlue    = 26;
const byte eeAddressTotalNumberOfSortedMMsBrown   = 28;
const byte eeAddressTotalNumberOfSortedMMsUnknown = 30;

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
  Serial.println("   5. Initialise the EEPROM"); 
  Serial.println("   6. Return to the main menu");
  Serial.println();

  // Read the selected EEPROM setting
  do {
    current_selection = Serial.read();
  } while ((current_selection != '1') && (current_selection != '2') && (current_selection != '3') && (current_selection != '4') && (current_selection != '5') && (current_selection != '6'));

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
    case '3':
      confirmResetNumberOfSortedSmarties();
      break;
    case '4':
      confirmResetNumberOfSortedMMs();
      break;
    case '5':
      confirmInitialiseEEPROM();
      break;
    case '6':
      break;    
  }
}

// A function for viewing the number of sorted Smarties stored in the EEPROM
void viewSortedSmartie() {

  // Create a variable for keeping track of the selected navigational option
  char current_selection = '0';

  // Create variables to store the number of sorted Smarties stored in the EEPROM
  unsigned int totalNumberOfSortedSmartiesRed     = 0;
  unsigned int totalNumberOfSortedSmartiesOrange  = 0;
  unsigned int totalNumberOfSortedSmartiesYellow  = 0;
  unsigned int totalNumberOfSortedSmartiesGreen   = 0;
  unsigned int totalNumberOfSortedSmartiesBlue    = 0;
  unsigned int totalNumberOfSortedSmartiesMauve   = 0;
  unsigned int totalNumberOfSortedSmartiesPink    = 0;
  unsigned int totalNumberOfSortedSmartiesBrown   = 0;
  unsigned int totalNumberOfSortedSmartiesUnknown = 0;

  // Print the introduction
  Serial.println("Now displaying the number of sorted Smarties stored in the EEPROM:");
  Serial.println();

  // Print the number of sorted Smarties stored in the EEPROM
  Serial.print("   Red:     "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesRed, totalNumberOfSortedSmartiesRed));
  Serial.print("   Orange:  "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesOrange, totalNumberOfSortedSmartiesOrange));
  Serial.print("   Yellow:  "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesYellow, totalNumberOfSortedSmartiesYellow));
  Serial.print("   Green:   "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesGreen, totalNumberOfSortedSmartiesGreen));
  Serial.print("   Blue:    "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesBlue, totalNumberOfSortedSmartiesBlue));
  Serial.print("   Mauve:   "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesMauve, totalNumberOfSortedSmartiesMauve));
  Serial.print("   Pink:    "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesPink, totalNumberOfSortedSmartiesPink));
  Serial.print("   Brown:   "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesBrown, totalNumberOfSortedSmartiesBrown));
  Serial.print("   Unknown: "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesUnknown, totalNumberOfSortedSmartiesUnknown));
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

  // Create variables to store the number of sorted M&M's stored in the EEPROM
  unsigned int totalNumberOfSortedMMsRed     = 0;
  unsigned int totalNumberOfSortedMMsOrange  = 0;
  unsigned int totalNumberOfSortedMMsYellow  = 0;
  unsigned int totalNumberOfSortedMMsGreen   = 0;
  unsigned int totalNumberOfSortedMMsBlue    = 0;
  unsigned int totalNumberOfSortedMMsBrown   = 0;
  unsigned int totalNumberOfSortedMMsUnknown = 0;

  // Print the introduction
  Serial.println("Now displaying the number of sorted M&M's stored in the EEPROM:");
  Serial.println();

  // Print the number of sorted M&M's stored in the EEPROM
  Serial.print("   Red:     "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedMMsRed, totalNumberOfSortedMMsRed));
  Serial.print("   Orange:  "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedMMsOrange, totalNumberOfSortedMMsOrange));
  Serial.print("   Yellow:  "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedMMsYellow, totalNumberOfSortedMMsYellow));
  Serial.print("   Green:   "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedMMsGreen, totalNumberOfSortedMMsGreen));
  Serial.print("   Blue:    "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedMMsBlue, totalNumberOfSortedMMsBlue));
  Serial.print("   Brown:   "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedMMsBrown, totalNumberOfSortedMMsBrown));
  Serial.print("   Unknown: "); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedMMsUnknown, totalNumberOfSortedMMsUnknown));
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

// A function asking for confirmation before initialising the EEPROM of new Arduino boads
void confirmInitialiseEEPROM() {

  // Create a variable for keeping track of the selected confirmation option
  char current_selection = '0';

  // Print the introduction
  Serial.println("You are about to initialise all of the EEPROM values to zero:");
  Serial.println("Please confirm...");
  Serial.println();

  // Print the list of confirmation options
  Serial.println("   1. Yes");
  Serial.println("   2. No");
  Serial.println();

  // Read the selected confirmation option
  do {
    current_selection = Serial.read();
  } while ((current_selection != '1') && (current_selection != '2'));

  // Take the selected action
  switch (current_selection) {
    case '1':
      // Initialise the EEPROM
      initialiseEEPROM();
      break;
    case '2':
      // Abort the initialisation process
      Serial.println("Initialisation aborted");
      Serial.println();
      break;   
  }

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

// A function for initialising the EEPROM of new Arduino boads
void initialiseEEPROM() {

  Serial.println("Initialising the EEPROM...");
  Serial.println();

  // Initialise the EEPROM
  for (int i = 0; i < EEPROM.length(); i++) {
    EEPROM.write(i,0);

    // Print the progress
    if ( i == round(EEPROM.length() / 10 * 1)) {
      Serial.println("   10%");
    } else if (i == round(EEPROM.length() / 10 * 2)) {
      Serial.println("   20%");
    } else if (i == round(EEPROM.length() / 10 * 3)) {
      Serial.println("   30%");
    } else if (i == round(EEPROM.length() / 10 * 4)) {
      Serial.println("   40%");
    } else if (i == round(EEPROM.length() / 10 * 5)) {
      Serial.println("   50%");
    } else if (i == round(EEPROM.length() / 10 * 6)) {
      Serial.println("   60%");
    } else if (i == round(EEPROM.length() / 10 * 7)) {
      Serial.println("   70%");
    } else if (i == round(EEPROM.length() / 10 * 8)) {
      Serial.println("   80%");
    } else if (i == round(EEPROM.length() / 10 * 9)) {
      Serial.println("   90%");
    }
  }
  Serial.println("   100%");
  Serial.println();

  // Print the completion message
  Serial.println("Initialisation complete");
  Serial.println();
}


// A function asking for confirmation before resetting the number of sorted Smarties stored in the EEPROM
void confirmResetNumberOfSortedSmarties() {

  // Create a variable for keeping track of the selected confirmation option
  char current_selection = '0';

  // Print the introduction
  Serial.println("You are about to reset the number of sorted Smarties:");
  Serial.println("Please confirm...");
  Serial.println();

  // Print the list of confirmation options
  Serial.println("   1. Yes");
  Serial.println("   2. No");
  Serial.println();

  // Read the selected confirmation option
  do {
    current_selection = Serial.read();
  } while ((current_selection != '1') && (current_selection != '2'));

  // Take the selected action
  switch (current_selection) {
    case '1':
      // Reset the number of sorted Smarties
      resetNumberOfSortedSmarties();
      break;
    case '2':
      // Abort the reset process
      Serial.println("Reset aborted");
      Serial.println();
      break;   
  }

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

// A function for resetting the number of sorted Smarties stored in the EEPROM
void resetNumberOfSortedSmarties() {

  // Reset the number of sorted Smarties stored in the EEPROM
  EEPROM.put(eeAddressTotalNumberOfSortedSmartiesRed, 0);
  EEPROM.put(eeAddressTotalNumberOfSortedSmartiesOrange, 0);
  EEPROM.put(eeAddressTotalNumberOfSortedSmartiesYellow, 0);
  EEPROM.put(eeAddressTotalNumberOfSortedSmartiesGreen, 0);
  EEPROM.put(eeAddressTotalNumberOfSortedSmartiesBlue, 0);
  EEPROM.put(eeAddressTotalNumberOfSortedSmartiesMauve, 0);
  EEPROM.put(eeAddressTotalNumberOfSortedSmartiesPink, 0);
  EEPROM.put(eeAddressTotalNumberOfSortedSmartiesBrown, 0);
  EEPROM.put(eeAddressTotalNumberOfSortedSmartiesUnknown, 0);

  // Print the completion message
  Serial.println("Reset complete");
  Serial.println();
}

// A function asking for confirmation before resetting the number of sorted M&M's stored in the EEPROM
void confirmResetNumberOfSortedMMs() {

  // Create a variable for keeping track of the selected confirmation option
  char current_selection = '0';

  // Print the introduction
  Serial.println("You are about to reset the number of sorted M&M's:");
  Serial.println("Please confirm...");
  Serial.println();

  // Print the list of confirmation options
  Serial.println("   1. Yes");
  Serial.println("   2. No");
  Serial.println();

  // Read the selected confirmation option
  do {
    current_selection = Serial.read();
  } while ((current_selection != '1') && (current_selection != '2'));

  // Take the selected action
  switch (current_selection) {
    case '1':
      // Reset the number of sorted M&M's
      resetNumberOfSortedMMs();
      break;
    case '2':
      // Abort the reset process
      Serial.println("Reset aborted");
      Serial.println();
      break;   
  }

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

// A function for resetting the number of sorted M&M's stored in the EEPROM
void resetNumberOfSortedMMs() {

  // Reset the number of sorted M&M's stored in the EEPROM
  EEPROM.put(eeAddressTotalNumberOfSortedMMsRed, 0);
  EEPROM.put(eeAddressTotalNumberOfSortedMMsOrange, 0);
  EEPROM.put(eeAddressTotalNumberOfSortedMMsYellow, 0);
  EEPROM.put(eeAddressTotalNumberOfSortedMMsGreen, 0);
  EEPROM.put(eeAddressTotalNumberOfSortedMMsBlue, 0);
  EEPROM.put(eeAddressTotalNumberOfSortedMMsBrown, 0);
  EEPROM.put(eeAddressTotalNumberOfSortedMMsUnknown, 0);

  // Print the completion message
  Serial.println("Reset complete");
  Serial.println();
}

// A function for printing a divider between the different menus
void printDivider() {

  for (int i = 0; i < 72; i++ ) {
    Serial.print("-");
  }

  Serial.println();
  Serial.println();
}
