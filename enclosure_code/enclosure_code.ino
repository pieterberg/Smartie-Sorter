// Project name: Smartie Sorter 3000
// Sketch name:  enclosure_code.ino
// Created by:   Pieter van den Berg
// Created on:   28 February 2024

// Code to control the Smartie Sorter 3000's mini arcade game enclosure

#include <EEPROM.h>

// Add the EEPROM addresses for the operating modes
const byte eeAddressChocolateMode = 0;      // enum (1 byte)
const byte eeAddressSortingMode   = 1;      // enum (1 byte)

// Create enums to track the states of the three operating properties
enum SORTING_STATE {
  SORTING,
  NOT_SORTING
};

enum CHOCOLATE_MODE {
  SMARTIES,
  M_AND_M_S
};

enum SORTING_MODE {
  UNCOLLATED,
  COLLATED
};

// Set the default values of the three operating properties
SORTING_STATE sorting_state   = NOT_SORTING;
CHOCOLATE_MODE chocolate_mode = SMARTIES;
SORTING_MODE sorting_mode     = UNCOLLATED;

// Create a bool to keep track of the combinations mode
bool isCombinationsMode = false;

// Create a numeric counter for keeping track of the button presses during combinations mode
int combinationsScore = 0;

// Assign the pin numbers
const int LEDTransistor = 2;
const int button1       = 3;  // The blue arcade game button
const int button2       = 4;  // The left white arcade game button
const int button3       = 5;  // The right white arcade game button

// Create a variable to control the length of the LED flashes
const int LEDFlashingDelay = 200; // [ms]

// Create the variables to keep track of the blue arcade game button's state
int button1Reading       = 0;
int button1StateCurrent  = 0;
int button1StatePrevious = 0;

// Create the variables to keep track of the left white arcade game button's state
int button2Reading       = 0;
int button2StateCurrent  = 0;
int button2StatePrevious = 0;

// Create the variables to keep track of the right white arcade game button's state
int button3Reading       = 0;
int button3StateCurrent  = 0;
int button3StatePrevious = 0;

// Use a debounce delay of 50 ms
unsigned long debounceDelay = 50;  // [ms]

// Create the variables to keep track of the arcade game buttons' last debounce times
unsigned long button1LastDebounceTime = 0;  // [ms]
unsigned long button2LastDebounceTime = 0;  // [ms]
unsigned long button3LastDebounceTime = 0;  // [ms]

void setup() {
  // Setup the transistor pins
  pinMode(LEDTransistor, OUTPUT);

  // Setup the button pins
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  // Start the LED lights
  digitalWrite(LEDTransistor, HIGH);

  // Read the operating modes from the EEPROM
  chocolate_mode = (CHOCOLATE_MODE)EEPROM.read(eeAddressChocolateMode);
  sorting_mode   = (SORTING_MODE)EEPROM.read(eeAddressSortingMode);

  // Begin a serial channel
  Serial.begin(9600);
}

void loop() {
  // Scan for any button presses
  readButtonPresses();

  // Run the sorting procedure when the SORTING_STATE property is set to SORTING
  if (sorting_state == SORTING){


  }
}

// A grouping function for determining whether the arcade game buttons have been pressed
void readButtonPresses(){
  // Determine whether the blue arcade game button has been pressed
  readButton1();
  // Determine whether the left white arcade game button has been pressed
  readButton2();
  // Determine whether the right white arcade game button has been pressed
  readButton3();
}

// A function for determining whether the blue arcade game button has been pressed
void readButton1() {

  // Read the current state of the blue arcade game button
  button1Reading = digitalRead(button1);
 
  // Reset the debounce timer of the blue arcade game button
  if (button1Reading != button1StatePrevious) {
    button1LastDebounceTime = millis();
  }

  // Determine whether the blue arcade game button has been pressed
  if ((millis() - button1LastDebounceTime) > debounceDelay) {
    if (button1Reading != button1StateCurrent) {
      // Update the current state of the blue arcade game button
      button1StateCurrent = button1Reading;
      // Call the button1Pressed() function when the blue arcade game button has been pressed
      if (button1StateCurrent == 1) {
        button1Pressed();
      }
    }
  }

  // Capture the previous state of the blue arcade game button
  button1StatePrevious = button1Reading;
}

// A function for determining whether the left white arcade game button has been pressed
void readButton2() {

  // Read the current state of the left white arcade game button
  button2Reading = digitalRead(button2);
 
  // Reset the debounce timer of the left white arcade game button
  if (button2Reading != button2StatePrevious) {
    button2LastDebounceTime = millis();
  }

  // Determine whether the left white arcade game button has been pressed
  if ((millis() - button2LastDebounceTime) > debounceDelay) {
    if (button2Reading != button2StateCurrent) {
      // Update the current state of the left white arcade game button
      button2StateCurrent = button2Reading;
      // Call the button2Pressed() function when the left white arcade game button has been pressed
      if (button2StateCurrent == 1) {
        button2Pressed();
      }
    }
  }

  // Capture the previous state of the left white arcade game button
  button2StatePrevious = button2Reading;
}

// A function for determining whether the right white arcade game button has been pressed
void readButton3() {

  // Read the current state of the right white arcade game button
  button3Reading = digitalRead(button3);
 
  // Reset the debounce timer of the right white arcade game button
  if (button3Reading != button3StatePrevious) {
    button3LastDebounceTime = millis();
  }

  // Determine whether the right white arcade game button has been pressed
  if ((millis() - button3LastDebounceTime) > debounceDelay) {
    if (button3Reading != button3StateCurrent) {
      // Update the current state of the right white arcade game button
      button3StateCurrent = button3Reading;
      // Call the button3Pressed() function when the right white arcade game button has been pressed
      if (button3StateCurrent == 1) {
        button3Pressed();
      }
    }
  }

  // Capture the previous state of the right white arcade game button
  button3StatePrevious = button3Reading;
}

// Code to run when the blue arcade game button is pressed
void button1Pressed() {

  // Use a switch statement to control the logic for the combinations and normal operating modes
  switch(isCombinationsMode) {
    case false: 
      if (sorting_state == NOT_SORTING) {
        isCombinationsMode = true;
        // Flash the built-in LEDs 3 times to indicate that the Smartie Sorter 3000 has now entered the combinations mode
        flashLEDs(3); 
      }               
      break;
      
    case true:
      isCombinationsMode = false;
      // Evaluate the entered combination
      evaluateCombinations();
      break;
    }   
}

// Code to run when the left white arcade game button is pressed
void button2Pressed() {

  switch(isCombinationsMode) {
    case false: 
      if (sorting_state == NOT_SORTING) {
        sorting_state = SORTING;
        // Flash the built-in LEDs 1 time to indicate that the SORTING_STATE has now been set to SORTING
        flashLEDs(1);
      }                    
      break;
      
    case true:
      // Increase the value of the numeric counter used to keep track of the button presses for entering the combinations
      combinationsScore = combinationsScore + 1;    
      break;
    }
}

// Code to run when the right white arcade game button is pressed
void button3Pressed() {

  switch(isCombinationsMode) {
    case false: 
      if (sorting_state == SORTING) {
        sorting_state = NOT_SORTING;
        // Flash the built-in LEDs 2 times to indicate that the SORTING_STATE has now been set to NOT_SORTING
        flashLEDs(2);
      }       
      break;
      
    case true:
      // Increase the value of the numeric counter used to keep track of the button presses for entering the combinations
      combinationsScore = combinationsScore + 10;    
      break;
    }
}

// A function for determining which combination was entered based on the final value of the numeric counter used to keep track of the button presses
void evaluateCombinations() {

  // Evaluate the entered combination based on the final value of the numeric counter
  switch(combinationsScore) {
    case 1:
      if (chocolate_mode == SMARTIES) {
        // Flash the built-in LEDs 4 times to indicate that the CHOCOLATE_MODE state is currently set to SMARTIES
        flashLEDs(4);
      }
      if (chocolate_mode == M_AND_M_S) {
        // Flash the built-in LEDs 5 times to indicate that the CHOCOLATE_MODE state is currently set to M_AND_M_S
        flashLEDs(5);
      }
      break;
    
    case 10:
      if (sorting_mode == UNCOLLATED){
        // Flash the built-in LEDs 6 times to indicate that the SORTING_MODE state is currently set to UNCOLLATED
        flashLEDs(6);
      }
      if (sorting_mode == COLLATED) {
        // Flash the built-in LEDs 7 times to indicate that the SORTING_MODE state is currently set to COLLATED
        flashLEDs(7);
      }
      break;

    case 25:
      chocolate_mode = SMARTIES;
      EEPROM.write(eeAddressChocolateMode, chocolate_mode);
      // Flash the built-in LEDs 4 times to indicate that the CHOCOLATE_MODE state has now been set to SMARTIES
      flashLEDs(4);
      break;

    case 34:
      chocolate_mode = M_AND_M_S;
      EEPROM.write(eeAddressChocolateMode, chocolate_mode);
      // Flash the built-in LEDs 5 times to indicate that the CHOCOLATE_MODE state has now been set to M_AND_M_S
      flashLEDs(5);
      break;

    case 52:
      sorting_mode = UNCOLLATED;
      EEPROM.write(eeAddressSortingMode, sorting_mode);
      // Flash the built-in LEDs 6 times to indicate that the SORTING_MODE state has now been set to UNCOLLATED
      flashLEDs(6);
      break;

    case 43:
      sorting_mode = COLLATED;
      EEPROM.write(eeAddressSortingMode, sorting_mode);
      // Flash the built-in LEDs 7 times to indicate that the SORTING_MODE state has now been set to COLLATED
      flashLEDs(7);
      break;
  }

  // Reset the score counter back to zero
  combinationsScore = 0;
}

// A function for flashing the built-in LEDs a certain number of times corresponding to the mode number of the selected operating state
void flashLEDs(int modeNumber) {

  // Flash the built-in LEDs a certain number of times corresponding to the mode number of the selected operating state
  for (int i = 0; i <= (modeNumber - 1); i++){
    digitalWrite(LEDTransistor, LOW);
    delay (LEDFlashingDelay);
    digitalWrite(LEDTransistor, HIGH);
    delay (LEDFlashingDelay);
  }
      
  // Turn the built-in LEDs back on
  digitalWrite(LEDTransistor, HIGH); 
}



