# Question: BJ 2812 (https://www.acmicpc.net/problem/2812)
# Rank: Gold3
# Algorithm: Data structure, Stack, Greedy

import sys
input = sys.stdin.readline

N, K = map(int, input().split())
num = list(input().rstrip())

stack = []
cnt = 0
for i in range(N):
    while stack and cnt < K and stack[-1] < num[i]:
        stack.pop()
        cnt += 1
    stack.append(num[i])
    
for i in range(N-K):
    print(stack[i], end='')
print()