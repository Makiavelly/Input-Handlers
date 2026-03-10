#include <iostream>
#include <cmath>

double calc_s(double x1, double y1, double x2, double y2, double x3, double y3) {
	double s = fabs(((x1-x3) * (y2-y3) - (y1-y3) * (x2-x3))) / 2.0;
	return s;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double x1, x2, x3, y1, y2, y3;
	std::cout << "Введите координаты  числа (x1, y1, x2, y2, x3, y3): ";
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	std::cout << "Точки имеют следущие координаты: (" << x1 << " " << y1 << "), (" << x2 << " " << y2 << "), (" << x3 << " " << y3 << ")" << std::endl;
	
	double s, s1, s2, s3;
	s1 = calc_s(x1, y1, x2, y2, 0, 0);
	s2 = calc_s(x1, y1, x3, y3, 0, 0);
	s3 = calc_s(x2, y2, x3, y3, 0, 0);
	s = calc_s(x1, y1, x2, y2, x3, y3);

	if (s == s1 + s2 + s3) {
		std::cout << "Принадлежит!" << std::endl;
	}
	else {
		std::cout << "Не принадлежит." << std::endl;
	}
}

