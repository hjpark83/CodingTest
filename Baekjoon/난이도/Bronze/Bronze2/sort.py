my_List=[]
n=int(input())

for i in range(n):
    num=int(input())
    my_List.append(num)
    
my_List=sorted(my_List)
for i in range(n):
    print(my_List[i])