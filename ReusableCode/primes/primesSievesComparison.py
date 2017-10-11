from math import sqrt
import timeit


# sieve of primes, use dict if you want to save memory
# however using it will make this slower
def sieve(N=100000000):
    n = N + 1
    dic = [0] * (n)
    # dic = {0: 0, 1: 1}
    dic[0] = -1
    dic[1] = 1
    for i in range(4, n, 2):
        dic[i] = 2
    for i in range(9, n, 3):
        dic[i] = 3
    i = 5
    w = 2
    k = i * i
    while k < n:
        # if i not in dic:
        if dic[i] == 0:
            # skip multiples of 2
            jump = 2 * i
            for j in range(k, n, jump):
                dic[j] = i
        i += w
        w = 6 - w
        k = i * i
    return dic


def clasicSieve(N=100000000):
    criba = [0] * (N + 1)
    raiz = int(sqrt(N))
    criba[0] = -1
    criba[1] = 1
    for i in range(4, N + 1, 2):
        criba[i] = 2
    for i in range(3, raiz + 1, 2):
        if (criba[i] == 0):
            for j in range(i * i, N + 1, i):
                if (criba[j] == 0):
                    criba[j] = i
    return criba


if __name__ == '__main__':
    print(timeit.timeit(clasicSieve, number=1))
    print(timeit.timeit(sieve, number=1))
