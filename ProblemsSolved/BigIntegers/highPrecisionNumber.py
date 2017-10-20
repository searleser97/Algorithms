ngroups = int(input())

for i in range(ngroups):
    bef = '0.0'
    while True:
        act = input()
        if act == '0':
            break
        if act.find('.') == -1:
            act += '.0'
        nDecAct = len(act) - act.find('.') - 1
        nDecBef = len(bef) - bef.find('.') - 1
        decimalsAfter = max(nDecBef, nDecAct)
        zeroesToContatBef = decimalsAfter - nDecBef
        zeroesToContatAct = decimalsAfter - nDecAct
        bef += '0' * zeroesToContatBef
        act += '0' * zeroesToContatAct
        bef = bef.replace('.', '')
        act = act.replace('.', '')
        addition = str(int(bef) + int(act))

        floatPart = addition[-1 * decimalsAfter:]
        floatPart = '0' * (decimalsAfter - len(floatPart)) + floatPart
        intPart = addition[:-1 * decimalsAfter]

        if intPart == '':
            intPart = '0'
        bef = intPart + '.' + floatPart
    print(bef.rstrip('0').rstrip('.'))
