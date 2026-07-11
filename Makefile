# Project name: Smartie Sorter 3000
# File type:    GNU Makefile
# Created by:   Pieter van den Berg
# Created on:   5 July 2026

# Define the build variables for the smartie_sorter.ino sketch
smartie-sorter-config-file := ./smartie_sorter/sketch.yaml
smartie-sorter-build-folder := ./smartie_sorter/build
smartie-sorter-profile := arduino.renesas_uno.nanor4

# Define the build variables for the management.ino sketch
management-config-file := ./management/sketch.yaml
management-build-folder := ./management/build
management-profile := arduino.renesas_uno.nanor4

# Set the default target to the upload command
.PHONY: default
default: upload

# Install the Arduino Renesas core for the Arduino Nano R4 board
.PHONY: install
install:
	arduino-cli core install arduino:renesas_uno

# Compile the smartie_sorter.ino sketch
.PHONY: compile
compile: ${smartie-sorter-build-folder}/${smartie-sorter-profile}/smartie_sorter.ino.bin

# Generate the compiled smartie_sorter.ino.bin binary file
${smartie-sorter-build-folder}/${smartie-sorter-profile}/smartie_sorter.ino.bin: ./smartie_sorter/smartie_sorter.ino
	arduino-cli compile ./smartie_sorter --config-file ${smartie-sorter-config-file} --export-binaries

# Upload the compiled smartie_sorter.ino.bin binary file to the Arduino Nano R4 board
.PHONY: upload
upload: ${smartie-sorter-build-folder}/${smartie-sorter-profile}/smartie_sorter.ino.bin
	arduino-cli upload --config-file ${smartie-sorter-config-file} --port ${port} --input-file ${smartie-sorter-build-folder}/${smartie-sorter-profile}/smartie_sorter.ino.bin

# Compile the management.ino sketch
.PHONY: compile-management
compile-management: ${management-build-folder}/${management-profile}/management.ino.bin

# Generate the compiled management.ino.bin binary file
${management-build-folder}/${management-profile}/management.ino.bin: ./management/management.ino
	arduino-cli compile ./management --config-file ${management-config-file} --export-binaries

# Upload the compiled management.ino.bin binary file to the Arduino Nano R4 board
.PHONY: upload-management
upload-management: ${management-build-folder}/${management-profile}/management.ino.bin
	arduino-cli upload --config-file ${management-config-file} --port ${port} --input-file ${management-build-folder}/${management-profile}/management.ino.bin

# Delete the build folder for the smartie_sorter.ino sketch
.PHONY: clean
clean:
	rm -rf ${smartie-sorter-build-folder}

# Delete the build folder for the management.ino sketch
.PHONY: clean-management
clean-management:
	rm -rf ${management-build-folder}

