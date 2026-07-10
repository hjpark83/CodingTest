# Question: BJ 1989 (https://www.acmicpc.net/problem/1989)
# Rank: Platinum 5
# Algorithm: Data structure, Segment Tree, Aggregation, Divide and Conquer, Stack

import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

i = 0
j = 0
result = -1

def solve(x, y):
    global i, j, result
    
    if x == y:
        if A[x]*A[x] > result:
            result = A[x]*A[x]
            i = x
            j = x
        return result
        
    mid = (x+y)//2
    
    left = solve(x, mid)
    right = solve(mid+1, y)
    
    if left > result:
        result = left
        i = x
        j = mid
    if right > result:
        result = right
        i = mid+1
        j = y
        
    left = mid
    right = mid+1
    
    sub = A[left] + A[right]
    min_ = min(A[left], A[right])
    
    if result < min_*sub:
        i = left
        j = right
        result = min_*sub
        
    while x < left or right< y:
        if right < y and (x == left or A[left-1] < A[right+1]):
            right += 1
            sub += A[right]
            min_ = min(min_, A[right])
        else:
            left -= 1
            sub += A[left]
            min_ = min(min_, A[left])
            
        if result < min_*sub:
            i = left
            j = right
            result = min_*sub
            
    return result

print(solve(0, N-1))
print(i+1, j+1)