# Question: BJ 11729 (https://www.acmicpc.net/problem/11729)
# Rank: Gold 5
# Algorithm: Recursion

import sys
input = sys.stdin.readline

def hanoi(n, start, to, via):
    if n == 1:
        print(start, to)
        return
    hanoi(n-1, start, via, to)
    print(start, to)
    hanoi(n-1, via, to, start)
    
N = int(input())
print(2**N - 1)
hanoi(N, 1, 3, 2)