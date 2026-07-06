# Project name: Smartie Sorter 3000
# File type:    GNU Makefile
# Created by:   Pieter van den Berg
# Created on:   5 July 2026

# Install the Arduino Renesas core for the Arduino Nano R4 board
.PHONY: install
install:
	arduino-cli core install arduino:renesas_uno

# Compile the management.ino sketch
.PHONY: compile-management
compile-management:
	arduino-cli compile ./management --config-file ./management/sketch.yaml --export-binaries

