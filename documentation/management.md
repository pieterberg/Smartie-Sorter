# Management

### Table of Contents

- [1. Setup and Calibration](#1-setup-and-calibration)
  - [1.1. EEPROM Initialisation](#11-eeprom-initialisation)
  - [1.2. Smartie Arm Calibration](#12-smartie-arm-calibration)
  - [1.3. Colour Sensor Calibration](#13-colour-sensor-calibration)
- [2. EEPROM Addresses](#2-eeprom-addresses)

## 1. Setup and Calibration

### 1.1. EEPROM Initialisation

### 1.2. Smartie Arm Calibration

### 1.3. Colour Sensor Calibration

## 2. EEPROM Addresses

Table 1: EEPROM addresses

| EEPROM Address | Variable Name                    | Data Type  | Size (bytes) |
|:--------------:|----------------------------------|------------|:------------:|
|       `0`      | Chocolate mode                   | `uint8_t`  |       1      |
|       `1`      | Sorting mode                     | `uint8_t`  |       1      |
|       `2`      | Number of sorted red Smarties    | `uint16_t` |       2      |
|       `4`      | Number of sorted orange Smarties | `uint16_t` |       2      |
|       `6`      | Number of sorted yellow Smarties | `uint16_t` |       2      |
|       `8`      | Number of sorted green Smarties  | `uint16_t` |       2      |
|      `10`      | Number of sorted blue Smarties   | `uint16_t` |       2      |
|      `12`      | Number of sorted mauve Smarties  | `uint16_t` |       2      |
|      `14`      | Number of sorted pink Smarties   | `uint16_t` |       2      |
|      `16`      | Number of sorted brown Smarties  | `uint16_t` |       2      |
|      `18`      | Number of unknown Smarties       | `uint16_t` |       2      |
|      `20`      | Number of sorted red M&M's       | `uint16_t` |       2      |
|      `22`      | Number of sorted orange M&M's    | `uint16_t` |       2      |
|      `24`      | Number of sorted yellow M&M's    | `uint16_t` |       2      |
|      `26`      | Number of sorted green M&M's     | `uint16_t` |       2      |
|      `28`      | Number of sorted blue M&M's      | `uint16_t` |       2      |
|      `30`      | Number of sorted brown M&M's     | `uint16_t` |       2      |
|      `32`      | Number of unknown M&M's          | `uint16_t` |       2      |


