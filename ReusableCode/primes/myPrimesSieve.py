

# sieve of primes, use dict if you want to save memory
# however using it will make this slower
def sieve(N=10000000):
    dic = [0] * (N + 1)
    # dic = {0: 0, 1: 1}
    dic[0] = -1
    dic[1] = 1
    for i in range(4, N + 1, 2):
        dic[i] = 2
    for i in range(9, N + 1, 3):
        dic[i] = 3
    i = 5
    w = 2
    k = i * i
    while k <= N:
        # if i not in dic:
        if dic[i] == 0:
            for j in range(k, N + 1, i):
                dic[j] = i
        i += w
        w = 6 - w
        k = i * i
    return dic


def primesToN(N=10000000):
    s = sieve(N)
    primes = []
    for i in range(2, len(s)):
        if s[i] == 0:
            primes.append(i)
    return primes


if __name__ == '__main__':
    for prime in primesToN(int(input())):
        print(prime)
