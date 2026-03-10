#include <iostream>
#include <cmath>
#include <iomanip>

void x_calc() {
	std::cout << "Введите число e (точность) > 0: " << std::endl;
	double e;
	std::cin >> e;

	std::cout << std::setprecision(10);
	
	double y0, y1{1};

	do {
		y0 = y1;
		y1 = (y0 + 1) / (y0 + 2);
		std::cout << y0 << " " << y1 << std::endl;
	} while ((std::fabs(y1 - y0)) >= e);

	std::cout << "Первый член, при котором выполняется данное в задаче условие (Yn) = " << y0 << std::endl;
}
