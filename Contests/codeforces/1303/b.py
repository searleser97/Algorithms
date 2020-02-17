from math import *

t = int(input())
for i in range(t):
  n, g, b = list(map(int, input().split()))
  needrepair = floor((n / 2)) + 1 if (n & 1) else (n / 2)
  ans = needrepair / g * (g + b)
  if (ans > g):
    ans -= b
  if (floor(ans) == ans):
    print(max(n, int(ans)))
  else:
    print(max(n, int(floor(ans) + 1)))