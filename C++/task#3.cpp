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

// Расширенный алгоритм Евклида для нахождения обратного элемента: c^(-1) mod m = d
int inverse(int c, int m) {
    int x, y;
    int g = extended_gcd(c, m, x, y);
    if (g != 1) {
        cout << "Обратного элемента не существует!" << endl;
        return -1;
    }
    return (x % m + m) % m;
}

int main() {
    setlocale(LC_ALL, "ru");
    
    cout << endl;

    int c, m;
    cout << "Введите: c, m: ";

    cin >> c >> m;

    int inv = inverse(c, m);
    if (inv != -1) {
        cout << "Обратный элемент для " << c << " по модулю " << m << " равен " << inv << endl;
    }
}