#include <iostream>
#include <limits>
#include <string>

void ex() {
    double n;
    std::string s;
    bool r{false};

    while (true) {
        std::cout << "Введите натуральное число n: " << std::endl;
        std::cin >> n;

        if (std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода" << std::endl;
        }
        else { 
            if (n == int(n) && n > 0) {
                n = static_cast<const int>(n);
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            std::cout << "n ненатурально, попробуйте ещё раз." << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    while (true) {
        std::cout << "Введите " << n << " симовлов: " << std::endl;
        getline(std::cin, s);

        if (s.length() == n) {
            for (int i = 0; i < n; ++i) {
                if (s[i] == '-') {
                    if (r == true) {
                        break;
                    }
                }
                if (s[i] == ',' && (i+1) != n) {
                    r = true;
                }
                else { r = false; }
            }
            break;
        }
        else { std::cout << "Введено неверное количество символов..." << std::endl; }
    }

    if (r == true) {
        std::cout << "Есть" << std::endl;
    }
    else { std::cout << "Нет" << std::endl; }

}