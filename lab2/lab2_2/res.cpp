#include <iostream>
#include <cmath>

void res() 
{
    int n;
    std::cout << "¬ведите натуральные число n: ";
    std::cin >> n;

    double a, s;
    s = 0;

    for (int count = 1; count < (n + 1); ++count) {
        std::cout << "¬ведите " << count << " элемент: ";
        std::cin >> a;
        s += a;
        std::cout << "b" << count << " = " << a / (1 + std::pow(s, 2)) << std::endl;
    }
}