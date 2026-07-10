# Question: BJ 2805 (https://www.acmicpc.net/problem/2805)
# Rank: Silver 2 
# Algorithm: binary search

import sys
input = sys.stdin.readline

N, M = map(int, input().split())
trees = list(map(int, input().split()))

def cut_tree(h):
    total = 0
    for tree in trees:
        if tree > h:
            total += tree - h
        if total >= M:
            return total
    return total

left, right = 0, max(trees)
result = 0

while left <= right:
    mid = (left + right) // 2
    if cut_tree(mid) >= M:
        result = mid
        left = mid + 1
    else:
        right = mid - 1

print(result)
