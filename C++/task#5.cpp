#include <iostream>
#include <vector>

using namespace std;

int powmod(int a, int x, int p) {
    int res = 1;
    for (int i = 0; i < x; i++) {
        res = res * a;
        res = res % p;
    }
    return res;
}

vector<int> cycle(int a) {
    vector<int> ost;
    int res = 1;

    while (true) {
        res = (res * a) % 10;

        // Проверяем, есть ли уже res в ost
        bool found = false;
        for (int val : ost) {
            if (val == res) {
                found = true;
                break;
            }
        }

        if (found) {
            // Цикл найден, прерываем цикл
            break;
        }

        ost.push_back(res);
    }

    return ost;
}

int main() {
    int a, b, c;

    cout << "Введите a, b, c: ";
    cin >> a >> b >> c;
    
    vector<int> res = cycle(a);

    int temp = powmod(b, c, res.size());

    int last;

    if (temp == 0) {
        last = res.back();
    } else {
        last = res[temp - 1];
    }

    cout << "Последняя цифра 'трёхэтажного числа' = "<< last << endl;
}