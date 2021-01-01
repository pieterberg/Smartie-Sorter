// Arduino Smartie Sorter Project
// Created by Pieter van den Berg
// on 1 January 2021
//
// Based on Skittles Sorter from How to Mechatronics
// https://howtomechatronics.com/projects/arduino-color-sorter-project/


// Colour Sensor's pins
const int colourSensorS0 = 6;
const int colourSensorS1 = 5;
const int colourSensorS2 = 4;
const int colourSensorS3 = 3;
const int colourSensorOut = 2;


void setup() {
  // Set up Colour Sensor's pins
  pinMode(colourSensorS0, OUTPUT);
  pinMode(colourSensorS1, OUTPUT);
  pinMode(colourSensorS2, OUTPUT);
  pinMode(colourSensorS3, OUTPUT);
  pinMode(colourSensorOut, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

}



// Reads the red RGB value of the Smartie
int readRedValue() {

}

// Reads the green RGB value of the Smartie
int readGreenValue() {

}

// Reads the blue RGB value of the Smartie
int readBluevalue() {

}

