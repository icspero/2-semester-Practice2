import math

# Алгоритм Евклида (поиск НОД)
def NOD(a, p):
    while p != 0:
        a, p = p, a % p
    return a

# Малая теорема Ферма
def mTeoremaFerma(a, p):
    if NOD(a, p) != 1:
        return -1
    s = 1
    for i in range(p - 1):
        s = (s * a) % p
    return 1 if s == 1 else 0

# Свойство сравнения
def svoSrav(a, x, p):
    b = 1
    for i in range(x):
        b = (b * a) % p
    c = b % p
    return 1 if b % p == c % p else -1

# Модульное умножение
def alg_1(a, x, p):
    res = 1
    for i in range(x):
        res = (res * a) % p
    return res

# Бинарное возведение в степень
def alg_2(a, x, p):
    if mTeoremaFerma(a, p) != 1:
        return -1

    size = int(math.log2(x))
    ost = [alg_1(a, 2**i, p) for i in range(size + 1)]
    dv = []
    while x != 0:
        dv.append(x % 2)
        x //= 2

    result = 1
    for i in range(size + 1):
        result = (result * pow(ost[i], dv[i])) % p

    return result


a = int(input("Введите число a: "))
x = int(input("Введите число x: "))
p = int(input("Введите число p: "))

r1 = mTeoremaFerma(a, p)
if r1 == 1:
    print("a^(p-1) mod p = 1, следовательно, число p - вероятно простое!")
elif r1 == -1:
    print("Введенные числа не взаимно простые!")
else:
    print("a^x mod p != 1, следовательно, число p - СОСТАВНОЕ!")

r2 = svoSrav(a, x, p)
if r2 != 1:
    print("Свойство сравнений НЕ выполняется")

alg1 = alg_1(a, x, p)
print(f"\nАлгоритм №1 - По правилам модульного умножения: a^x mod p = {alg1}")
alg2 = alg_2(a, x, p)
print(f"Алгоритм №2 - Метод бинарного возведения в степень: a^x mod p = {alg2}")
if alg1 == alg2:
    print("\nДанные совпадают >>>> Алгоритмы работают правильно!")