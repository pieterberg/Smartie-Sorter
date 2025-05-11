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

// Assign the pin numbers
const int LEDTransistor = 2;
const int button1       = 3;
const int button2       = 4;
const int button3       = 5;

// Create variables to control the lighting state
bool isFlashing      = false;
int  transistorState = 1;

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
  // Read button 1's state
  button1State = digitalRead(button1);

  // Flash the LEDs if button 1 is pressed
  if ((button1State == 1) && (button1StatePrevious == 0)) {
    Serial.println("Button 1 pressed");
    if (isFlashing == true)
    {
      isFlashing = false;
    }else{
      isFlashing = true;
    }
  }

  // Read button 2's state
  button2State = digitalRead(button2);

  // Print when button 2 is pressed
  if ((button2State == 1) && (button2StatePrevious == 0)) {
    Serial.println("Button 2 pressed");
  }

  // Read button 3's state
  button3State = digitalRead(button3);

  // Print when button 3 is pressed
  if ((button3State == 1) && (button3StatePrevious == 0)) {
    Serial.println("Button 3 pressed");
  }

  if (isFlashing == true) {
    if(transistorState == 1){
      digitalWrite(LEDTransistor, LOW);
      transistorState = 0;
    } else {
      digitalWrite(LEDTransistor, HIGH);
      transistorState = 1;
    }
  } else {
    digitalWrite(LEDTransistor, HIGH);  
  }

  // Capture the previous button states
  button1StatePrevious = button1State;
  button2StatePrevious = button2State;
  button3StatePrevious = button3State;

  // Flash the lights every 300 ms
  delay(300);

}


