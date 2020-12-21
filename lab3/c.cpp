/**
 * Два наименьших и два наибольших элемента
 *
 * Найти суммы двух минимальных и двух максимальных элементов в данном списке натуральных чисел.
 * В данной задаче не следует запоминать все числа в память, в том числе использовать массив или список в явной форме.
 * Поиск двух максимальных и двух минимальных чисел должен производиться однопроходным алгоритмом.
 *
 * Формат входных данных:
 * N - число элементов в массиве (4 < N < 1000000).
 * На следующей строке — N натуральных чисел x: 1 <= x <= 1000000.
 *
 * Формат выходных данных:
 * Через пробел сумма двух минимальных и двух максимальных элементов.
 *
 * TODO: Incomplete solution
 */

#include <iostream>

using namespace std;

const char WHITESPACE = ' ';

int str_to_int (const string str);

int main ()
{
    string count;
    string line;

    getline(cin, count);
    getline(cin, line);

    size_t offset = 0;
    int len = str_to_int(count);
    int i = 0;

    int max_1 = 0, max_2 = 0;
    int min_1 = 0, min_2 = 0;

    while (i < len)
    {
        size_t pos = line.find(WHITESPACE, offset);
        string prev, next;
        int num_1, num_2;

        prev = line.substr(offset, pos - offset);

        offset = pos + 1;
        pos = line.find(WHITESPACE, offset);

        next = i + 1 == len ? prev : line.substr(offset, pos - offset);

        offset = pos + 1;

        num_1 = str_to_int(prev);
        num_2 = str_to_int(next);

        if (num_1 > max_1)
        {
            max_2 = max_1;
            max_1 = num_1;
        }
        else if (num_1 > max_2)
        {
            max_2 = num_1;
        }

        if (num_2 > max_1)
        {
            max_2 = max_1;
            max_1 = num_2;
        }
        else if (num_2 > max_2)
        {
            max_2 = num_2;
        }

        if (i == 0)
        {
            if (num_1 > num_2)
            {
                min_1 = num_2;
                min_2 = num_1;
            }
            else
            {
                min_1 = num_1;
                min_2 = num_2;
            }
        }
        else
        {
            if (num_1 < min_1)
            {
                min_2 = min_1;
                min_1 = num_1;
            }
            else if (num_1 < min_2)
            {
                min_2 = num_1;
            }

            if (num_2 < min_1)
            {
                min_2 = min_1;
                min_1 = num_2;
            }
            else if (num_2 < min_2)
            {
                min_2 = num_2;
            }
        }

        i += 2;
    }

    if (len > 1)
    {
        cout << min_1 + min_2 << ' ' << max_1 + max_2 << endl;
    }
    else {
        cout << min_1 << ' ' << max_1 << endl;
    }

    return 0;
}

int str_to_int (const string str)
{
    return stoi(str);
}
