while True:
    try:
        n, a = map(int, input().split())
    except:
        break
    limit = n + 1
    ans = 0
    for i in range(1, limit):
        ans += i * a**i
    print(ans)
