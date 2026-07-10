num=int(input())

for i in range(1,num+1):
    print("*"*i,end="")
    print(" "*2*(num-i),end="")
    print("*"*i)
for j in range(1,num):
    print("*"*(num-j),end="")
    print(" "*(2*j),end="")
    print("*"*(num-j))