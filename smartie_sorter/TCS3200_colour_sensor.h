#pragma once

#include <Arduino.h>

// Library for the TCS3200 colour sensor component
class TCS3200_colour_sensor
{
    public:
        // Constructor
        TCS3200_colour_sensor(int S0, int S1, int S2, int S3, int LED, int OUT);

        // Set frequency scaling for the colour sorter
        void setFrequencyScalingToZero();
        void setFrequencyScalingTo2Percent();
        void setFrequencyScalingTo20Percent();
        void setFrequencyScalingTo100Percent();

        // Functions to read the frequency returned by the colour sensor
        int readRedFrequency();
        int readGreenFrequency();
        int readBlueFrequency();

        // Functions to read the RGB mapping of the colour read by the colour sensor
        int readRedRGB();
        int readGreenRGB();
        int readBlueRGB();

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