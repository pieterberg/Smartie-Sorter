// Arduino Smartie Sorter 3000
// Created by Pieter van den Berg
// on 28 February 2024

// Code to control the Smartie Sorter 3000's mini arcade game enclosure

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
int button1State         = 0;
int button1StatePrevious = 0;

// Create the variables to keep track of the left white arcade game button's state
int button2State         = 0;
int button2StatePrevious = 0;

// Create the variables to keep track of the right white arcade game button's state
int button3State         = 0;
int button3StatePrevious = 0;

void setup() {
  // Setup the transistor pins
  pinMode(LEDTransistor, OUTPUT);

  // Setup the button pins
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  // Start the LED lights
  digitalWrite(LEDTransistor, HIGH);

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


void readButtonPresses(){

  // Read button 1's state
  button1State = digitalRead(button1);

  // Flash the LEDs if button 1 is pressed
  if ((button1State == 1) && (button1StatePrevious == 0)) {

    button1Pressed();

  }

  // Read button 2's state
  button2State = digitalRead(button2);

  // Print when button 2 is pressed
  if ((button2State == 1) && (button2StatePrevious == 0)) {

    button2Pressed();

  }

  // Read button 3's state
  button3State = digitalRead(button3);


  // Print when button 3 is pressed
  if ((button3State == 1) && (button3StatePrevious == 0)) {

    button3Pressed();
  

  }

  // Capture the previous button states
  button1StatePrevious = button1State;
  button2StatePrevious = button2State;
  button3StatePrevious = button3State;

}


// Code to run when the blue arcade game button is pressed
void button1Pressed() {

  // Print a message to the serial monitor to confirm that button 1 has been pressed
  Serial.println("Button 1 pressed");

  // Use a switch statement to control the logic for the combinations and normal operating modes
  switch(isCombinationsMode) {
    case false: 
      if (sorting_state == NOT_SORTING) {
        isCombinationsMode = true;
        Serial.println("Enter combinations mode");
        // Flash the built-in LEDs 3 times to indicate that the Smartie Sorter 3000 has now entered the combinations mode
        flashLEDs(3); 
      }               
      break;
      
    case true:
      isCombinationsMode = false;
      // Evaluate the entered combination
      evaluateCombinations();
      Serial.println("Exit combinations mode");     
      break;
    }   
}

// Code to run when the left white arcade game button is pressed
void button2Pressed() {

  // Print a message to the serial monitor to confirm that button 2 has been pressed
  Serial.println("Button 2 pressed");

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

  // Print a message to the serial monitor to confirm that button 3 has been pressed
  Serial.println("Button 3 pressed");

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
      // Flash the built-in LEDs 4 times to indicate that the CHOCOLATE_MODE state has now been set to SMARTIES
      flashLEDs(4);
      break;

    case 34:
      chocolate_mode = M_AND_M_S;
      // Flash the built-in LEDs 5 times to indicate that the CHOCOLATE_MODE state has now been set to M_AND_M_S
      flashLEDs(5);
      break;

    case 52:
      sorting_mode = UNCOLLATED;
      // Flash the built-in LEDs 6 times to indicate that the SORTING_MODE state has now been set to UNCOLLATED
      flashLEDs(6);
      break;

    case 43:
      sorting_mode = COLLATED;
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



