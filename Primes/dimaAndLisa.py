from random import randrange


def is_prime(p):
    k = 100
    if p == 2 or p == 3:
        return True
    if p & 1 == 0 or p == 1:
        return False
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
    # it is guaranteed that 'n' is odd
    n = int(input())

    if is_prime(n):
        print(1)
        print(n)
        return

    if is_prime(n - 2):
        print(2)
        print(2, n - 2)
        return

    print(3)
    even = n - 3

    # even = 3 + even - 3
    left = 3
    right = even - 3
    for i in range(int(even / 2) + 1):
        if is_prime(left) and is_prime(right):
            print(str(3) + ' ' + str(left) + ' ' + str(right))
            return
        left += 2
        right -= 2


if __name__ == '__main__':
    main()
