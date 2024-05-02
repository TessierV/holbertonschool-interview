# Rain Based on Walls

## Overview
This Python script calculates the amount of water retained after it rains, based on a given list of non-negative integers representing walls of width 1.

## Description

The `rain` function takes a list of wall heights as input and calculates the amount of water that can be retained between the walls after a rainstorm. The function iterates through the list of wall heights and determines the water level at each position by finding the minimum height of the tallest walls to the left and right of each wall.

## Usage

To use the `rain` function, simply call it with a list of non-negative integers representing the heights of the walls:
