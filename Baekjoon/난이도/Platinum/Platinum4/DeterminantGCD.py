# Question: BJ 13728 (https://www.acmicpc.net/problem/13728)
# Rank: Platinum4
# Algorithm: Math, Linear Algebra, Integer

import sys
input = sys.stdin.readline

N = int(input())
MOD = 1000000007


def matmul(a, b):
    n = len(a)
    m = len(b)
    l = len(b[0])
    ret = [[0]*l for _ in range(n)]
    for i in range(n):
        for j in range(l):
            for k in range(m):
                ret[i][j] += a[i][k]*b[k][j]
                ret[i][j] %= MOD
    return ret

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

print(pow(2, gcd(N, MOD-1), MOD))
    