# Question: BJ 14500 (https://www.acmicpc.net/problem/14500)
# Rank: Gold4
# Algorithm: Implementation, Brute Force

import sys
input = sys.stdin.readline

N, M = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(N)]

TetroMino = [
        [(0, 0), (0, 1), (1, 0), (1, 1)], 
        [(0, 0), (0, 1), (0, 2), (0, 3)], 
        [(0, 0), (1, 0), (2, 0), (3, 0)], 
        [(0, 0), (1, 0), (1, 1), (2, 1)], 
        [(1, 0), (0, 1), (1, 1), (2, 0)], 
        [(1, 0), (1, 1), (0, 1), (0, 2)], 
        [(0, 0), (0, 1), (1, 1), (1, 2)],
        [(0, 0), (1, 0), (2, 0), (2, 1)], 
        [(0, 1), (1, 1), (2, 0), (2, 1)], 
        [(0, 0), (0, 1), (1, 0), (2, 0)],
        [(0, 0), (0, 1), (1, 1), (2, 1)],
        [(1, 0), (0, 1), (1, 1), (1, 2)],
        [(0, 0), (0, 1), (0, 2), (1, 1)],
        [(0, 0), (1, 0), (1, 1), (1, 2)],
        [(1, 0), (1, 1), (1, 2), (0, 2)],
        [(0, 0), (0, 1), (0, 2), (1, 0)],
        [(0, 0), (0, 1), (0, 2), (1, 2)],
        [(0, 0), (1, 0), (1, 1), (2, 0)],
        [(1, 0), (0, 1), (1, 1), (2, 1)]
] 

def inRange(x, y):
    return 0 <= x < N and 0 <= y < M

def getSum(x, y):
    global answer
    for i in range(len(TetroMino)):
        temp = 0
        for j in range(4):
            nx, ny = x + TetroMino[i][j][0], y + TetroMino[i][j][1]
            if not inRange(nx, ny):
                break
            temp += board[nx][ny]
        answer = max(answer, temp)

answer = 0
for i in range(N):
    for j in range(M):
        getSum(i, j)
        
print(answer)