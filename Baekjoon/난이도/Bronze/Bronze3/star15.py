num=int(input())

for i in range(1,num+1):
    print(" "*(num-i),end="")
    print("*",end="")
    if i>1:
        print(" "*(2*i-3),end="")
        print("*")
    else:
        print("")
    