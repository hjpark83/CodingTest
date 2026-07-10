num=int(input())

for i in range(1,num+1):
    print(" "*(num-i),end="")
    print("*"*(2*i-1))
    
for j in range(num-1,0,-1):
    print(" "*(num-j),end="")
    print("*"*(2*j-1))
    