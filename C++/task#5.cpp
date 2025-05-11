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
    int res = 1, k = 0, t;
    for (int i = 0; i < 8; i++) {
        res = res * a;
        res = res % 10;
        if (k == 0) {
            ost.push_back(res);
            k = 1;
        }
        t = 0;
        for (int j = 0; j < ost.size(); j++) {
            if (ost[j] == res) {
                t = 1;
            }
        }
        if (t != 1) {
            ost.push_back(res);
        }
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