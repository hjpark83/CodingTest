# Question: BJ 11559 (https://www.acmicpc.net/problem/11559)
# Rank: Gold4
# Algorithm: Implementation. Graph. BFS, Simulation

import sys
input = sys.stdin.readline

Map = [list(input().rstrip()) for _ in range(12)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(x, y):
    q = [(x, y)]
    visited = [[0]*6 for _ in range(12)]
    visited[x][y] = 1
    cnt = 1
    color = Map[x][y]
    while q:
        x, y = q.pop(0)
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0 <= nx < 12 and 0 <= ny < 6 and not visited[nx][ny] and Map[nx][ny] == color:
                visited[nx][ny] = 1
                cnt += 1
                q.append((nx, ny))
    if cnt >= 4: # 4개 이상의 블록이 연결되어 있으면
        for i in range(12):
            for j in range(6):
                if visited[i][j]:
                    Map[i][j] = '.' # 터뜨릴 블록을 .으로 바꿈
        return True
    return False

def gravity():
    for j in range(6):
        for i in range(11, -1, -1): # 아래에서부터 위로 올라가면서 빈칸을 찾아서 블록을 내림
            if Map[i][j] == '.': # 빈칸을 찾으면
                for k in range(i-1, -1, -1): # 그 위에 있는 블록을 찾아서 내림
                    if Map[k][j] != '.':
                        Map[i][j], Map[k][j] = Map[k][j], Map[i][j] # 블록을 내림
                        break
                    
def solve():
    cnt = 0
    while True:
        flag = False
        for i in range(12):
            for j in range(6):
                if Map[i][j] != '.':
                    if bfs(i, j): # 4개 이상의 블록이 연결되어 있으면
                        flag = True
        if not flag:
            break
        gravity() 
        cnt += 1
    return cnt

print(solve())