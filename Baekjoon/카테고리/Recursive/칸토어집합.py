# Question: BJ 4779 (https://www.acmicpc.net/problem/4779)
# Rank: Silver 3
# Algorithm: Recursion

import sys
input = sys.stdin.readline

def cantoer(n):
    if n == 0:
        return '-'
    prev = cantoer(n-1)
    return prev + ' ' * (3**(n-1)) + prev

while True:
    N = input().strip()
    if N == '':
        break
    N = int(N)
    print(cantoer(N))