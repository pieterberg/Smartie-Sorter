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

}
