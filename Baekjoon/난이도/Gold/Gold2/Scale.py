# Question: BJ 2437 (https://www.acmicpc.net/problem/2437)
# Rank: Gold2
# Algorithm: Greedy, Sorting

import sys
input = sys.stdin.readline

N = int(input())
weights = list(map(int, input().split()))

weights.sort()

if weights[0] != 1:
    print(1)
else:
    answer = 1
    for i in range(1, N):
        if weights[i] > answer + 1:
            break
        answer += weights[i]
    print(answer + 1)