from numba import jit

'''
the problem is to find the kth smallest number in the multiplication table (n rows, m columns)
for k = 9 the answer is 5
to solve it:
the idea is to guess a number between 1 and n * m, lets call this number mid and
count the numbers up to mid (including repetitions) with the following conditions:
// every number below mid / m_i will be bigger than mid, so:
    if mid / m_i( = 1,2,...,m) = maxNumberReachedPerColumn > n, then
        count += n
    else
        count += maxNumberReachedPerColumn
now that we have the count of numbers lesser than mid
we check:
    if (count < k)
        we discard left
        left = mid + 1
    else
        we discard right
        right = mid - 1
we do this until left > right
now the answer is left, since right will be always one below the correct answer
(Binary Search)
'''
@jit
def main():
    n, m, k = map(int, input().split())

    lf = 1
    r = n * m

    while lf <= r:
        mid = int((lf + r) / 2)
        count = 0
        limit = m + 1
        for i in range(1, limit):
            maxInColumn = int(mid / i)
            if maxInColumn > n:
                count += n
            else:
                count += maxInColumn
        if count < k:
            lf = mid + 1
        else:
            r = mid - 1

    print(int(lf))


if __name__ == "__main__":
    main()
