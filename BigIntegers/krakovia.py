from fractions import Fraction

number = 1
while True:
    N, F = map(int, input().split())
    if N == 0 and F == 0:
        break
    addition = 0
    for i in range(N):
        addition += int(input())
    print('Bill #' + str(number) + ' costs ' + str(addition) + ': each friend should pay ' + str(int(Fraction(addition, F))))
    print()
    number += 1
