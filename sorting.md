# Sorting

### Table of Contents

## 1. Sorting Procedure

## 2. Process States

There are three different properties that control the sorting behaviour of the Smartie Sorter 3000, namely:

- `SORTING_STATE`
- `CHOCOLATE_MODE`
- `SORTING_MODE`

Each of these properties have two different possible states that the Smartie Sorter 3000 can be in at any given time. Section 2.1 provides more information about the different states while Section 2.2 provides the default values for each property.

### 2.1. Enumerated Values

### 2.2. Default States

The default values when powering on the Smartie Sorter 3000 are given by Table 1.

Table 1: Default values

| Property         | Default State |
|------------------|---------------|
| `SORTING_STATE`  | NOT_SORTING   |
| `CHOCOLATE_MODE` | SMARTIES      |
| `SORTING_MODE`   | UNCOLLATED    |

## 3. Codes

The Smartie Sorter 3000 can operate in 4 different modes.

The different modes are selected by entering different codes using the arcade game buttons. Section 3.1 outlines the procedure for entering a code and Section 3.2 provides the codes for the different operating modes.

### 3.1. Procedure

The procedure to enter a code is as follows:

1. Press the blue arcade game button
2. Enter a combination of white button presses
3. Press the blue arcade game button again

The Smartie Sorter 3000 will enter the selected mode if a valid combination of white button presses was entered. The built-in LEDs will flash a certain number of times, corresponding to the mode number, to confirm that the code has been accepted.

### 3.2. Combinations

Table 2 provides the combinations for selecting the different operating modes.

For the combinations, `L` refers to a press of the left white arcade game button and `R` refers to a press of the right white arcade game button.

A numerical system is used to keep track of the button presses. Presses of the left white arcade game button (`L`) count +1 point while presses of the right white arcade game button (`R`) count +10 points. The selected operating mode is then entered based on the total points score.

Table 2: Combinations for entering the different operating modes

| Mode number | Combination     | Numeric Value | Description                       |
|:-----------:|-----------------|:-------------:|-----------------------------------|
|      -      | `L`             |       1       | Display the active chocolate mode |
|      -      | `R`             |       10      | Display the active sorting mode   |
|      1      | `L L R L L R L` |       25      | Enter the Smartie chocolate mode  |
|      2      | `L R L L R L R` |       34      | Enter the M&M chocolate mode      |
|      3      | `R L R R R L R` |       52      | Enter the uncollated sorting mode |
|      4      | `R R L R L L R` |       43      | Enter the collated sorting mode   |

