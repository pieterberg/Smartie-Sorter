// Arduino Smartie Sorter 3000
// Created by Pieter van den Berg
// on 28 February 2024

// Create the variables for the different pins
const int LEDTransistor = 2;
const int button1       = 3;
const int button2       = 4;
const int button3       = 5;

// Create a bool to control the lighting state
bool isFlashing = false;

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

  // Setup the Arduino Nano's pins
  pinMode(LEDTransistor, OUTPUT);

  // Setup the button pins
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  // Begin a serial channel
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Read button 1's state
  button1State = digitalRead(button1);

  if ((button1State == 1) && (button1StatePrevious == 0)) {

    Serial.println("Button 1 pressed");
  }

  // Read button 2's state
  button2State = digitalRead(button2);

  if ((button2State == 1) && (button2StatePrevious == 0)) {

    Serial.println("Button 2 pressed");
  }

  // Read button 3's state
  button3State = digitalRead(button3);

  if ((button3State == 1) && (button3StatePrevious == 0)) {

    Serial.println("Button 3 pressed");
  }

  // Capture the previous button states
  button1StatePrevious = button1State;
  button2StatePrevious = button2State;
  button3StatePrevious = button3State;

  delay(200);
}


