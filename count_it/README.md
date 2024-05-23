# Count it!

## Overview
This project involves creating a recursive function that queries the Reddit API, parses the titles of all hot articles, and prints a sorted count of given keywords (case-insensitive, delimited by spaces). For example, "Javascript" should count as "javascript", but "java" should not count as "javascript".

## Requirements
- All files will be interpreted/compiled on Ubuntu 14.04 LTS using python3 (version 3.4.3).
- All files should end with a new line.
- The first line of all files should be exactly `#!/usr/bin/python3`.
- Libraries imported in Python files must be organized in alphabetical order.
- A `README.md` file, at the root of the folder of the project, is mandatory.
- Code should use the PEP 8 style.
- All files must be executable.
- The length of files will be tested using `wc`.
- All modules should have documentation (`python3 -c 'print(__import__("my_module").__doc__)'`).
- The `Requests` module must be used for sending HTTP requests to the Reddit API.

## Usage
```python3 0-main.py <subreddit> <list of keywords>```
