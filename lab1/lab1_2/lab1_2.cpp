#include <iostream>


int main() {
	setlocale(LC_ALL, "Russian");
	double x, y, z;
	std::cout << "Введите три числа: ";
	std::cin >> x >> y >> z;

	if (x >= y) {
		if (x >= z) {
			std::cout << "Макс. = " << x << std::endl;
			if (y >= z) {
				std::cout << "Мин. = " << z << std::endl;
			}
			else {
				std::cout << "Мин. = " << y << std::endl;
			}
		}
		else {
			std::cout << "Макс. = " << z << std::endl;
			std::cout << "Мин. = " << y << std::endl;
		}
	}
	else {
		if (y >= z) {
			std::cout << "Макс. = " << y << std::endl;
			if (x >= z) {
				std::cout << "Мин. = " << z << std::endl;
			}
			else {
				std::cout << "Мин. = " << x << std::endl;
			}
		}
		else {
			std::cout << "Макс. = " << z << std::endl;
			std::cout << "Мин. = " << x << std::endl;
		}
	}
}