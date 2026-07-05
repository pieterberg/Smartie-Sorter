# Project name: Smartie Sorter 3000
# File name:    GNU Makefile
# Created by:   Pieter van den Berg
# Created on:   5 July 2026

.PHONY: install

# Install the Arduino Renesas core for the Arduino Nano R4 board
install:
	arduino-cli core install arduino:renesas_uno


