from sys import stdin, stdout
from collections import *

def read():
  return list(map(int, stdin.readline().split()))

n, k = read()
inque = set()
q = deque()

ids = read()

for i in range(len(ids)):
  id = ids[i]
  if id in inque:
    continue
  if len(q) == k:
    inque.remove(q.pop())
  q.appendleft(id)
  inque.add(id)

stdout.write(str(len(q)))
stdout.write("\n")

for i in range(len(q)):
  if i:
    stdout.write(" ")
  stdout.write(str(q[i]))
stdout.write("\n")