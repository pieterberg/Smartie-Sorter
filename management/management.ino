// Project name: Smartie Sorter 3000
// Sketch name:  management.ino
// Created by:   Pieter van den Berg
// Created on:   14 July 2025
//
// An Arduino Sketch for managing the Smartie Sorter 3000
//
// Includes the following features:
//
//    - Perform the servo calibration
//    - Perform the colour sensor calibration
//    - View the number of sorted Smarties and M&M's
//    - Initialise the EEPROM
//

#include <EEPROM.h>
#include <math.h>

// Add the EEPROM addresses for the total number of sorted Smarties
const byte eeAddressTotalNumberOfSortedSmartiesRed     = 2;       // unsigned int (2 bytes)
const byte eeAddressTotalNumberOfSortedSmartiesOrange  = 4;       // unsigned int (2 bytes)
const byte eeAddressTotalNumberOfSortedSmartiesYellow  = 6;       // unsigned int (2 bytes)
const byte eeAddressTotalNumberOfSortedSmartiesGreen   = 8;       // unsigned int (2 bytes)
const byte eeAddressTotalNumberOfSortedSmartiesBlue    = 10;      // unsigned int (2 bytes)
const byte eeAddressTotalNumberOfSortedSmartiesMauve   = 12;      // unsigned int (2 bytes)
const byte eeAddressTotalNumberOfSortedSmartiesPink    = 14;      // unsigned int (2 bytes)
const byte eeAddressTotalNumberOfSortedSmartiesBrown   = 16;      // unsigned int (2 bytes)
const byte eeAddressTotalNumberOfSortedSmartiesUnknown = 18;      // unsigned int (2 bytes)

// Add the EEPROM addresses for the total number of sorted M&M's
const byte eeAddressTotalNumberOfSortedMMsRed     = 20;     // unsigned int (2 bytes)
const byte eeAddressTotalNumberOfSortedMMsOrange  = 22;     // unsigned int (2 bytes)
const byte eeAddressTotalNumberOfSortedMMsYellow  = 24;     // unsigned int (2 bytes)
const byte eeAddressTotalNumberOfSortedMMsGreen   = 26;     // unsigned int (2 bytes)
const byte eeAddressTotalNumberOfSortedMMsBlue    = 28;     // unsigned int (2 bytes)
const byte eeAddressTotalNumberOfSortedMMsBrown   = 30;     // unsigned int (2 bytes)
const byte eeAddressTotalNumberOfSortedMMsUnknown = 32;     // unsigned int (2 bytes)

void setup() {

  // Begin a serial channel
  Serial.begin(9600);

  // Wait until the serial channel is established before printing the welcome message
  while (!Serial) {
    delay(1);
  }

  // Print the welcome message
  Serial.println(F("Welcome to the Smartie Sorter 3000's management utility"));
  Serial.println();

  // Print a divider
  printDivider();

}

void loop() {

  // Print the main menu
  printMainMenu();

}

// A function for printing the main menu
void printMainMenu() {

  // Create a variable for keeping track of the selected option
  char current_selection = '0';

  // Print the introduction
  Serial.println(F("Smartie Sorter 3000 main menu"));
  Serial.println(F("Please select an option..."));
  Serial.println();

  // Print the list of options
  Serial.println(F("   1. Servo calibration"));
  Serial.println(F("   2. Colour sensor calibration"));
  Serial.println(F("   3. Sorting data"));
  Serial.println(F("   4. EEPROM settings"));
  Serial.println();

  // Read the selected option
  do {
    current_selection = Serial.read();
  } while ((current_selection != '1') && (current_selection != '2') && (current_selection != '3') && (current_selection != '4'));

  // Print a divider
  printDivider();

  // Call the selected function
  switch (current_selection) {
    case '3':
      printSortingDataMenu();
      break;
    case '4':
      printEEPROMMenu();
      break;      
  }
}

// A function for printing the sorting data menu
void printSortingDataMenu() {

  // Create a variable for keeping track of the selected sorting data option
  char current_selection = '0';

  // Print the introduction
  Serial.println(F("Sorting data menu"));
  Serial.println(F("Please select an option..."));
  Serial.println();

  // Print the list of sorting data options
  Serial.println(F("   1. View the number of sorted Smarties"));
  Serial.println(F("   2. View the number of sorted M&M's"));
  Serial.println(F("   3. Reset the number of sorted Smarties"));
  Serial.println(F("   4. Reset the number of sorted M&M's"));
  Serial.println(F("   5. Return to the main menu"));
  Serial.println();

  // Read the selected sorting data option
  do {
    current_selection = Serial.read();
  } while ((current_selection != '1') && (current_selection != '2') && (current_selection != '3') && (current_selection != '4') && (current_selection != '5'));

  // Print a divider
  printDivider();

  // Call the selected sorting data option
  switch (current_selection) {
    case '1':
      viewSortedSmarties();
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
      break;  
  }
}

// A function for printing the EEPROM settings menu
void printEEPROMMenu() {

  // Create a variable for keeping track of the selected EEPROM setting
  char current_selection = '0';

  // Print the introduction
  Serial.println(F("EEPROM settings menu"));
  Serial.println(F("Please select an option..."));
  Serial.println();

  // Print the list of EEPROM settings
  Serial.println(F("   1. Initialise the EEPROM")); 
  Serial.println(F("   2. Return to the main menu"));
  Serial.println();

  // Read the selected EEPROM setting
  do {
    current_selection = Serial.read();
  } while ((current_selection != '1') && (current_selection != '2'));

  // Print a divider
  printDivider();

  // Call the selected EEPROM setting
  switch (current_selection) {
    case '1':
      confirmInitialiseEEPROM();
      break;
    case '2':
      break;    
  }
}

// A function for viewing the number of sorted Smarties stored in the EEPROM
void viewSortedSmarties() {

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
  Serial.println(F("Now displaying the number of sorted Smarties stored in the EEPROM:"));
  Serial.println();

  // Print the number of sorted Smarties stored in the EEPROM
  Serial.print(F("   Red:     ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesRed, totalNumberOfSortedSmartiesRed));
  Serial.print(F("   Orange:  ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesOrange, totalNumberOfSortedSmartiesOrange));
  Serial.print(F("   Yellow:  ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesYellow, totalNumberOfSortedSmartiesYellow));
  Serial.print(F("   Green:   ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesGreen, totalNumberOfSortedSmartiesGreen));
  Serial.print(F("   Blue:    ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesBlue, totalNumberOfSortedSmartiesBlue));
  Serial.print(F("   Mauve:   ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesMauve, totalNumberOfSortedSmartiesMauve));
  Serial.print(F("   Pink:    ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesPink, totalNumberOfSortedSmartiesPink));
  Serial.print(F("   Brown:   ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesBrown, totalNumberOfSortedSmartiesBrown));
  Serial.print(F("   Unknown: ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedSmartiesUnknown, totalNumberOfSortedSmartiesUnknown));
  Serial.println();

  Serial.println(F("Please select an option..."));
  Serial.println();

  // Print the list of navigational options
  Serial.println(F("   1. Return to the sorting data menu"));
  Serial.println(F("   2. Return to the main menu"));
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
      printSortingDataMenu();
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
  Serial.println(F("Now displaying the number of sorted M&M's stored in the EEPROM:"));
  Serial.println();

  // Print the number of sorted M&M's stored in the EEPROM
  Serial.print(F("   Red:     ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedMMsRed, totalNumberOfSortedMMsRed));
  Serial.print(F("   Orange:  ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedMMsOrange, totalNumberOfSortedMMsOrange));
  Serial.print(F("   Yellow:  ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedMMsYellow, totalNumberOfSortedMMsYellow));
  Serial.print(F("   Green:   ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedMMsGreen, totalNumberOfSortedMMsGreen));
  Serial.print(F("   Blue:    ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedMMsBlue, totalNumberOfSortedMMsBlue));
  Serial.print(F("   Brown:   ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedMMsBrown, totalNumberOfSortedMMsBrown));
  Serial.print(F("   Unknown: ")); Serial.println(EEPROM.get(eeAddressTotalNumberOfSortedMMsUnknown, totalNumberOfSortedMMsUnknown));
  Serial.println();

  Serial.println(F("Please select an option..."));
  Serial.println();

  // Print the list of navigational options
  Serial.println(F("   1. Return to the sorting data menu"));
  Serial.println(F("   2. Return to the main menu"));
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
      printSortingDataMenu();
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
  Serial.println(F("You are about to initialise all of the EEPROM values to zero"));
  Serial.println();
  Serial.println(F("This will reset the:"));
  Serial.println();
  Serial.println(F("   - Operating modes"));
  Serial.println(F("   - Number of sorted Smarties"));
  Serial.println(F("   - Number of sorted M&M's"));
  Serial.println();
  Serial.println(F("Please confirm..."));
  Serial.println();

  // Print the list of confirmation options
  Serial.println(F("   1. Yes"));
  Serial.println(F("   2. No"));
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
      Serial.println(F("Initialisation aborted"));
      Serial.println();
      break;   
  }

  Serial.println(F("Please select an option..."));
  Serial.println();

  // Print the list of navigational options
  Serial.println(F("   1. Return to the EEPROM settings menu"));
  Serial.println(F("   2. Return to the main menu"));
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

  Serial.println(F("Initialising the EEPROM..."));
  Serial.println();

  // Initialise the EEPROM
  for (int i = 0; i < EEPROM.length(); i++) {
    EEPROM.write(i,0);

    // Print the progress
    if ( i == round(EEPROM.length() / 10 * 1)) {
      Serial.println(F("   10%"));
    } else if (i == round(EEPROM.length() / 10 * 2)) {
      Serial.println(F("   20%"));
    } else if (i == round(EEPROM.length() / 10 * 3)) {
      Serial.println(F("   30%"));
    } else if (i == round(EEPROM.length() / 10 * 4)) {
      Serial.println(F("   40%"));
    } else if (i == round(EEPROM.length() / 10 * 5)) {
      Serial.println(F("   50%"));
    } else if (i == round(EEPROM.length() / 10 * 6)) {
      Serial.println(F("   60%"));
    } else if (i == round(EEPROM.length() / 10 * 7)) {
      Serial.println(F("   70%"));
    } else if (i == round(EEPROM.length() / 10 * 8)) {
      Serial.println(F("   80%"));
    } else if (i == round(EEPROM.length() / 10 * 9)) {
      Serial.println(F("   90%"));
    }
  }
  Serial.println(F("   100%"));
  Serial.println();

  // Print the completion message
  Serial.println(F("Initialisation complete"));
  Serial.println();
}


// A function asking for confirmation before resetting the number of sorted Smarties stored in the EEPROM
void confirmResetNumberOfSortedSmarties() {

  // Create a variable for keeping track of the selected confirmation option
  char current_selection = '0';

  // Print the introduction
  Serial.println(F("You are about to reset the number of sorted Smarties:"));
  Serial.println(F("Please confirm..."));
  Serial.println();

  // Print the list of confirmation options
  Serial.println(F("   1. Yes"));
  Serial.println(F("   2. No"));
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
      Serial.println(F("Reset aborted"));
      Serial.println();
      break;   
  }

  Serial.println(F("Please select an option..."));
  Serial.println();

  // Print the list of navigational options
  Serial.println(F("   1. Return to the sorting data menu"));
  Serial.println(F("   2. Return to the main menu"));
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
      printSortingDataMenu();
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
  Serial.println(F("Reset complete"));
  Serial.println();
}

// A function asking for confirmation before resetting the number of sorted M&M's stored in the EEPROM
void confirmResetNumberOfSortedMMs() {

  // Create a variable for keeping track of the selected confirmation option
  char current_selection = '0';

  // Print the introduction
  Serial.println(F("You are about to reset the number of sorted M&M's:"));
  Serial.println(F("Please confirm..."));
  Serial.println();

  // Print the list of confirmation options
  Serial.println(F("   1. Yes"));
  Serial.println(F("   2. No"));
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
      Serial.println(F("Reset aborted"));
      Serial.println();
      break;   
  }

  Serial.println(F("Please select an option..."));
  Serial.println();

  // Print the list of navigational options
  Serial.println(F("   1. Return to the sorting data menu"));
  Serial.println(F("   2. Return to the main menu"));
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
      printSortingDataMenu();
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
  Serial.println(F("Reset complete"));
  Serial.println();
}

// A function for printing a divider between the different menus
void printDivider() {

  for (int i = 0; i < 72; i++ ) {
    Serial.print(F("-"));
  }

  Serial.println();
  Serial.println();
}
