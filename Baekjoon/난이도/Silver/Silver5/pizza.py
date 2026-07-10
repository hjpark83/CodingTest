import sys
sys.stdin.readline

N=int(input())

if(N==0):
    print(0)
    exit(0)
print(N*(N-1)//2)