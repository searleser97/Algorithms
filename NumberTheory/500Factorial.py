from sys import stdin, stdout
import math


for line in stdin.read().splitlines():
    stdout.write(line + '!' + '\n' + str(math.factorial(int(line))) + '\n')
