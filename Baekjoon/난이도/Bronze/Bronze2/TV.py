import sys
import math

D,H,W=map(int,input().split())

ratio=math.sqrt(D**2/(H**2+W**2))

real_height=math.trunc(ratio*H)
real_width=math.trunc(ratio*W)

print(real_height,real_width)