// Project name: Smartie Sorter 3000
// Sketch name:  calibration.ino
// Created by:   Pieter van den Berg
// Created on:   14 July 2025

// Code to calibrate and setup the Smartie Sorter 3000's mini arcade game enclosure

void setup() {
  // Begin a serial channel
  Serial.begin(9600);

  // Print a welcome message
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

}

// A function for printing a divider between the different menus
void printDivider() {

  for (int i = 0; i < 72; i++ ) {
    Serial.print("-");
  }

  Serial.println();
  Serial.println();
}
