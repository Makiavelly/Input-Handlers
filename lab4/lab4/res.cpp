#include <iostream>
#include <limits>
#include "space.h"
#include <fstream>

enum Ans {
    NO,
    YES
};

enum In_out {
    CONSOLE,
    OUTSIDE
};

bool tf(const char *s);
int atf();
void last(bool r);

void ex() {
    int ans;

    while (true) {
        std::cout << "Откуда вы хотите получить входные данные? Из консоли - 0, из файла - 1: ";
        ans = atf();

        if (ans == CONSOLE) {
            int len{ 2 }, k{ 0 };
            char* s, * er;

            do {
                s = new (std::nothrow) char[len];
            } while (!s);
            std::cout << "Введите последовательность симовлов: ";

            while (true) {
                while (std::cin.peek() != '\n') {
                    if (k == len) {
                        len = len * 2;
                        do {
                            er = new (std::nothrow) char[len];
                        } while (!er);
                        for (int i = 0; i < k; ++i) {
                            er[i] = s[i];
                        }
                        delete[] s;

                        do {
                            s = new (std::nothrow) char[len];
                        } while (!s);
                        for (int i = 0; i < k; ++i) {
                            s[i] = er[i];
                        }
                        delete[] er;
                        er = nullptr;
                    }

                    if (std::cin.peek() == ' ') {
                        s[k] = ' ';
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
                    }
                    else {
                        std::cin >> s[k];
                    }
                    ++k;
                }
                s[k] = '\0';
                if (std::cin.peek() == '\n') {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Введено неверное количество символов...\nПовторите ввод: ";
                }
            }

            last(tf(s));
            delete[] s;
            s = nullptr;

            std::cout << "Желаете повторить ввод? Да - 1, нет - 0: ";
            ans = atf();

            if (ans == YES) {}
            else if (ans == NO) { break; }
        }

        else if (ans == OUTSIDE) {
            char* s, * er;
            int k{ 0 }, len{ 2 };
            do {
                s = new (std::nothrow) char[len];
            } while (!s);

            std::ifstream in;
            in.open(path::in);
            if (in.is_open()) {
                while (in.peek() != -1) {
                    if (k == len) {
                        len = len * 2;
                        do {
                            er = new (std::nothrow) char[len];
                        } while (!er);
                        for (int i = 0; i < k; ++i) {
                            er[i] = s[i];
                        }
                        delete[] s;

                        do {
                            s = new (std::nothrow) char[len];
                        } while (!s);
                        for (int i = 0; i < k; ++i) {
                            s[i] = er[i];
                        }
                        delete[] er;
                        er = nullptr;
                    }

                    if (in.peek() == ' ') {
                        in.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
                        s[k] = ' ';
                    }
                    else {
                        in >> s[k];
                    }
                    k++;
                }

                if (k == len) {
                    len = len + 1;
                    do {
                        er = new (std::nothrow) char[len];
                    } while (!er);
                    for (int i = 0; i < k; ++i) {
                        er[i] = s[i];
                    }
                    delete[] s;

                    do {
                        s = new (std::nothrow) char[len];
                    } while (!s);
                    for (int i = 0; i < k; ++i) {
                        s[i] = er[i];
                    }
                    delete[] er;
                    er = nullptr;
                }
                s[k] = '\0';
            }
            else {
                std::cout << "Файл не найден...";
                exit(0);
            }
            in.close();

            std::cout << "Ваша строчка из файла находится в таком виде: " << s << std::endl;
            last(tf(s));

            delete[] s;
            s = nullptr;

            break;
        }
    }
}

bool tf(const char *s) {
    bool r{ false };

    for (int i = 0; *(s+i) != '\0'; ++i) {
        if (*(s+i) == '-') {
            if (r == true) {
                break;
            }
        }
        if (*(s+i) == ',' && *(s+i + 1) != '\n') {
            r = true;
        }
        else { r = false; }
    }

    return r;
}

int atf() {
    int ans;
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

void last(bool r) {
    int ans;

    std::cout << "Куда хотите получить результат? В консоль - 0, в файл - 1: ";
    ans = atf();

    if (ans == CONSOLE) {
        if (r == true) {
            std::cout << "Условие выполняется" << std::endl;
        }
        else { std::cout << "Условие не выполняется" << std::endl; }
    }
    else if (ans == OUTSIDE) {
        std::ofstream out;
        out.open(path::out);
        if (out.is_open()) {
            if (r == true) {
                out << "Условие выполняется";
            }
            else { out << "Условие не выполняется"; }

        }
        out.close();
        std::cout << "Выполнено" << std::endl;
    }
}