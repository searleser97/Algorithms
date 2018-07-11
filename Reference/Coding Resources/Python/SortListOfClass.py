class MyObject :
  def __init__(self, first, second, third):
    self.first = first
    self.second = second
    self.third = third

li = [MyObject('b', 3, 1), MyObject('a', 3, 2), MyObject('b', 3, 3)]
# returns list sorted by first then by second then by third in increasing order
ol = sorted(li, key = lambda x: (x.first, x.second, x.third), reverse=False)
# sorts inplace by first then by second then by third in increasing order
li.sort(key = lambda x: (x.first, x.second, x.third), reverse=False)
