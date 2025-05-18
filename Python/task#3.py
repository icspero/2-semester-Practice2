def gcd(a, p):
    while p != 0:
        r = a % p
        a = p
        p = r
    return a

def extended(a, m):
    x1, x2 = 1, 0
    y1, y2 = 0, 1

    while m != 0:
        q = a // m
        r = a % m

        tempx = x1
        x1 = x2
        x2 = tempx - q * x2

        tempy = y1
        y1 = y2
        y2 = tempy - q * y2

        a = m
        m = r

    return x1, y1

def main():
    while True:
        c = int(input("Введите c: "))
        m = int(input("Введите m: "))
        
        gcd_val = gcd(c, m)
        if gcd_val != 1:
            print("Решения нет, т.к. gcd(c, m) != 1")
            return
        else:
            x, y = extended(c, m)
            print(f"x = {x}, y = {y}")
            if x < 0:
                x = (x % m + m) % m
            print(f"Обратный элемент для {c} по модулю {m} равен {x}!")
        print()

if __name__ == "__main__":
    main()