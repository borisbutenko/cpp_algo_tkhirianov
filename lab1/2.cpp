#include <iostream>
#include <math.h>

/**
 * @see https://en.wikipedia.org/wiki/Hypotenuse
 * @example
 *      input => 3 4
 *      output => 5
 */
int main ()
{
    int x, y;
    std::cin >> x >> y;
    std::cout << sqrt(pow(x, 2) + pow(y, 2)) << std::endl;
    return 0;
}
