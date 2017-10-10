

# sieve of primes, use dict if you want to save memory
# however using it will make this slower
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
            for j in range(k, n, i):
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


if __name__ == '__main__':
    for prime in mySieve(int(input()))[1]:
        print(prime)
