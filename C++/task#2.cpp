#include <iostream>
using namespace std;

// Расширенный алгоритм Евклида
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_gcd(b, a % b, x1, y1);
    
    x = y1;
    y = x1 - (a / b) * y1;

    return d;
}

// Обобщённый алгоритм Евклида для нахождения d, такого что c * d ≡ 1 (mod m)
int generalizedAlgorithm(int c, int m) {
    int x, y;
    int g = extended_gcd(c, m, x, y);
    if (g != 1) {
        cout << "Решения нет, т.к. gcd(c, m) != 1" << endl;
        return -1;
    }
    return (x % m + m) % m; // Положительный остаток
}

int main() {
    setlocale(LC_ALL, "ru");
    
    cout << endl;

    int c, m;
    cout << "Введите: c, m: ";

    cin >> c >> m;

    int inv = generalizedAlgorithm(c, m);
    if (inv != -1) {
        cout << "Выражение c*d mod m = 1 при d = " << inv << endl;
    }
}