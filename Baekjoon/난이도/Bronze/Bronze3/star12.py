num=int(input())

for i in range(1,num+1):
    print(" "*(num-i),end="")
    print("*"*i)
for j in range(1,num):
    print(" "*j,end="")
    print("*"*(num-j))