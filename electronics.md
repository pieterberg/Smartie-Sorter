# Electronics

The electronic aspects of the Smartie Sorter 3000 are presented in this document. First, Section 1 lists the electronic components used for the mini arcade game enclosure. Then, Section 2 provides the breadboard and circuit schematics of the mini arcade game enclosure.

All circuit schematics were designed using Fritzing. The Fritzing file is available in the [Fritzing](https://github.com/pieterberg/Smartie-Sorter/tree/main/documentation/electronics/fritzing) folder.

### Table of Contents

- [1. Component list](#1-component-list)
- [2. Schematics](#2-schematics)
  - [2.1. Breadboard Schematic](#21-breadboard-schematic)
  - [2.2. Circuit Schematic](#22-circuit-schematic)

## 1. Component list

The Smartie Sorter 3000 uses an Arduino Nano microcontroller. Table 1 lists the electronic components used for the mini arcade game enclosure.

The Smartie Sorter 3000 has two different circuits running, a 9V circuit used to power the Arduino Nano and circuit components, and a 12V circuit used to power the LED strips. The 12V LED strips are controlled by the Arduino Nano using a 2N2222 NPN transistor.

Table 1: Electronic component list

| Component                           | Amount |
|-------------------------------------|:------:|
| Arduino Nano                        |   1x   |
| 9V batteries                        |   2x   |
| 1.5V batteries                      |   2x   |
| 9V battery holders                  |   2x   |
| 3V battery holder                   |   1x   |
| Light blue Sanwa arcade game button |   1x   |
| White Sanwa arcade game buttons     |   2x   |
| Pull-up resistors                   |   3x   |
| 2N2222 transistor                   |   1x   |
| Transistor resistor                 |   1x   |
| 4-part 12V LED strips               |   2x   |
| 5-part 12V LED strips               |   4x   |
| Power switch                        |   1x   |


## 2. Schematics

The circuit schematics were designed using Fritzing, and are presented in this section.

### 2.1. Breadboard Schematic

The breadboard schematic of the Smartie Sorter 3000 is presented in Figure 1. In Figure 1, the left breadboard is the 12V circuit, while the right breadboard is the 9V circuit. The grounds of the two breadboards are conencted for the 2N2222 NPN transistor to work.

<img src="https://github.com/pieterberg/Smartie-Sorter/blob/main/documentation/electronics/breadboard.png" alt="Breadboard schematic" width="70%">

Figure 1: Breadboard schematic of the Smartie Sorter 3000. The left breadboard is the 12V circuit and the right breadboard is the 9V circuit.

### 2.2. Circuit Schematic

The bcircuit schematic of the Smartie Sorter 3000 is presented in Figure 2. In Figure 2, the left loop is the 12V circuit, while the right loop is the 9V circuit. The grounds of the two loops are conencted for the 2N2222 NPN transistor to work.

<img src="https://github.com/pieterberg/Smartie-Sorter/blob/main/documentation/electronics/schematic.png" alt="Schematic" width="70%">

Figure 2: Circuit schematic of the Smartie Sorter 3000. The left loop is the 12V circuit and the right loop is the 9V circuit.
