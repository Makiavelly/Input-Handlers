#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

enum Ans {
	NO,
	YES
};

enum In_out {
	CONSOLE,
	OUTSIDE
};

bool atf() {
    bool ans;
    char in;

    while (true) {
        std::cin >> in;
        if (in != '0' && in != '1' || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода\nПопробуйте ещё раз: ";
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (in == '0') ans = 0;
            else if (in == '1') ans = 1;
            break;
        }
    }

    return ans;
}


void task(int n, std::string& s) {

    for (int i = 0; i < n / 2; i++) {
        if (s[i] == ':') s[i] = ',';
    }
    if (n % 2 == 0) {
        for (int i = n / 2; i < n; i++) {
            if (s[i] == '!') s[i] = '.';
        }
    }
    else {
        for (int i = n / 2 + 1; i < n; i++) {
            if (s[i] == '!') s[i] = '.';
        }
    }
}

void end(std::string& s) {
    bool ans;
    std::string  ofs;

    std::cout << "Куда хотите получить результат? 0 - Консоль, 1 - Файл: ";
    ans = atf();
    if (ans == CONSOLE) {
        std::cout << "Модифицированная строка: " << s << std::endl;
    }
    else if (ans == OUTSIDE) {
        std::cout << "Укажите файл для вывода (если ничего не вводить, то будет использован файл 'out1.txt'): ";
        getline(std::cin, ofs);
        //std::cout << ifs << std::endl;
        if (ofs.length() == 0) ofs = "out1.txt";

        std::ofstream out;
        out.open(ofs);
        if (out.is_open()) {
            out << "Модифицированная строка: " << s;
            std::cout << "Результат был записан в файл" << std::endl;
            out.close();
        }
    }
    s.clear();
}

void ex() {
	bool ans;
    int n;
    char check_zero;
    std::string s, ifs;

    while (true) {
        std::cout << "Откуда хотите подавать данные? 0 - Консоль, 1 - Файл: ";
        ans = atf();

        if (ans == CONSOLE) {
            /*std::cout << "Введите количество символов n: ";
            while (true) {
                std::cin >> check_zero;
                if (check_zero < 48 || check_zero > 57 || check_zero == 48 && s.length() == 0 || std::cin.peek() == ' ') {
                    std::cout << "Ошибка ввода... Повторите попытку: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    s.clear();
                }
                else if (std::cin.peek() != '\n') {
                    s += check_zero;
                }
                else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    s += check_zero;
                    break;
                }
            }*/
            //n = std::stoi(s);

            std::cout << "Введите последовательность символов: ";
            getline(std::cin, s);
            n = s.length();

            task(n, s);
            end(s);
            
            std::cout << "Желаете поторить ввод данных? 0 - Нет, 1 - Да: ";
            ans = atf();

            if (ans == NO) break;
            else if (ans == YES);
        }

        else if (ans == OUTSIDE) {
            bool chck{ false };
            const char* symb;
            int z{ 0 };

            std::cout << "Укажите исходный файл (если ничего не вводить, то будет использован файл 'in1.txt'): ";
            
            getline(std::cin, ifs);
            //std::cout << ifs << std::endl;
            if (ifs.length() == 0) ifs = "in1.txt";

            std::ifstream in;
            in.open(ifs);
            if (in.is_open()) {

                while (!in.eof()) {
                    getline(in, s);
                    symb = s.c_str();
                    for (int i = 0; i != s.length(); i++) {
                        if (symb[i] != ' ' && symb[i] != '\n') {
                            chck = true;
                            break;
                        }
                    }
                    if (chck) break;
                }
                
                if (!chck) {
                    std::cout << "Файл пуст" << std::endl;
                    exit(0);
                }
                n = s.length();
                std::cout << "Строка была успешно считана из файла: " << s << std::endl;
                task(n, s);
                end(s);
                in.close();
                break;
            }
            else {
                std::cout << "Файл не найден";
                exit(0);
            }
        }
    }
}
