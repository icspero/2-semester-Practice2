def powmod(a, x, p):
    res = 1
    for _ in range(x):
        res = (res * a) % p
    return res

def cycle(a):
    ost = []
    res = 1
    while True:
        res = (res * a) % 10
        if res in ost:
            break
        ost.append(res)
    return ost

def main():
    a = int(input("Введите a: "))
    b = int(input("Введите b: "))
    c = int(input("Введите c: "))

    res = cycle(a)
    temp = powmod(b, c, len(res))

    if temp == 0:
        last = res[-1]
    else:
        last = res[temp - 1]

    print("Последняя цифра 'трёхэтажного числа' =", last)

if __name__ == "__main__":
    main()