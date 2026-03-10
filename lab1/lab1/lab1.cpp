#include <iostream>
#include <cmath>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Russian");
	double a, b;
	std::cout << "Привет, дорогой друг! Введи, пожалуйста два положительных числа: " << std::endl;
	std::cin >> a >> b;
	std::cout << "Среднее арифм. = " << double (a+b)/2 << " Среднее геом. = " << std::sqrt(a*b) << "\n";
}
