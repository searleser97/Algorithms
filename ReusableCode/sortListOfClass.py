class MyObject:
    def __init__(self, first, second):
        self.first = first
        self.second = second

l = [MyObject('c', 3), MyObject('a', 1), MyObject('b', 2)]

for myObject in l:
    print(myObject.first, myObject.second)
print()
l.sort(key=lambda x: x.first, reverse=False)

for myObject in sorted(l, key=lambda x: x.first, reverse=False):
    print(myObject.first, myObject.second)

print()

for myObject in l:
    print(myObject.first, myObject.second)