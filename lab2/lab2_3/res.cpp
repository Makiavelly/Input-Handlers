#include <iostream>

void res() {
    int n;
    std::cout << "¬ведите натуральные число n: ";
    std::cin >> n;

    double max, x;
    std::cout << "¬ведите 1 элемент: ";
    std::cin >> x;
    max = x;

    for (int count = 2; count < (n + 1); ++count) {
        std::cout << "¬ведите " << count << " элемент: ";
        std::cin >> x;
        if (max < x) {
            max = x;
            std::cout << "„исло удовлетв. условию: " << x << std::endl;
        }
    }
}
