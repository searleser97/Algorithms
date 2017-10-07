from random import randrange


def is_prime(p):
    k = 100
    if p & 1 == 0:
        return False
    if p == 3:
        return True
    phi = p - 1
    d = phi
    r = 0
    while (d & 1 == 0):
        d = int(d >> 1)
        r += 1
    for i in range(k):
        a = randrange(2, p - 2)
        exp = pow(a, d, p)
        if (exp == 1 or exp == p - 1):
            continue
        for j in range(r - 1):
            exp = pow(exp, 2, p)
            if exp == 1:
                return False
            if exp == p - 1:
                break
        else:
            return False
    return True


def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        if n & 1 == 0:
            n += 1
        for i in range(n, 5000000000, 2):
            if is_prime(i):
                print(i)
                break


if __name__ == '__main__':
    main()