# Question: BJ 25682 (https://www.acmicpc.net/problem/25682)
# Rank: Gold 4
# Algorithm: Cumulative Sum, Implementation

import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
board = [input().strip() for _ in range(N)]

# 누적합 배열 생성
B_prefix = [[0] * (M + 1) for _ in range(N + 1)]
W_prefix = [[0] * (M + 1) for _ in range(N + 1)]

for i in range(1, N + 1):
    for j in range(1, M + 1):
        if (i+j) % 2 == 0:
            B_prefix[i][j] = B_prefix[i-1][j] + B_prefix[i][j-1] - B_prefix[i-1][j-1] + (board[i-1][j-1] == 'W')
            W_prefix[i][j] = W_prefix[i-1][j] + W_prefix[i][j-1] - W_prefix[i-1][j-1] + (board[i-1][j-1] == 'B')
        else:
            B_prefix[i][j] = B_prefix[i-1][j] + B_prefix[i][j-1] - B_prefix[i-1][j-1] + (board[i-1][j-1] == 'B')
            W_prefix[i][j] = W_prefix[i-1][j] + W_prefix[i][j-1] - W_prefix[i-1][j-1] + (board[i-1][j-1] == 'W')

def get_repaints(prefix, x1, y1, x2, y2):
    return prefix[x2][y2] - prefix[x1][y2] - prefix[x2][y1] + prefix[x1][y1]

min_repaints = float('inf')

for i in range(N - K + 1):
    for j in range(M - K + 1):
        black_count = get_repaints(B_prefix, i, j, i + K, j + K)
        white_count = get_repaints(W_prefix, i, j, i + K, j + K)
        min_repaints = min(min_repaints, black_count, white_count)
        
print(min_repaints)