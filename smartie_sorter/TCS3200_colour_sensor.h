#pragma once

#include <Arduino.h>

class TCS3200_colour_sensor
{
    public:
        TCS3200_colour_sensor();



    private:
        // Colour Sensor's pins
        int _colourSensorS0;
        int _colourSensorS1;
        int _colourSensorS2;
        int _colourSensorS3;
        int _colourSensorLED;
        int _colourSensorOut;

        // Calibrated frequencies for white and black
        // Use the calibration function to determine these values
        int _redWhiteFrequency;
        int _greenWhiteFrequency;
        int _blueWhiteFrequency;

        int _redBlackFrequency;
        int _greenBlackFrequency;
        int _blueBlackFrequency;
};