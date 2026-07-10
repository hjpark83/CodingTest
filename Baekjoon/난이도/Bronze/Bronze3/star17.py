num=int(input())

for i in range(1,num):
    print(" "*(num-i),end="")
    print("*",end="")
    if i>1:
        print(" "*(2*i-3),end="")
        print("*")
    else:
        print("")
print("*"*(2*num-1))