#include <iostream>
#include <map>

using namespace std;

int NOD(int a, int p) {
    while (p != 0) {
        int r = a % p;
        a = p;
        p = r;
    }

    return a;
}

int general(int a, int m) {
    int x1 = 1, x2 = 0;

    while (m != 0) {
        int q = a / m;
        int r = a % m;

        int tempx = x1;
        x1 = x2;
        x2 = tempx - q * x2;

        a = m;
        m = r;
    }

    return x1;
}

int main() {
    while (true) {
        int c, m;
        cout << "Введите: c, m: ";

        cin >> c >> m;

        int gcd = NOD(c, m);

        if (gcd != 1) {
            cout << "Решения нет, т.к. gcd(c, m) != 1" << endl;
        }
        else {
            int res = general(c, m);
            cout << "x = " << res << endl;
            if (res < 0) {
                res = (res % m + m) % m;
            }
            cout << "Выражение c*d mod m = 1 при d = " << res << "!" << endl;
        }
        cout << endl;
    }
}