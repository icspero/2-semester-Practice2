# Расширенный алгоритм Евклида
def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = extended_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return g, x, y

# Расширенный алгоритм Евклида для нахождения обратного элемента: c^(-1) mod m = d
def inverse(c, m):
    g, x, y = extended_gcd(c, m)
    if g != 1:
        print("Обратного элемента не существует!")
        return -1
    return (x % m + m) % m

c, m = map(int, input("Введите: c, m: ").split())
inv = inverse(c, m)
if inv != -1:
    print(f"Обратный элемент для {c} по модулю {m} равен {inv}")
