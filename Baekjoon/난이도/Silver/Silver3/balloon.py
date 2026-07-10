import sys
from collections import deque

N=int(input()) # input을 받아옴
balloon = deque([(idx, val) for idx, val in enumerate(map(int, sys.stdin.readline().split()), start=1)])

answer=[]

for _ in range(N):
    idx, val=balloon.popleft()
    answer.append(idx)
    if val>0:
        balloon.rotate(-(val-1))
    else:
        balloon.rotate(-val)
    
print(*answer)