#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Алгоритм Евклида(поиск НОД)
int NOD(int a, int p) {
    while (p != 0) { // пока остаток не будет равен 0
        int r = p; // a и r переносят числа
        p = a % p; // после первой итерации берем остаток от предыдущего делителя и остатка
        a = r; // a%b=c >> b%c=d >> c%d=e
    }
    return a; // функция возвращает НОД
}

// Малая теорема Ферма
int mTeoremaFerma(int a, int p) {
    if (NOD(a, p) != 1) {  // проверка на взаимную простоту 
        return -1;
    }
    int s = 1;
    for (int i = 0; i < p - 1; i++) { // a^p-1 mod p
        s = (s * a) % p; // a*(a mod p) = a*a mod p
    }
    if (s == 1) {
        return 1; // p - вероятно простое
    }
    else {
        return 0; // р - составное
    }
}

// Свойство сравнения 
int svoSrav(int a, int x, int p) {
    int b = 1;
    for (int i = 0; i < x; i++) { // a^x mod p = b >> a^x = b mod p
        b = (b * a) % p;
    }
    int c = b % p; // b mod p
    if (b % p == c % p) // сравниваем остатки
        return 1;
    else {
        return -1;
    }
}

// Модульное умножение
int alg_1(int a, int x, int p) {
    int res = 1;
    for (int i = 1; i <= x; i++) {
        res = res * a; // a*(a mod p) = (a*a) mod p
        res = res % p; // сразу берем остаток, избегая переполнения
    }
    return res;
}

// Бинарное возведение в степень
int alg_2(int a, int x, int p) {
    if (mTeoremaFerma(a, p) != 1) {
        return -1;
    }
    int size = log2(x); // вычисляем размер в двоичном виде - 1
    vector<int> ost; // вектор остатков степени
    vector<int> dv; // вектор двоичной записи числа степени
    int temp; // временная переменная
    for (int i = 0; i <= size; i++) {
        temp = alg_1(a, int(pow(2, i)), p);
        ost.push_back(temp); // вычисляем и записываем остаток  
    }

    int d;
    while (x != 0) { // перевод в двоичный вид
        d = x % 2;
        x = x / 2;
        dv.push_back(d);
    }

    int result = 1;
    for (int i = 0; i <= size; i++) {
        result = result * int(pow(ost[i], dv[i]));
        result = result % p;
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "rus");
    int a, x, p;

    cout << "Введите числа a,x,p через пробел >>>> ";
    cin >> a >> x >> p;

    int r1 = mTeoremaFerma(a, p); // проверка р на простоту
    if (r1 == 1) {
        cout << "a^(p-1) mod p = 1, следовательно, число p - вероятно простое!" << endl;
    }
    else if (r1 == -1) {
        cout << "Введенные числа не взаимно простые!" << endl;
        return -1;
    }
    else {
        cout << "a^x mod p != 1, следовательно, число p - СОСТАВНОЕ!" << endl;
        return -1;
    }

    int r2 = svoSrav(a, x, p); // проверка свойства сравнения 
    if (r2 != 1) {
        cout << "Свойство сравнений НЕ выполняется" << endl;
    }

    int alg1 = alg_1(a, x, p);
    cout << "\nАлгоритм №1 - По правилам модульного умножения: a^x mod p = " << alg1 << endl;
    int alg2 = alg_2(a, x, p);
    cout << "Алгоритм №2 - Метод бинарного возведения в степень: a^x mod p = " << alg2 << endl;
    if (alg1 == alg2) {
        cout << "\nДанные совпадают >>>> Алгоритмы работают правильно!" << endl;
    }

    return 0;
}