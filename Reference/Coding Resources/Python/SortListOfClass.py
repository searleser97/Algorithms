class MyObject :
  def __init__(self, first, second):
    self.first = first
    self.second = second

li = [MyObject('c', 3), MyObject('a', 1), MyObject('b', 2)]
li.sort(key = lambda x: x.first, reverse = False)
