#include <iostream>

/**
 * Тест простоты числа
 * Выяснить, является ли заданное число простым.
 *
 * Формат входных данных:
 * На вход подается натуральное число.
 *
 * Формат выходных данных:
 * Вывести 1 - число простое, 0 - число составное.
 */

int main ()
{
    using namespace std;

    int num;
    bool flag = false;

    cin >> num;

    if (num != 1) {
        int d = 2;

        while (num % d != 0) {
            d += 1;
        }

        flag = (num == d);
    }

    cout << flag << endl;

    return 0;
}
