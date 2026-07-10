# Question: BJ 14499 (https://www.acmicpc.net/problem/14499)
# Rank: Gold4
# Algorithm: Implementation, Simulation

import sys
input = sys.stdin.readline

N, M, x, y, K = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
commands = list(map(int, input().split()))

dice = [0]*6
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

for c in commands:
    nx, ny = x+dx[c-1], y+dy[c-1]
    if nx < 0 or nx >= N or ny < 0 or ny >= M:
        continue
    
    if c == 1: # 동
        dice[0], dice[2], dice[3], dice[5] = dice[3], dice[0], dice[5], dice[2]
    elif c == 2: # 서
        dice[0], dice[2], dice[3], dice[5] = dice[2], dice[5], dice[0], dice[3]
    elif c == 3: # 북
        dice[0], dice[1], dice[4], dice[5] = dice[4], dice[0], dice[5], dice[1]
    else: # 남
        dice[0], dice[1], dice[4], dice[5] = dice[1], dice[5], dice[0], dice[4]
    
    if board[nx][ny] == 0:
        board[nx][ny] = dice[5]
    else:
        dice[5] = board[nx][ny]
        board[nx][ny] = 0
        
    x, y = nx, ny
    print(dice[0])