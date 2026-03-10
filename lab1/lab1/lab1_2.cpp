#include <iostream>
#include <iomanip>


int main() {
	setlocale(LC_ALL, "Russian");
	double x, y, z;
	std::cout << "Введите три числа: "
	std::cin >> x >> y >> z;
	if (x >= y) {
		if (x >= z) {
			std::cout << "Макс. = " << x << std::endl;
		}
		else {
			std::cout << "Макс. = " << z << std::endl;
		}
	else {
		if (y >= z) {
			std::cout << "Макс. = " << y << std::endl;
		}
		else {
			std::cout << "Макс. = " << z << std::endl;
		}
	}
	}
}