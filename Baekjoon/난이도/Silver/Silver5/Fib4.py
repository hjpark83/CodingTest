import sys
input=sys.stdin.readline

n=int(input())
Fib=[0,1]

for i in range(2,n+1):
    Fib.append(Fib[i-1]+Fib[i-2])
    
print(Fib[n])