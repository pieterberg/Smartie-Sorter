# Smartie Sorter 3000

<img src="https://img.shields.io/badge/Arduino-Nano R4-008BC0?logo=arduino&logoColor=FFFFFF&style=flat"/> <img src="https://img.shields.io/badge/Autodesk-Fusion 360-008BC0?logo=autodesk&logoColor=FFFFFF&style=flat"/> [![Arduino Lint](https://github.com/pieterberg/Smartie-Sorter/actions/workflows/arduino_lint.yaml/badge.svg)](https://github.com/pieterberg/Smartie-Sorter/actions/workflows/arduino_lint.yaml) [![Arduino Compilation](https://github.com/pieterberg/Smartie-Sorter/actions/workflows/arduino_compilation.yaml/badge.svg)](https://github.com/pieterberg/Smartie-Sorter/actions/workflows/arduino_compilation.yaml)

<img src="images/Smartie_Sorter.png" alt="Arduino Smartie Sorter" width="50%"/><img src="images/smartie_sorter_interface.png" alt="Smartie Sorter Interface" width="50%"/>

Smartie Sorter 3000 project for sorting Smarties and M&M's based on their colour using the TCS3200 colour sensor built into a mini arcade game enclosure.

The project was written using C++ and runs on an Arduino Nano R4 microcontroller. The mini arcade game enclosure was designed using Fusion 360. The physical components were either laser-cut out of MDF and acrylic, or 3D printed using a Bambu Lab X1 Series 3D printer.

## Arduino Sketches

- The [smartie_sorter.ino](smartie_sorter/smartie_sorter.ino) sketch contains the main logic for the Smartie Sorter 3000 mini arcade game. First, the sketch initialises the Smartie Sorter 3000 after the power is switched on. The user interaction is handled by reading the button presses and providing feedback to the user through flashing the built-in LED lights. The RGB spectra of the Smarties and M&M chocolates are measured using the TCS3200 colour sensor and their colours are determined using the trained colour-detection classifier. The chocolates are then sorted using the servo motors by reading the calibrated positions stored in the EEPROM. Finally, the total number of sorted chocolates is updated and stored in the EEPROM.

- [Management.ino](management/management.ino) provides the required utilities to manage the Smartie Sorter 3000. The sketch contains code to initialise the EEPROM addresses of new Arduino boards. The management tool can then be used to generate training datasets of the RGB spectra measured by the TCS3200 colour sensor in order to train the colour-detection classifiers. An interface for calibrating the servo motors is also provided. Finally, an option is available to view the total number of sorted Smarties and M&M chocolates. These utilities can be accessed through a 9600 Baud serial channel.

## Arduino CLI

A Makefile is provided that can be used to compile and upload the Arduino sketches using the [Arduino CLI](https://github.com/arduino/arduino-cli). The make commands should all be run from the project's root directory.

First, run the install command to install the required core for the Arduino Nano R4 board. This will install the Arduino Renesas core (arduino:renesas_uno) if it is not already installed.

```shell
make install
```

The upload command can be used to compile and upload the smartie_sorter.ino sketch to the Arduino Nano R4 board. Replace the `port` parameter with the relevant port of the Arduino Nano R4 board. The ports of the attached Arduino boards can be viewed by running `arduino-cli board list` in the terminal.

```shell
make upload port=COM7
```

The upload-management command can be used to compile and upload the management.ino sketch to the Arduino Nano R4 board. Once again replace the `port` parameter with the relevant port of the Arduino Nano R4 board.

```shell
make upload-management port=COM7
```

## Git Signatures

The [signatures](./signatures) folder contains the required public SSH keys to verify the git commit signatures. These public SSH keys have been configured in the allowed_signers file.

Run the following command in the project's root directory to configure the repository's local git config file to use the allowed_signers file for verifying the git commmit signatures:

```shell
git config --local gpg.ssh.allowedSignersFile "./signatures/allowed_signers"
```

## Documentation

- [Components.md](documentation/components.md) provides information about the components used in the design of the Smartie Sorter 3000's mini arcade game enclosure. First, it provides information about the different types of components used in the design of the Smartie Sorter 3000's mini arcade game enclosure. Thereafter, it provides information about laser cutting the wooden panels and acrylic components. Finally, it provides information about the Fusion 360 computer aided design (CAD) files.

- [Design.md](documentation/design.md) provides information about the design of the Smartie Sorter 3000. First, it provides information about the name sign present at the top of the Smartie Sorter 3000's mini arcade game enclosure. Thereafter, it provides information about the Smartie Sorter 3000's colour scheme. Finally, it provides information about the sorted Smartie and M&M locations.

## Fusion 360

The [fusion_360](https://github.com/pieterberg/Smartie-Sorter/tree/main/fusion_360) folder contains the .f3d and .f3z Fusion 360 component and assembly files for the Smartie Sorter 3000's mini arcade game enclosure.





