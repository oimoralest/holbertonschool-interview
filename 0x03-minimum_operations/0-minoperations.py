#!/usr/bin/python3
"""Context:

In a text file, there is a single character H. Your text editor can execute
only two operations in this file: Copy All and Paste. Given a number n, write
a method that calculates the fewest number of operations needed to result in
exactly n H characters in the file
"""
import math


def minOperations(n):
    """
    Computes the minimum required operations
    """
    if n <= 1:
        return 0
    prime_factors = []
    while n % 2 == 0:
        prime_factors.append(2)
        n = n / 2

    for i in range(3, int(math.sqrt(n))+1, 2):
        while (n % i == 0):
            prime_factors.append(i)
            n = n / i

    if n > 2:
        prime_factors.append(n)

    return int(sum(prime_factors))

if __name__ == '__name__':
    minOperations(8)
