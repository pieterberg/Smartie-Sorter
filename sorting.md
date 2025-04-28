# Sorting

### Table of Contents

- [1. Sorting Procedure](#1-sorting-procedure)
- [2. Operating Modes](#2-operating-modes)
  - [2.1. Enumerated Values](#21-enumerated-values)
  - [2.2. Default Values](#22-default-values)
- [3. Control](#3-control)
  - [3.1. Buttons](#31-buttons)
  - [3.2. Combinations Mode](#32-combinations-mode)
  - [3.3. Combinations](#33-combinations)

## 1. Sorting Procedure

## 2. Operating Modes

There are three different operating properties that control the sorting behaviour of the Smartie Sorter 3000, namely:

- `SORTING_STATE`
- `CHOCOLATE_MODE`
- `SORTING_MODE`

Each of these properties have two different possible values that they can have at any given time. Section 2.1 provides more information about the different values that the operating properties can have while Section 2.2 provides the default values for each operating property.

### 2.1. Enumerated Values

The values of the three operating properties are tracked using enums. The Smartie Sorter 3000 must have a value for each property at any given time.

The `SORTING_STATE` property controls whether the Smartie Sorter 3000 is currently performing the sorting procedure that was outlined in Section 1. The two possible enumerated values are:

- SORTING
- NOT_SORTING

The `CHOCOLATE_MODE` property allows the Smartie Sorter 3000 to switch between sorting Smarties and sorting M&M's. The two possible enumerated values are:

- SMARTIES
- M_AND_M_S

The `SORTING_MODE` property allows the Smartie Sorter 3000 to switch between grouping the same-coloured Smarties and M&M's together (uncollated) and grouping the Smarties and M&M's in such a way that consecutive chocolates of the same colour end up in consecutive compartments (collated). The two possible enumerated values are:

- UNCOLLATED 
- COLLATED

### 2.2. Default Values

The default values of the three operating property are given by Table 1. These values have been hard-coded into the Arduino sketch and represent the values that the operating properties will have when powering on the Smartie Sorter 3000.

Table 1: The default values of the operating properties

| Property         | Default Value |
|------------------|---------------|
| `SORTING_STATE`  | NOT_SORTING   |
| `CHOCOLATE_MODE` | SMARTIES      |
| `SORTING_MODE`   | UNCOLLATED    |

## 3. Control

Control of the Smartie Sorter 3000 is achieved through the use of arcade game buttons to set the values of the three operating properties that were defined in Section 2.

### 3.1. Buttons

The Smartie Sorter 3000 uses three Sanwa arcade game buttons to control the sorting process. As mentioned in [design.md](https://github.com/pieterberg/Smartie-Sorter/blob/main/documentation/design.md), the arcade game buttons consist of one light-blue arcade game button and two white arcade game buttons. Table 2 provides the normal behaviour of the arcade game buttons.

Table 2: The normal behaviour of the arcade game buttons

| Mode Number    | Button                         | Symbol | Action                                                                                                      |
|:--------------:|--------------------------------|:------:|-------------------------------------------------------------------------------------------------------------|
| -              | Blue arcade game button        | `B`    | Enters the "combination" mode for setting the values of the `CHOCOLATE_MODE` and `SORTING_MODE` properties. |
| 1              | Left white arcade game button  | `L`    | Starts the sorting procedure by setting the value of the `SORTING_STATE` property to SORTING.               |
| 2              | Right white arcade game button | `R`    | Stops the sorting procedure by setting the value of the `SORTING_STATE` property to NOT_SORTING.            |

The Arduino sketch continuously monitors for button presses during the sorting procedure, and the built-in LEDs will flash a certain number of times, corresponding to the mode number, when the `SORTING_STATE` property changes.

### 3.2. Combinations Mode

The "combinations" mode can be used to set the values of the `CHOCOLATE_MODE` and `SORTING_MODE` properties through entering a combination of left and right white arcade game button presses. 

The procedure to enter a combination is as follows:

1. Press the blue arcade game button to enter the "combinations" mode
2. Enter a combination of left and right white arcade game button presses
3. Press the blue arcade game button again to exit the "combinations" mode

The Smartie Sorter 3000 will enter the selected operating mode if a valid combination of white arcade game button presses was entered. The built-in LEDs will flash a certain number of times, corresponding to the mode number, to confirm that the combination has been accepted.

### 3.3. Combinations

A numeric system is used to keep track of the white arcade game button presses during "combination" mode. Presses of the left white arcade game button (`L`) count +1 point while presses of the right white arcade game button (`R`) count +10 points. The selected operating mode is then entered based on the total points score. Table 3 provides the supported combinations and their respective actions.

Table 3: The combinations for setting the values of the `CHOCOLATE_MODE` and `SORTING_MODE` properties

| Mode Number | Combination     | Numeric Value | Action                                           |
|:-----------:|-----------------|:-------------:|--------------------------------------------------|
|      -      | `L`             |       1       | Displays the active chocolate mode.              |
|      -      | `R`             |       10      | Displays the active sorting mode.                |
|      3      | `L L R L L R L` |       25      | Sets the value of `CHOCOLATE_MODE` to SMARTIES.  |
|      4      | `L R L L R L R` |       34      | Sets the value of `CHOCOLATE_MODE` to M_AND_M_S. |
|      5      | `R L R R R L R` |       52      | Sets the value of `SORTING_MODE` to UNCOLLATED.  |
|      6      | `R R L R L L R` |       43      | Sets the value of `SORTING_MODE` to COLLATED.    |

