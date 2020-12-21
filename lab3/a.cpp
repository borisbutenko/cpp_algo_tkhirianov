/**
 * Через сколько прозвонит будильник
 *
 * Перед экзаменом Петя решил хорошенько выспаться.
 * После криков "Халява, приди!" наш студент лег в кровать и начал заводить будильник.
 * Посчитайте сколько секунд осталось спать до звонка.
 *
 * Формат входных данных:
 * Два времени в формате hh:mm:ss, первое - текущее время, второе - время, на которое завели будильник.
 * Гарантируется, что оба времени корректные.
 *
 * Формат выходных данных:
 * Одно число — количество секунд до звонка.
 *
 * TODO: Incomplete solution
 */

#include <iostream>

using namespace std;

const char DIVIDER = ':';
const int TIME_COUNT = 2;
const int HH = 24;
const int MM = 60;
const int SS = MM;

int get_time (const int i, const string time);

int get_diff (int start, const int end, const int max);

int main ()
{
    string start_time;
    string end_time;

    cin >> start_time >> end_time;

    int start_hh = get_time(0, start_time);
    int end_hh = get_time(0, end_time);

    int start_mm = get_time(start_time.find(DIVIDER) + 1, start_time);
    int end_mm = get_time(end_time.find(DIVIDER) + 1, end_time);

    int start_ss = get_time(start_time.rfind(DIVIDER) + 1, start_time);
    int end_ss = get_time(end_time.rfind(DIVIDER) + 1, end_time);

    int diff_hh = get_diff(start_hh, end_hh, HH);
    int diff_mm = get_diff(start_mm, end_mm, MM);
    int diff_ss = get_diff(start_ss, end_ss, SS);

    cout << diff_hh * 3600 + diff_mm * 60 + diff_ss << endl;

    return 0;
}

int get_time (const int i, const string text)
{
    string time = text.substr(i, TIME_COUNT);
    return stoi(time);
}

int get_diff (int start, const int end, const int max)
{
    int diff = 0;

    while (start != end)
    {
        diff += 1;
        start += 1;

        if (start == max)
        {
            start = 0;
        }
    }

    return diff;
}
