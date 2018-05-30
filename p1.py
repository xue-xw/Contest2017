a = int(input())
b = int(input())
c = b-a
if c<0:
    sign=-1
elif c>0:
    sign=1
else:
    sign=0

if sign==-1:
    magnitude = -c
else:
    magnitude = c

ret = 0
if magnitude==180:
    ret = 180
elif magnitude>180:
    ret = (360-magnitude)*(-sign)
elif magnitude<180:
    ret = sign*magnitude

print(ret)

