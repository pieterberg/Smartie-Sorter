#include <Arduino.h>
#include "TCS3200_colour_sensor.h"

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