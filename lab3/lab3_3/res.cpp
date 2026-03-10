#include <iostream>
#include <vector>

std::vector<double> a(int k, int n, const std::vector<double>& v) {
	double s;
	std::vector<double> a;

	for (int i = 1; i <= n; ++i) {
		s = 0;
		for (int j = k * (i - 1) + 1; j <= i * k; ++j) {
			s += v[j - 1];
		}
		a.push_back(s);
	}

	return a;
}

std::vector<double> b(int k, int n, const std::vector<double>& v) {
	double max;
	std::vector<double> b;

	for (int i = 1; i <= n; ++i) {
		max = v[k * (i - 1)];
		for (int j = k * (i - 1) + 1; j <= i * k; ++j) {
			if (v[j - 1] > max) {
				max = v[j - 1];
			}
		}
		b.push_back(max);
	}

	return b;
}

double c(int k, int n, const std::vector<double>& v) {
	double min, s{0};

	for (int i = 1; i <= n; ++i) {
		min = v[k * (i - 1)];
		for (int j = k * (i - 1) + 1; j <= i * k; ++j) {
			if (v[j - 1] < min) {
				min = v[j - 1];
			}
		}
		s = s + min;
	}

	return s;
}

double g(int k, int n, const std::vector<double>& v) {
	double max, s;
	std::vector<double> g;

	for (int i = 1; i <= n; ++i) {
		s = 0;
		for (int j = k * (i - 1) + 1; j <= i * k; ++j) {
			s = s + v[j - 1];
		}
		g.push_back(s);
	}

	max = g[0];
	for (double i : g) {
		if (i > max) {
			max = i;
		}
	}

	return max;
}

double d(int k, int n, const std::vector<double>& v) {
	double max, min;
	std::vector<double> d;

	for (int i = 1; i <= n; ++i) {
		max = v[k * (i - 1)];
		for (int j = k * (i - 1) + 1; j <= i * k; ++j) {
			if (v[j - 1] > max) {
				max = v[j - 1];
			}
		}
		d.push_back(max);
	}

	min = d[0];
	for (double i : d) {
		if (i < max) {
			min = i;
		}
	}

	return min;
}

//4 -3 32 0 -4 59 12 54 9 8 3 -3
void calc(int k, int n, const std::vector<double> &v) {
	std::cout << "a) ";
	for (double i: a(k, n, v)) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::cout << "б) ";
	for (double i : b(k, n, v)) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::cout << "в) " << c(k,n,v);
	std::cout << std::endl;

	std::cout << "г) " << g(k, n, v);
	std::cout << std::endl;

	std::cout << "д) " << d(k, n, v);
	std::cout << std::endl;
}

void inp() {
	int k, n, x;
	double y;
	std::vector<int> a;
	std::vector<double> b;

	std::cout << "Введите натуральные k и n через пробел: ";
	while (true) {
		while (std::cin >> x) {
			a.push_back(x);
			if (std::cin.peek() == '\n') {
				break;
			}
		}
		if (std::cin.peek() != '\n' || a.size() != 2 || a[0] <= 0 || a[1] <= 0) {
			a.clear();
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка ввода\nПопробуйте ещё раз: ";
		}
		else { 
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break; 
		}
	}

	k = a[0]; n = a[1]; a.clear(); x = static_cast<double>(x);

	/*for (int i : v) {
		std::cout << i << " " << std::endl;
	}*/

	std::cout << "Введите " << k*n << " действительных чисел через пробел : ";
	while (true) {
		while (std::cin >> y) {
			b.push_back(y);
			if (std::cin.peek() == '\n') {
				break;
			}
		}
		
		if (std::cin.peek() != '\n') {
			b.clear();
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка ввода\nПопробуйте ещё раз: ";
		}
		else if (b.size() != (k * n)) {
			b.clear();
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Неверное количество чисел\nПопробуйте ещё раз: ";
		}
		else { break; }
	}

	calc(k, n, b);
}