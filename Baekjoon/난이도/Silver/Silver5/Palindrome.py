from itertools import combinations

T=int(input())

for _ in range(T):
    N=int(input())
    ls=list(input() for i in range(N))
    combi=combinations(ls,2)
    
    for a,b in combi:
        add1=a+b
        add2=b+a
        if add1==add1[::-1]:
            print(add1)
            break
        if add2==add2[::-1]:
            print(add2)
            break
    else:
        print(0)
        