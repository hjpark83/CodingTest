# Question: BJ 17299 (https://www.acmicpc.net/problem/17299)
# Rank: Gold3
# Algorithm: Data Structure, Stacks

import sys
input = sys.stdin.readline

N = int(input())

A = list(map(int, input().split()))

F = [0] * 1000001
# frequency
for a in A:
    F[a] += 1
    
stack = []
# Next Greater Frequency
NGF = [-1] * N

# stack에는 index를 넣는다.
for i in range(N):
    # stack이 비어있지 않고, stack의 top의 frequency가 현재 frequency보다 작다면
    while stack and F[A[stack[-1]]] < F[A[i]]:
        NGF[stack.pop()] = A[i] # A[i]가 NGF
    stack.append(i) # 그렇지 않으면 stack에 넣는다.
    
print(*NGF)