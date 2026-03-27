# Question: BJ 9370 (https://www.acmicpc.net/problem/9370)
# Rank: Gold 2
# Algorithm: Shortest Path, Dijkstra

import sys
import heapq

input = sys.stdin.readline
INF = int(1e9)

def dijkstra(start, n, graph):
    distances = [INF] * (n + 1)
    queue = []
    heapq.heappush(queue, (0, start))
    distances[start] = 0
    
    while queue:
        d, now = heapq.heappop(queue)
        if distances[now] < d:
            continue
        
        for neighbor, weight in graph[now]:
            cost = d + weight
            if cost < distances[neighbor]:
                distances[neighbor] = cost
                heapq.heappush(queue, (cost, neighbor))
    return distances


T = int(input())
for _ in range(T):
    n, m, t = map(int, input().split())
    s, g, h = map(int, input().split())
    
    graph = [[] for _ in range(n + 1)]
    gh_weight = 0
    
    for _ in range(m):
        a, b, d = map(int, input().split())
        graph[a].append((b, d))
        graph[b].append((a, d))
        if (a == g and b == h) or (a == h and b == g):
            gh_weight = d
    
    targets = []
    for _ in range(t):
        targets.append(int(input()))
    
    dist_s = dijkstra(s, n, graph)
    dist_g = dijkstra(g, n, graph)
    dist_h = dijkstra(h, n, graph)
    
    result = []
    for e in targets:
        # s -> g -> h -> e 경로의 길이
        path1 = dist_s[g] + gh_weight + dist_h[e]
        # s -> h -> g -> e 경로의 길이
        path2 = dist_s[h] + gh_weight + dist_g[e]
        
        # s에서 e까지의 최단 거리와, g-h를 거친 경로 중 하나라도 같다면 정답
        shortest = dist_s[e]
        if shortest != INF:
            if shortest == path1 or shortest == path2:
                result.append(e)
    
    result.sort()
    if result:
        print(*(result))