size, index=map(int,input().split())

every_score=list(map(int,input().split()))
    
every_score.sort(reverse=True)

print(every_score[index-1])