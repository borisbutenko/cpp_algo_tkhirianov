/**
 * Генерация n-го простого числа
 *
 * Необходимо написать функцию prime(n), генерирующую n-ое простое число, где n - натуральное.
 * Первым простым числом является 2, вторым - 3, третьим - 5 и так далее.
 *
 * Формат входных данных:
 * Натуральное число - n
 *
 * Формат выходных данных:
 * n-ое простое число
 */

#include <iostream>

using namespace std;

int is_prime (int num)
{
    bool flag = false;

    if (num != 1) {
        int d = 2;

        while (num % d != 0) {
            d += 1;
        }

        flag = (num == d);
    }

    return flag;
}

int prime (int num, int start = 2)
{
    if (num == 1)
    {
        return start;
    }

    int _num = num - 1;
    int _start = start + 1;

    while (true)
    {
        if (is_prime(_start))
        {
            break;
        }
        _start += 1;
    }

    return prime(_num, _start);
}

int main ()
{
    int num;
    cin >> num;
    cout << prime(num) << endl;
    return 0;
}
