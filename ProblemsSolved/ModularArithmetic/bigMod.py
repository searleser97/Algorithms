while True:
    try:
        b = int(input())
        p = int(input())
        m = int(input())
    except:
        break
    print(pow(b, p, m))
    try:
        blank = input()
    except:
        break
