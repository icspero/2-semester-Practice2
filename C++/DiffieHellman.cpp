#include <iostream>
#include <random>
using namespace std;

int powmod(int a, int x, int p) {
    int res = 1;
    for (int i = 1; i <= x; i++) {
        res = res * a;
        res = res % p;
    }
    return res;
}

string encoder(string message, int key) {
    string encrypted = "";
    for (char c : message) {
        encrypted += c ^ key;
    }
    return encrypted;
}

string decoder(string message, int key) {
    string decrypted = "";
    for (char c : message) {
        decrypted += c ^ key;
    }
    return decrypted;
}

vector<int> sieveEratosthenes(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    
    is_prime[0] = is_prime[1] = false; // 0 и 1 не являются простыми
    
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false; // отмечаем все кратные i как составные
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

int main() {

    int n1 = 100;
    int n2 = 50;
    vector<int> primes = sieveEratosthenes(n1);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist1(0, primes.size() - 1);

    int p = primes[dist1(gen)];
    int g = 3;

    cout << "g = " << g << "; " << "p = " << p << endl;

    uniform_int_distribution<> dist2(1, n2);

    int a = dist2(gen);
    int b = dist2(gen);

    cout << "Private key a = " << a << endl;
    cout << "Private key b = " << b << endl;

    int A = powmod(g, a, p);
    int B = powmod(g, b, p);

    cout << "Public key A = " << A << endl;
    cout << "Public key B = " << B << endl;

    int sA = powmod(B, a, p);
    int sB = powmod(A, b, p);

    cout << "Shared secret key sA = " << sA << endl;
    cout << "Shared secret key sB = " << sB << endl;

    string message = "Hello World!";
    string encrypted = encoder(message, sA);
    cout << "Message: "  << message << endl;
    cout << "Encrypted data with sA: " << encrypted << endl;

    string decrypted = decoder(encrypted, sB);
    cout << "Decrypted data with sB: " << decrypted << endl;
}



