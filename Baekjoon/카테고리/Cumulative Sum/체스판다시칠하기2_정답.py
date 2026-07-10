import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
board = [input().strip() for _ in range(N)]

prefix = [[0] * (M + 1) for _ in range(N + 1)]

for i in range(1, N + 1):
    for j in range(1, M + 1):
        expected = 'B' if (i + j) % 2 == 0 else 'W'
        mismatch = 1 if board[i-1][j-1] != expected else 0
        
        prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + mismatch

def get_mismatches(x1, y1, x2, y2):
    return prefix[x2][y2] - prefix[x1][y2] - prefix[x2][y1] + prefix[x1][y1]

min_repaints = float('inf')

for i in range(N - K + 1):
    for j in range(M - K + 1):
        pattern1 = get_mismatches(i, j, i + K, j + K)
        pattern2 = K * K - pattern1
        min_repaints = min(min_repaints, pattern1, pattern2)

print(min_repaints)
