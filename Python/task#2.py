# Расширенный алгоритм Евклида
def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = extended_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return g, x, y

# Обобщённый алгоритм Евклида для нахождения d, такого что c * d ≡ 1 (mod m)
def generalized_algorithm(c, m):
    g, x, y = extended_gcd(c, m)
    if g != 1:
        print("Решения нет, т.к. gcd(c, m) != 1")
        return -1
    return (x % m + m) % m  # Положительный остаток

c, m = map(int, input("Введите: c, m: ").split())
inv = generalized_algorithm(c, m)
if inv != -1:
    print(f"Выражение c*d mod m = 1 при d = {inv}")