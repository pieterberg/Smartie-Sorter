// Library for the TCS3200 colour sensor
// Created by Pieter Leon van den Berg
// on 8 February 2021

#pragma once

#include <Arduino.h>

// Library for the TCS3200 colour sensor component
class TCS3200_colour_sensor
{
    public:
        // Constructor
        TCS3200_colour_sensor(int S0, int S1, int S2, int S3, int LED, int OUT);

        // Set up frequencies for RGB mapping
        void setWhiteFrequencies(int redWhiteFrequency, int greenWhiteFrequency, int blueWhiteFrequency);
        void setBlackFrequencies(int redBlackFrequency, int greenblackFrequency, int blueblackFrequency);

        // Set frequency scaling for the TCS3200 colour sensor
        void setFrequencyScalingToZero();
        void setFrequencyScalingTo2Percent();
        void setFrequencyScalingTo20Percent();
        void setFrequencyScalingTo100Percent();

        // Turn the TCS3200 colour sensor's LEDs on or off
        void turnOnLEDs();
        void turnOffLEDs();

        // Functions to read the frequency returned by the TCS3200 colour sensor
        int readRedFrequency();
        int readGreenFrequency();
        int readBlueFrequency();

        // Functions to read the RGB mapping of the colour read by the TCS3200 colour sensor
        int readRedRGB();
        int readGreenRGB();
        int readBlueRGB();

    private:
        // TCS3200 colour sensor's pins
        int _colourSensorS0;
        int _colourSensorS1;
        int _colourSensorS2;
        int _colourSensorS3;
        int _colourSensorLED;
        int _colourSensorOut;

        // Calibrated frequencies for white and black
        int _redWhiteFrequency;
        int _greenWhiteFrequency;
        int _blueWhiteFrequency;

        int _redBlackFrequency;
        int _greenBlackFrequency;
        int _blueBlackFrequency;
};