#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void ex() {
	double x, s;
	std::vector<double> a;
	std::vector<double> b(10);

	std::cout << "Введите последовательность чисел через пробел: ";
	while (true) {
		while (std::cin >> x) {
			a.push_back(x);
			if (std::cin.peek() == '\n') {
				break;
			}
		}
		if (std::cin.peek() != '\n') {
			a.clear();
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка ввода\nПопробуйте ещё раз: ";
		}
		else { break; }
	}

	sort(a.begin(), a.end());

	for (double i = 0; i < b.size(); ++i) {
		s = 0;
		for (double j : a) {
			if (j <= 0) {
				continue;
			}
			else if (j > (i + 1)) {
				break;
			}
			else if (i < j && j <= (i + 1)) {
				s = s + j;
			}
		}
		b[i] = s;
	}

	for (double i : b) {
		std::cout << i << " ";
	}
}