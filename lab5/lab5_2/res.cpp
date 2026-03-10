#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

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

int getSingleIndex(int row, int col, int numberOfColumnsInArray)
{
    return (row * numberOfColumnsInArray) + col;
}

double task(int m, int n, std::vector<double>& v) {
    double max;
    double s{ 0 };

    std::cout << "Ваша матрица: " << std::endl;
    for (int i = 0; i < m; i++) {
        max = v[getSingleIndex(i, 1, n)];
        for (int j = 0; j < n; j++) {
            if (max < v[getSingleIndex(i, j, n)]) max = v[getSingleIndex(i, j, n)];
            std::cout << v[getSingleIndex(i, j, n)] << "\t";
        }
        s += max;
        std::cout << std::endl;
    }
    v.clear();
    return s;
}

void end(double s) {
    bool ans;
    std::string  ofs;

    std::cout << "Куда хотите получить результат? 0 - Консоль, 1 - Файл: ";
    ans = atf();
    if (ans == CONSOLE) {
        std::cout << "Сумма максимальных эелементов строк = " << s << std::endl;
    }
    else if (ans == OUTSIDE) {
        std::cout << "Укажите файл для вывода (если ничего не вводить, то будет использован файл 'out2.txt'): ";
        getline(std::cin, ofs);
        //std::cout << ifs << std::endl;
        if (ofs.length() == 0) ofs = "out2.txt";

        std::ofstream out;
        out.open(ofs);
        if (out.is_open()) {
            out << "Сумма максимальных элементов строк = " << s << std::endl;
            std::cout << "Результат был записан в файл" << std::endl;
            out.close();
        }
    }
}

void ex() {
    bool ans;
    std::string ifs;

    while (true) {
        std::cout << "Откуда хотите подавать данные? 0 - Консоль, 1 - Файл: ";
        ans = atf();

        if (ans == CONSOLE) {
            int n{ 0 }, m{ 0 }, y{ 0 };
            double numb, s;
            std::vector<double> v;


            std::cout << "Введите построчно матрицу (чтобы закончить ввод, два раза нажмите Enter): ";
            while (true) {
                if (std::cin.peek() == '\n') {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                else {
                    m++;
                    y = 0;
                    while (std::cin.peek() != '\n') {
                        y++;
                        std::cin >> numb;
                        v.push_back(numb);
                        if (std::cin.peek() == -1) {
                            std::cout << "Ошибка ввода... Повторите попытку: ";
                            n = 0;
                            m = 0;
                            y = 0;
                            v.clear();
                            break;
                        }
                    }
                    if (n == 0) n = y;

                    if (y != n) {
                        std::cout << "В каждой строке должно быть одинаковое количество элементов... Повторите попытку: ";
                        n = 0;
                        m = 0;
                        v.clear();
                    }
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            }

            s = task(m, n, v);
            end(s);
            std::cout << "Желаете поторить ввод данных? 0 - Нет, 1 - Да: ";
            ans = atf();

            if (ans == NO) break;
            else if (ans == YES);
        }

        else if (ans == OUTSIDE) {
            double numb, s;
            int n{ 0 }, m{ 1 }, y{ 0 };
            std::vector<double> v;
            bool mark{ false };

            std::cout << "Укажите исходный файл (если ничего не вводить, то будет использован файл 'in2.txt'): ";
            getline(std::cin, ifs);
            //std::cout << ifs << std::endl;
            if (ifs.length() == 0) ifs = "in2.txt";

            std::ifstream in;
            in.open(ifs);
            if (in.is_open()) {
                while (in.peek() != -1) {
                    if ((in.peek() > 57 || in.peek() < 48) && in.peek() != 45 && in.peek() != 46 && in.peek() != -1 && in.peek() != 32 && in.peek() != 10) {
                        std::cout << std::cin.peek() << std::endl;
                        std::cout << "Ошибка ввода... Измените данные файла и повторите попытку..." << std::endl;
                        exit(0);
                    }
                   
                    if (in.peek() == '\n' && mark) {
                        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        
                        m += 1;
                        if (n == 0) n = y;
                        if (n != y) {
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
                                m -= 1;
                                y = n;
                                break;
                            }
                        }

                    }
                    if (in >> numb) mark = true;
                    v.push_back(numb);
                    while (in.peek() == ' ') {
                        in.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
                    }
                    y++;
                }
                if (n != y) {
                    std::cout << "Матрица неверная..." << std::endl;
                    exit(0);
                }
                if (n == 0) {
                    std::cout << "Файл пуст..." << std::endl;
                    exit(0);
                }
                in.close();
                s = task(m, n, v);
                end(s);
                
                break;
                
            }
            else {
                std::cout << "Файл не найден";
                exit(0);
            }
        }
    }
}
