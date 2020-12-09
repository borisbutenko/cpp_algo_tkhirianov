#include <iostream>

/**
 * Високосный год
 * Требуется определить, является ли данный год високосным.
 * (Год является високосным, если его номер кратен 4, но не кратен 100, а также если он кратен 400).
 *
 * Формат входных данных:
 * На вход подается натуральное число N - номер года (0 < N < 100000).
 *
 * Формат выходных данных:
 * Вывести YES если год високосный и NO в противном случае.
 */

bool is_multiplicity (int target_num, int multiplicity_num)
{
    return target_num % multiplicity_num == 0;
}

int main ()
{
    using namespace std;

    int year;
    cin >> year;

    if ((is_multiplicity(year, 4) && !is_multiplicity(year, 100)) || is_multiplicity(year, 400)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    cout << endl;
    return 0;
}
