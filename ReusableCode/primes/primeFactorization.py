def mySieve(N=10000000):
    n = N + 1
    dic = [0] * (n)
    # dic = {0: 0, 1: 1}
    primes = [2, 3]
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
            primes.append(i)
            # skip multiples of 2
            jump = 2 * i
            for j in range(k, n, jump):
                dic[j] = i
        i += w
        w = 6 - w
        k = i * i
    # if you need primes bigger than the root of N
    while i < n:
        if dic[i] == 0:
            primes.append(i)
        i += w
        w = 6 - w
    return dic, primes


def getPrimeFactors(N, sieveToMaxN):
    n = N
    primeFactors = []
    while n != 1:
        if sieveToMaxN[n] == 0:
            primeFactors.append(n)
            break
        primeFactors.append(sieveToMaxN[n])
        n = n / sieveToMaxN[n]
    return primeFactors


if __name__ == '__main__':
    n = int(input())
    sieve = mySieve(n)[0]
    print(sieve)
    print(getPrimeFactors(n, sieve))
