# Question: BJ 14621 (https://www.acmicpc.net/problem/14621)
# Rank: Gold3
# Algorithm: Graph, MST

import sys
input = sys.stdin.readline

N, M = map(int, input().split())
Univ = list(input().split())

for i in range(N):
    if Univ[i] == 'M':
        Univ[i] = 1
    else:
        Univ[i] = 0
        
edges = []
for _ in range(M):
    u, v, w = map(int, input().split())
    edges.append((w, u-1, v-1))
    
edges.sort()

parent = [i for i in range(N)]

def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]

def union(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        return
    parent[x] = y
    
ans = 0
cnt = 0
for w, u, v in edges:
    if find(u) == find(v):
        continue
    if Univ[u] == Univ[v]:
        continue
    union(u, v)
    ans += w
    cnt += 1
    
if cnt != N-1:
    print(-1)
else:
    print(ans)