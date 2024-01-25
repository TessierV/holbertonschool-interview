![image](https://github.com/TessierV/holbertonschool-interview/assets/113889290/ad2f608d-c78c-4ec3-b61b-e156fe5c6393)

## Overview

In this exercise, the goal is to calculate the fewest number of operations needed to obtain exactly n occurrences of the character 'H' in a text file. The text editor can perform only two operations: Copy All and Paste. The challenge is to be efficient in utilizing these operations to achieve the desired count of 'H'.

## Project Structure

- **0-minoperations.py**: This file contains the Python script with a function minOperations(n) that calculates the minimum number of operations needed to obtain n occurrences of 'H'.

- **0-main.py**: This is a test file that demonstrates the usage of the minOperations function with example cases.

## Example Usage

```
n = 9

H => Copy All => Paste => HH => Paste =>HHH => Copy All => Paste => HHHHHH => Paste => HHHHHHHHH

Number of operations: 6

carrie@ubuntu:~/minoperations$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 12
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

carrie@ubuntu:~/minoperations$
carrie@ubuntu:~/minoperations$ ./0-main.py
Min number of operations to reach 4 characters: 4
Min number of operations to reach 12 characters: 7
carrie@ubuntu:~/minoperations$```
