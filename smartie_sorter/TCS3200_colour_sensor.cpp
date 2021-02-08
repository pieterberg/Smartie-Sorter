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

// Set up white frequencies for RGB mapping
void TCS3200_colour_sensor::setWhiteFrequencies(int redWhiteFrequency, int greenWhiteFrequency, int blueWhiteFrequency)
{
    _redWhiteFrequency = redWhiteFrequency;
    _greenWhiteFrequency = greenWhiteFrequency;
    _blueWhiteFrequency = blueWhiteFrequency;
}

// Set up black frequencies for RGB mapping
void TCS3200_colour_sensor::setBlackFrequencies(int redBlackFrequency, int greenBlackFrequency, int blueBlackFrequency)
{
    _redBlackFrequency = redBlackFrequency;
    _greenBlackFrequency = greenBlackFrequency;
    _blueBlackFrequency = blueBlackFrequency;
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

// Read the red frequency returned by the TCS3200 colour sensor
int TCS3200_colour_sensor::readRedFrequency()
{
    int redFrequency;

    // Set up the TCS3200 colour sensor's pins to read the red frequency value
    digitalWrite(_colourSensorS2, LOW);
    digitalWrite(_colourSensorS3, LOW);

    // Read the red colour frequency
    redFrequency = pulseIn(_colourSensorOut, LOW);

    // Return the read frequency
    return redFrequency;
}

// Read the green frequency returned by the TCS3200 colour sensor
int TCS3200_colour_sensor::readGreenFrequency()
{
    int greenFrequency;

    // Set up the TCS3200 colour sensor's pins to read the green frequency value
    digitalWrite(_colourSensorS2, HIGH);
    digitalWrite(_colourSensorS3, HIGH);

    // Read the green colour frequency
    greenFrequency = pulseIn(_colourSensorOut, LOW);

    // Return the read frequency
    return greenFrequency;
}

// Read the blue frequency returned by the TCS3200 colour sensor
int TCS3200_colour_sensor::readBlueFrequency()
{
    int blueFrequency;

    // Set up the TCS3200 colour sensor's pins to read the blue frequency value
    digitalWrite(_colourSensorS2, LOW);
    digitalWrite(_colourSensorS3, HIGH);

    // Read the blue colour frequency
    blueFrequency = pulseIn(_colourSensorOut, LOW);

    // Return the read frequency
    return blueFrequency;
}

// Read the red RGB mapping of the colour read by the TCS3200 colour sensor
int TCS3200_colour_sensor::readRedRGB()
{
    int redRGBValue;
    int redFrequency;

    // Read the red frequency returned by the TCS3200 colour sensor
    redFrequency = readRedFrequency();

    // Map the frequency to the corresponding RGB value
    redRGBValue = map(redFrequency, _redWhiteFrequency, _redBlackFrequency, 255, 0);

    // Limit the upper value
    if (redRGBValue > 255)
    {
    redRGBValue = 255;
    }

    // Limit the lower value
    if (redRGBValue < 0)
    {
    redRGBValue = 0;
    }

    // Return the mapped red RGB value
    return redRGBValue;
}

// Read the green RGB mapping of the colour read by the TCS3200 colour sensor
int TCS3200_colour_sensor::readGreenRGB()
{
    int greenRGBValue;
    int greenFrequency;

    // Read the green frequency returned by the TCS3200 colour sensor
    greenFrequency = readGreenFrequency();

    // Map the frequency to the corresponding RGB value
    greenRGBValue = map(greenFrequency, _greenWhiteFrequency, _greenBlackFrequency, 255, 0);

    // Limit the upper value
    if (greenRGBValue > 255)
    {
    greenRGBValue = 255;
    }

    // Limit the lower value
    if (greenRGBValue < 0)
    {
    greenRGBValue = 0;
    }

    // Return the mapped red RGB value
    return greenRGBValue;
}

// Read the blue RGB mapping of the colour read by the TCS3200 colour sensor
int TCS3200_colour_sensor::readBlueRGB()
{
    int blueRGBValue;
    int blueFrequency;

    // Read the blue frequency returned by the TCS3200 colour sensor
    blueFrequency = readBlueFrequency();

    // Map the frequency to the corresponding RGB value
    blueRGBValue = map(blueFrequency, _blueWhiteFrequency, _blueBlackFrequency, 255, 0);

    // Limit the upper value
    if (blueRGBValue > 255)
    {
    blueRGBValue = 255;
    }

    // Limit the lower value
    if (blueRGBValue < 0)
    {
    blueRGBValue = 0;
    }

    // Return the mapped red RGB value
    return blueRGBValue;
}


