# Question: BJ 10830 (https://www.acmicpc.net/problem/10830)
# Rank: Gold4
# Algorithm: Math, Merge, Linear Algebra

import sys
input = sys.stdin.readline

N, B = map(int, input().split())
matrix = []

for _ in range(N):
    matrix.append(list(map(int, input().split())))
    
def multiply(A, B):
    result = [[0]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                result[i][j] += A[i][k]*B[k][j]
            result[i][j] %= 1000
    return result
    
def power(A, B):
    if B==1:
        return A
    else:
        tmp = power(A, B//2)
        if B%2==0:
            return multiply(tmp, tmp)
        else:
            return multiply(multiply(tmp, tmp), A)
    
result = power(matrix, B)
for row in result:
    for col in row:
        print(col%1000, end=" ")
    print()
        
