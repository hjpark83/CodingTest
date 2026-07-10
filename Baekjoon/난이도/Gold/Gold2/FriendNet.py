# Question: BJ 4195 (https://www.acmicpc.net/problem/4195)
# Rank: Gold2
# Algorithm: Data Structure, Disjoint Set, Hash Map

import sys
input = sys.stdin.readline

def Find(parent, x):
    if parent[x] != x:
        parent[x] = Find(parent, parent[x])
    return parent[x]

def Union(parent, x, y):
    x = Find(parent, x)
    y = Find(parent, y)
    
    if x==y:
        return Friend[x]
    elif x>y:
        parent[x] = y
        Friend[y] += Friend[x]
    else:
        parent[y] = x
        Friend[x] += Friend[y]
        
        
T = int(input())
for i in range(T):
    Parent = dict()
    Friend = dict()
    
    F = int(input())
    for j in range(F):
        x, y = input().rstrip().split()
        
        if x not in Parent:
            Parent[x] = x
            Friend[x] = 1
        if y not in Parent:
            Parent[y] = y
            Friend[y] = 1
        Union(Parent, x, y)
        print(Friend[Find(Parent, x)])