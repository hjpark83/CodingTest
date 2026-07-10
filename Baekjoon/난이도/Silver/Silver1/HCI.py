# Question: BJ 16139 (https://www.acmicpc.net/problem/16139)
# Rank: Silver1
# Algorithm: Aggregation

import sys
input = sys.stdin.readline

S = input().rstrip()
Q = int(input().rstrip())
A = [[0]*len(S) for _ in range(26)] # 각 문자별로 나온 횟수를 저장할 배열

for i in range(len(S)):
    A[ord(S[i])-ord('a')][i] += 1 # 해당 문자가 나온 횟수를 저장 
    
for i in range(26):
    for j in range(1, len(S)): 
        A[i][j] += A[i][j-1] # 누적합을 구함
        
for i in range(Q):
    a, l, r = input().split()
    tmp = A[ord(a)-ord('a')][int(r)] - A[ord(a)-ord('a')][int(l)] 
    # 해당 문자가 l~r까지 나온 횟수를 구함
    # ord(a) - ord('a') = 해당 문자의 인덱스
    if S[int(l)] == a: 
        tmp += 1
        
    print(tmp)