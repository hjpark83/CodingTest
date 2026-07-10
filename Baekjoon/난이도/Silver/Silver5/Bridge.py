def Combi(K,N):
    if K==0 or N==K:
        return 1
    elif N<K:
        return 0
    else:
        up=1
        down=1
        for i in range(1,K+1):
            up=up*(N-i+1)
            down=down*i
        return up/down
    
def main():
    count=int(input())
    for i in range(count):
        K,N=map(int,input().split())
        result=Combi(K,N)
        print(int(result))
main()