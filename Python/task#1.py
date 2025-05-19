def NOD(a, p):
    while p != 0:
        r = a % p
        a = p
        p = r
    return a

def mTeoremaFerma(a, p):
    if NOD(a, p) != 1:
        return -1
    s = 1
    for _ in range(p - 1):
        s = (s * a) % p
    if s == 1:
        return 1
    else:
        return 0

def svo_srav(a, x, p):
    left = alg_2(a, x, p) # (a^x) mod p
    a_mod = a % p
    right = alg_2(a_mod, x, p) # ((a mod p)^x) mod p
    return 1 if left == right else -1

def alg_1(a, x, p):
    res = 1
    for _ in range(x):
        res = (res * a) % p
    return res

def alg_2(a, x, p):
    res = 1
    a = a % p
    while x > 0:
        if x % 2 == 1:
            res = (res * a) % p
        a = (a * a) % p
        x //= 2
    return res

def main():
    a, x, p = map(int, input("Введите числа a, x, p через пробел >>>> ").split())

    r1 = mTeoremaFerma(a, p)
    if r1 == 1:
        print("a^(p-1) mod p = 1, следовательно, число p - вероятно простое!")
    elif r1 == -1:
        print("Введенные числа не взаимно простые!")
        return
    else:
        print("a^x mod p != 1, следовательно, число p - СОСТАВНОЕ!")
        return

    r2 = svoSrav(a, x, p)
    if r2 != 1:
        print("Свойство сравнений НЕ выполняется")

    alg1 = alg_1(a, x, p)
    print(f"\nАлгоритм №1 - По правилам модульного умножения: a^x mod p = {alg1}")

    alg2 = alg_2(a, x, p)
    print(f"Алгоритм №2 - Метод бинарного возведения в степень: a^x mod p = {alg2}")

    if alg1 == alg2:
        print("\nДанные совпадают >>>> Алгоритмы работают правильно!")

if __name__ == "__main__":
    main()