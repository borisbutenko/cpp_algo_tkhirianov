/**
 * Вавилонская система счисления
 * @see https://en.wikipedia.org/wiki/Sexagesimal
 *
 * В вавилонской системе счисления для записи чисел внутри 60-ричного разряда использовались всего два знака:
 * стоячий клин "v" (латинская строчная v) для обозначения единиц
 * и лежачий клин "<" (знак строго меньше) для обозначения десятков.
 *
 * Для формирования разряда сначала выписывалось количество десятков, а затем количество единиц.
 * Разряды вавилоняне разделяли пустым пространством, однако мы будем использовать для этого точку ".".
 * Если какой-то разряд отсутствовал, на его месте ничего не писалось.
 * Вам требуется записать поданное на вход число в вавилонской системе.
 *
 * Формат входных данных:
 * Натуральное число, записанное в десятичной системе счисления.
 *
 * Формат выходных данных:
 * Вавилонская запись числа.
 */

#include <iostream>
#include <string>
#include <list>

using namespace std;

const int NUMBER_SYSTEM = 60;

int char_to_int (const char ch)
{
    return int(ch - '0');
}

string get_wedges (int count, char wedge /* available list<char> => { 'v', '<', '.' } */)
{
    string result = "";
    int i = count;

    while (i--) {
        result += wedge;
    }

    return result;
}

string get_babylonian_str (int num)
{
    string num_as_str = to_string(num);
    string result = "";

    if (num_as_str.length() > 1) {
        result += get_wedges(char_to_int(num_as_str[0]), '<');
        result += get_wedges(char_to_int(num_as_str[1]), 'v');
    } else {
        result += get_wedges(char_to_int(num_as_str[0]), 'v');
    }

    return result;
}

string convert_to_babylonian (int target)
{
    list<int> nums = { target % NUMBER_SYSTEM };
    string result = "";

    while (target / NUMBER_SYSTEM > 0) {
        target /= NUMBER_SYSTEM;
        nums.push_front(target % NUMBER_SYSTEM);
    }

    for (int num : nums) {
        result += get_babylonian_str(num);
        result += '.';
    }

    result.pop_back();
    return result;
}

int main ()
{
    int num;

    cin >> num;
    cout << convert_to_babylonian(num) << endl;

    return 0;
}
