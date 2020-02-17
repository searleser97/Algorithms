t = int(input())

for i in range(t):
  n = int(input())
  ones = n // 2
  n = n % 2
  nines = 0
  if n >= 4:
    nines = n // 4
    n = n % 4
  ones = ones - nines
  sevens = 0
  if n >= 1:
    sevens = n
  ones = ones - sevens
  ans = ''
  for i in range(nines):
    ans += '9'
  for i in range(sevens):
    ans += '7'
  for i in range(ones):
    ans += '1'
  print(ans)