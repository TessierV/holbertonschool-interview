![image](https://github.com/TessierV/holbertonschool-interview/assets/113889290/d637fafc-835a-48c1-b03e-46e7baec8b08)


# Tasks

You have n number of locked boxes in front of you. Each box is numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes.

Write a method that determines if all the boxes can be opened.

Prototype: def canUnlockAll(boxes)
boxes is a list of lists
A key with the same number as a box opens that box
You can assume all keys will be positive integers
There can be keys that do not have boxes
The first box boxes[0] is unlocked
Return True if all boxes can be opened, else return False


## Script Test

```python
#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))
```
    

## Result Expected

```carrie@ubuntu:~/lockboxes$
carrie@ubuntu:~/lockboxes$ ./main_0.py
True
True
False
carrie@ubuntu:~/lockboxes$
```


<br/><hr>
<p align="right">Holberton TOULOUSE</p>
