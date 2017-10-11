from sys import stdin, stdout


def divisorCriteria(n, lim):
    results = []
    for i in range(lim):
        remainder = pow(10, i, n)
        negremainder = remainder - n
        if(remainder <= abs(negremainder)):
            results.append(remainder)
        else:
            results.append(negremainder)
    return results


def testDivisibility(dividend, divisor, divisor_criteria):
    dividend = str(dividend)
    addition = 0
    dividendSize = len(dividend)
    i = dividendSize - 1
    j = 0
    while j < dividendSize:
        addition += int(dividend[i]) * divisor_criteria[j]
        i -= 1
        j += 1
    return addition % divisor == 0


if __name__ == '__main__':
    divisor_criteria = divisorCriteria(11, 1000)
    for dividend in stdin.read().splitlines():
        if dividend == '0':
            break
        if testDivisibility(dividend, 11, divisor_criteria):
            stdout.write(dividend + ' is a multiple of 11.\n')
        else:
            stdout.write(dividend + ' is not a multiple of 11.\n')
