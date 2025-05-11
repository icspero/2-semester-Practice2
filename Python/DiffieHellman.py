import random

# Функция для вычисления степени по модулю
def powmod(a, x, p):
    res = 1
    for i in range(1, x + 1):
        res = res * a
        res = res % p
    return res

# Функция шифрования
def encoder(message, key):
    encrypted = ""
    for c in message:
        encrypted += chr(ord(c) ^ key)
    return encrypted

# Функция расшифровки
def decoder(message, key):
    decrypted = ""
    for c in message:
        decrypted += chr(ord(c) ^ key)
    return decrypted

# Решето Эратосфена для нахождения простых чисел до n
def sieveEratosthenes(n):
    is_prime = [True] * (n + 1)
    primes = []
    
    is_prime[0] = is_prime[1] = False  # 0 и 1 не являются простыми
    
    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False  # отмечаем все кратные i как составные
    
    for i in range(2, n + 1):
        if is_prime[i]:
            primes.append(i)
    
    return primes

n1 = 100
n2 = 50
primes = sieveEratosthenes(n1)

# Генератор случайных чисел
random.seed()
dist1 = random.randint(0, len(primes) - 1)

p = primes[dist1]
g = 3

print(f"g = {g}; p = {p}")

a = random.randint(1, n2)
b = random.randint(1, n2)

print(f"Private key a = {a}")
print(f"Private key b = {b}")

A = powmod(g, a, p)
B = powmod(g, b, p)

print(f"Public key A = {A}")
print(f"Public key B = {B}")

sA = powmod(B, a, p)
sB = powmod(A, b, p)

print(f"Shared secret key sA = {sA}")
print(f"Shared secret key sB = {sB}")

message = "Hello World!"
encrypted = encoder(message, sA)
print(f"Message: {message}")
print(f"Encrypted data with sA: {encrypted}")

decrypted = decoder(encrypted, sB)
print(f"Decrypted data with sB: {decrypted}")