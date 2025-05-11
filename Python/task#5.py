# Функция для вычисления степени по модулю
def powmod(a, x, p):
    res = 1
    for _ in range(x):
        res = res * a
        res = res % p
    return res

# Функция для нахождения цикла последних цифр степеней числа a
def cycle(a):
    ost = []
    res = 1
    k = 0
    for _ in range(8):
        res = res * a
        res = res % 10
        if k == 0:
            ost.append(res)
            k = 1
        t = 0
        for val in ost:
            if val == res:
                t = 1
        if t != 1:
            ost.append(res)
    return ost

a, b, c = map(int, input("Введите a, b, c: ").split())

res = cycle(a)
temp = powmod(b, c, len(res))

if temp == 0:
    last = res[-1]
else:
    last = res[temp - 1]

print(f"Последняя цифра 'трёхэтажного числа' = {last}")