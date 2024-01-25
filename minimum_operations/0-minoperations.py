#!/usr/bin/python3
'''
Calculates the fewest number of operations
'''

def minOperations(n):
    '''
    minOperations - Return the fewest number of operations needed
    @n: The number of H characters needed

    Return: The fewest number of operations needed, or 0
    '''
    if n <= 1:
        return 0

    operations = 0
    sum = 2

    while sum <= n:
        while n % sum == 0:
            operations += sum
            n //= sum
        sum += 1

    return operations
