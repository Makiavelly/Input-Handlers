#include <iostream>
#include <limits>
#include "space.h"
#include <fstream>
#include <cmath>

enum Ans {
    NO,
    YES
};

enum In_out {
    CONSOLE,
    OUTSIDE
};

int atf();
int num_of_mat(int row, int col, int m);
void sum_pos(int n, int m, double r, const double *b);

void ex() {
    int ans;
    while (true) {
        std::cout << "Откуда вы хотите получить входные данные? Из консоли - 0, из файла - 1: ";
        ans = atf();

        if (ans == CONSOLE) {
            double** a, * b, n, m, r, s{ 0 };
            do {
                a = new (std::nothrow) double* [3];
            } while (!a);

            a[0] = &n; a[1] = &m; a[2] = &r;

            std::cout << "Введите натуральные n, m и дейтсивтельное чилсо r через пробелы: ";
            while (true) {
                for (int i = 0; i < 3; ++i) {
                    std::cin >> *a[i];
                }
                if (std::cin.peek() != '\n' || *a[0] != unsigned int(*a[0]) || *a[1] != unsigned int(*a[1])) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ошибка ввода... Повторите попытку: ";
                }
                else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
            }

            n = *a[0]; m = *a[1]; r = *a[2];
            delete[] a;
            a = nullptr;

            do {
                b = new (std::nothrow) double[n * m];
            } while (!b);

            std::cout << "Заоплните матрицу размера " << n << "*" << m << "(введите " << n * m << " дейстительных чисел через пробелы): ";
            while (true) {
                for (int i = 0; i < n * m; ++i) {
                    std::cin >> b[i];
                }
                if (std::cin.peek() != '\n') {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ошибка ввода... Повторите попытку: ";
                }
                else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
            }

            std::cout << "Ваша матрица имеет следующий вид: " << std::endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    std::cout << b[num_of_mat(i, j, m)] << '\t';
                }
                std::cout << std::endl;
            }

            sum_pos(n, m, r, b);

            delete[] b;
            b = nullptr;

            std::cout << "Желаете повторить ввод? Да - 1, нет - 0: ";
            ans = atf();

            if (ans == YES) {}
            else if (ans == NO) { break; }
        }
        else if (ans == OUTSIDE) {
            double* b, * er, r, numb;
            int k{ 0 }, len{ 2 }, n{ 1 }, m{ 0 }, y{ 0 };
            bool mark{ false };

            do {
                b = new (std::nothrow) double[len];
            } while (!b);

            std::ifstream in;
            in.open(path::in);
            if (in.is_open()) {
                while (in.peek() != -1) {
                    if (k == len) {
                        len = len * 2;
                        do {
                            er = new (std::nothrow) double[len];
                        } while (!er);
                        for (int i = 0; i < k; ++i) {
                            er[i] = b[i];
                        }
                        delete[] b;

                        do {
                            b = new (std::nothrow) double[len];
                        } while (!b);
                        for (int i = 0; i < k; ++i) {
                            b[i] = er[i];
                        }
                        delete[] er;
                        er = nullptr;
                    }

                    if ((in.peek() > 57 || in.peek() < 48) && in.peek() != 45 && in.peek() != 46 && in.peek() != -1 && in.peek() != 32 && in.peek() != 10) {
                        std::cout << std::cin.peek() << std::endl;
                        std::cout << "Ошибка ввода... Измените данные файла и повторите попытку..." << std::endl;
                        exit(0);
                    }

                    if (in.peek() == '\n' && mark) {
                        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        
                        n += 1;
                        if (m == 0) m = y;
                        if (m != y) {
                            std::cout << "Матрица неверная..." << std::endl;
                            exit(0);
                        }
                        y = 0;
                        if (in.peek() == ' ') {
                            while(in.peek() == ' ') in.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
                        }
                        if (in.peek() == '\n') {
                            while ((in.peek() == ' ' || in.peek() == '\n') && in.peek() != -1) {
                                if (in.peek() == ' ') in.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
                                if (in.peek() == '\n') in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            if (in.peek() != -1) {
                                if ((in.peek() > 57 || in.peek() < 48) && in.peek() != 45 && in.peek() != 46 && in.peek() != -1 && in.peek() != 32 && in.peek() != 10) {
                                    std::cout << std::cin.peek() << std::endl;
                                    std::cout << "Ошибка ввода... Измените данные файла и повторите попытку..." << std::endl;
                                    exit(0);
                                }
                                std::cout << "Ошибка... Между строчками матрицы не должно быть пробелов..." << std::endl;
                                exit(0);
                            }
                            else {
                                n -= 1;
                                y = m;
                                break;
                            }
                        }
                    }
                    if (in >> numb) mark = true;
                    b[k] = numb;
                    while (in.peek() == ' ') {
                        in.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
                    }
                    y++;
                    k++;
                }
            }
            else {
                std::cout << "Файл не найден...";
                exit(0);
            }

            if (n == 0) {
                std::cout << "Файл пуст...";
                exit(0);
            }
            
            if (m != y) {
                std::cout << "Матрица неверная...";
                exit(0);
            }
            in.close();

            std::cout << "Ваша матрица имеет следующий вид: " << std::endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    std::cout << b[num_of_mat(i, j, m)] << '\t';
                }
                std::cout << std::endl;
            }

            std::cout << "Введите дейтсивтельное число r: ";
            while (true) {
                std::cin >> r;
                if (std::cin.peek() != '\n') {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ошибка ввода... Повторите попытку: ";
                }
                else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
            }

            sum_pos(n, m, r, b);

            delete[] b;
            b = nullptr;
            break;
        }
    }
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

int num_of_mat(int row, int col, int m) {
    return (row * m) + col;
}

void sum_pos(int n, int m, double r, const double *b) {
    double s{ 0 };
    int ans;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[num_of_mat(i, j, m)] > 0) {
                s += b[num_of_mat(i, j, m)] * pow(r, n - i - 1);
                break;
            }
            else if (j == m - 1) {
                s += 0.5 * pow(r, n - i - 1);
            }
        }
    }

    std::cout << "Куда хотите получить результат? В консоль - 0, в файл - 1: ";
    ans = atf();

    if (ans == CONSOLE) {
        std::cout << "Сумма элементов, удовлетворяющих условию задачи = " << s << std::endl;
    }
    else if (ans == OUTSIDE) {
        std::ofstream out;
        out.open(path::out);
        if (out.is_open()) {
            out << "Сумма элементов, удовлетворяющих условию задачи = " << s;
        }
        out.close();
        std::cout << "Выполнено" << std::endl;
    }
}
