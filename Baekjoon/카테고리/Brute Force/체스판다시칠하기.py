# Question: BJ 1018 (https://www.acmicpc.net/problem/1018)
# Rank: Silver 3
# Algorithm: Brute Force, Implementation

import sys
input = sys.stdin.readline

N, M = map(int, input().split())
board = [input().rstrip() for _ in range(N)]

def count_repaint(x, y):
    repaint_w = 0
    repaint_b = 0
    for i in range(x, x + 8):
        for j in range(y, y + 8):
            if (i + j) % 2 == 0:
                if board[i][j] != 'W':
                    repaint_w += 1
                if board[i][j] != 'B':
                    repaint_b += 1
            else:
                if board[i][j] != 'B':
                    repaint_w += 1
                if board[i][j] != 'W':
                    repaint_b += 1
    return min(repaint_w, repaint_b)

min_repaint = float('inf')
for i in range(N - 7):
    for j in range(M - 7):
        min_repaint = min(min_repaint, count_repaint(i, j))
print(min_repaint)