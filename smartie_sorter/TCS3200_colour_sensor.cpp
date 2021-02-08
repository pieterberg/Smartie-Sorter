#include <Arduino.h>
#include "TCS3200_colour_sensor.h"

// TCS3200_colour_sensor class' contructor
TCS3200_colour_sensor::TCS3200_colour_sensor(int S0, int S1, int S2, int S3, int LED, int OUT)
{
    // Set up the pin values
    _colourSensorS0 = S0;
    _colourSensorS1 = S1;
    _colourSensorS2 = S2;
    _colourSensorS3 = S3;
    _colourSensorLED = LED;
    _colourSensorOut = OUT;   

    // Set up Colour Sensor's pins
    pinMode(_colourSensorS0, OUTPUT);
    pinMode(_colourSensorS1, OUTPUT);
    pinMode(_colourSensorS2, OUTPUT);
    pinMode(_colourSensorS3, OUTPUT);
    pinMode(_colourSensorLED, OUTPUT);
    pinMode(_colourSensorOut, INPUT);
}

// Turn the TCS3200 colour sensor's LEDs on
void TCS3200_colour_sensor::turnOnLEDs()
{
    digitalWrite(_colourSensorLED, HIGH);
}

// Turn the TCS3200 colour sensor's LEDs off
void TCS3200_colour_sensor::turnOffLEDs()
{
    digitalWrite(_colourSensorLED, LOW);
}


// Set scaling frequency of TCS3200 colour sensor to 0%
void TCS3200_colour_sensor::setFrequencyScalingToZero()
{
    digitalWrite(_colourSensorS0, LOW);
    digitalWrite(_colourSensorS1, LOW);
}

// Set scaling frequency of TCS3200 colour sensor to 2%
void TCS3200_colour_sensor::setFrequencyScalingTo2Percent()
{   
    digitalWrite(_colourSensorS0, LOW);
    digitalWrite(_colourSensorS1, HIGH);
}

// Set scaling frequency of TCS3200 colour sensor to 20%
void TCS3200_colour_sensor::setFrequencyScalingTo20Percent()
{
    digitalWrite(_colourSensorS0, HIGH);
    digitalWrite(_colourSensorS1, LOW);   
}

// Set scaling frequency of TCS3200 colour sensor to 100%
void TCS3200_colour_sensor::setFrequencyScalingTo100Percent()
{
    digitalWrite(_colourSensorS0, HIGH);
    digitalWrite(_colourSensorS1, HIGH);     
}