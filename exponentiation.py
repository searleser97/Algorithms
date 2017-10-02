def main():
    while True:
        try:
            n, r = input().split()
        except:
            break
        r = int(r)
        ndecimals = len(n) - n.find('.') - 1
        ndecimalsAfter = ndecimals * r
        nAux = int(n.replace('.', ''))
        exponentiated = str(nAux**r)
        floatPart = exponentiated[-1 * ndecimalsAfter:]
        intPart = exponentiated[:len(exponentiated) - len(floatPart)]
        zeroesAfterDot = ndecimalsAfter - len(floatPart)
        print(intPart + '.' + '0' * zeroesAfterDot + floatPart.strip('0'))


if __name__ == '__main__':
    main()
