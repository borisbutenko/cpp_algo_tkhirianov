#include <iostream>

/**
 * Алгоритм Евклида
 * Необходимо найти НОД двух чисел, используя алгоритм Евклида.
 *
 * Формат входных данных:
 * На вход подаются два натуральных числа, по числу в новой строке.
 *
 * Формат выходных данных:
 * Одно число - НОД входных чисел.
 */

int euclidean_algorithm (int a, int b)
{
    while (a > b) {
        a -= b;
    }
    return (a == b) ? b : euclidean_algorithm(b, a);
}

int main ()
{
    using namespace std;

    int a, b;
    cin >> a >> b;
    cout << euclidean_algorithm(a, b) << endl;

    return 0;
}
