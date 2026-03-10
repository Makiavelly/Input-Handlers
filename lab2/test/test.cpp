#include <iostream>
#include <iomanip>

int main()
{   
    std::cout << std::setprecision(17);
    double a(1);
    do {
        std::cout << a << std::endl;
        ++a;
    } while (a <10);
}

