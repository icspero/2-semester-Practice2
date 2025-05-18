def gcd(a, p):
    while p != 0:
        r = a % p
        a = p
        p = r
    return a

def general(a, m):
    x1, x2 = 1, 0
    while m != 0:
        q = a // m
        r = a % m

        tempx = x1
        x1 = x2
        x2 = tempx - q * x2

        a = m
        m = r
    return x1

def main():
    while True:
        c = int(input("Введите c: "))
        m = int(input("Введите m: "))

        gcd_val = gcd(c, m)
        if gcd_val != 1:
            print("Решения нет, т.к. gcd(c, m) != 1")
        else:
            res = general(c, m)
            print(f"x = {res}")
            res = (res % m + m) % m
            print(f"Выражение c*d mod m = 1 при d = {res}!")

        print()

if __name__ == "__main__":
    main()
