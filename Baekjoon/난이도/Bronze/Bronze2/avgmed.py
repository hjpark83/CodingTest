my_list=[]

for i in range(5):
    num=int(input())
    my_list.append(num)

sorted_list=sorted(my_list)

sum=0
avg=0
median=0
for i in range(5):
    sum=sum+sorted_list[i]
    avg=int(sum/5)
    median=sorted_list[2]
    
print(avg)
print(median)    