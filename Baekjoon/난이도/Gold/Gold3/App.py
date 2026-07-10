# Question: BJ 7579 (https://www.acmicpc.net/problem/7579)
# Rank: Gold3
# Algorithm: DP, Knapsack 

import sys
input = sys.stdin.readline

N, M = map(int, input().split())
Byte = [0]+list(map(int, input().split()))
Cost = [0]+list(map(int, input().split()))

answer = 10001

DP = [[0] * (sum(Cost) + 1) for _ in range(N + 1)]

for i in range(1, N+1):
    for j in range(sum(Cost)+1):
        DP[i][j] = DP[i-1][j]
    for j in range(Cost[i], sum(Cost)+1):
        DP[i][j] = max(DP[i][j], DP[i-1][j-Cost[i]] + Byte[i])
        
        if DP[i][j] >= M:
            answer = min(answer, j)
            
print(answer)