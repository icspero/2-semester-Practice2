#include <iostream>

using namespace std;

int NOD(int a, int p) {
    while (p != 0) {
        int r = a % p;
        a = p;
        p = r;
    }

    return a;
}

pair<int, int> extended(int a, int m) {
    int x1 = 1, x2 = 0;
    int y1 = 0, y2 = 1;

    while (m != 0) {
        int q = a / m;
        int r = a % m;

        int tempx = x1;
        x1 = x2;
        x2 = tempx - q * x2;

        int tempy = y1;
        y1 = y2;
        y2 = tempy - q * y2;

        a = m;
        m = r;
    }

    return {x1, y1};
}

int main() {
    while (true) {
        int c, m;
        cout << "Введите: c, m: ";

        cin >> c >> m;

        int gcd = NOD(c, m);

        if (gcd != 1) {
            cout << "Решения нет, т.к. gcd(c, m) != 1" << endl;
            return -1;
        }
        else {
            pair<int, int> res = extended(c, m);
            int x = res.first;
            int y = res.second;
            cout << "x = " << x << ", y = " << y << endl;
            if (res.first < 0) {
                x = (x % m + m) % m;
            }
            cout << "Обратный элемент для " << c << " по модулю " << m << " равен " << x  << "!" << endl;
        }
        cout << endl;
    }
}