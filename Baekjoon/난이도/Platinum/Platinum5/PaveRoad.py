# Question: BJ 1162 (https://www.acmicpc.net/problem/1162)
# Rank: Platinum 5
# Algorithm: DP, Dijkstra, Graph, Shortest Path

import sys
from heapq import heappush, heappop
input = sys.stdin.readline

inf = 10**18

N, M, K = map(int, input().split())
G = [[] for _ in range(N+1)]

for _ in range(M):
    a, b, c = map(int, input().split())
    G[a].append((b, c))
    G[b].append((a, c))
    
dp = [[inf for _ in range(K+1)] for _ in range(N+1)]
dp[1][0] = 0

def dijkstra():
    q = []
    heappush(q, (0, 1, 0))
    while q:
        dist, node, cnt = heappop(q)
        if dp[node][cnt] < dist:
            continue
        for next_node, next_dist in G[node]:
            if dp[next_node][cnt] > dist + next_dist:
                dp[next_node][cnt] = dist + next_dist
                heappush(q, (dist + next_dist, next_node, cnt))
            if cnt < K and dp[next_node][cnt+1] > dist:
                dp[next_node][cnt+1] = dist
                heappush(q, (dist, next_node, cnt+1))
                
dijkstra()
print(min(dp[N]))