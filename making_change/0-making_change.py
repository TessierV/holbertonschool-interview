#!/usr/bin/python3
"""Making Change"""


def makeChange(coins, total):
    """
    Found the fewest number of coins needed
    to meet a given total total
    """

    if total < 1:
        return 0
    dp = [-1 for num in range(0, total + 1)]

    for num in coins:
        if num > len(dp) - 1:
            continue
        dp[num] = 1
        for x in range(num + 1, total + 1):
            if dp[x - num] == -1:
                continue
            elif dp[x] == -1:
                dp[x] = dp[x - num] + 1
            else:
                dp[x] = min(dp[x], dp[x - num] + 1)
    return dp[total]
