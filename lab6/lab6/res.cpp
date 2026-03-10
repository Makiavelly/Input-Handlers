#include <iostream>
#include <string>
#include <vector>
#include <sstream>

enum Tasks {
	ONE = 4,
	TWO = 5
};

void check_num_arg(int size) {
	if (size != 5) {
		std::cout << "Введено неверное количество аргументов..." << std::endl;
		exit(0);
	}
}

template <typename T>
T Type_conversion(char num[]) {
	std::stringstream convert(num);
	T convert_num;
	if (convert.peek() == 45 || convert.peek() == 43) {
		std::cout << "Ошибка ввода... Требуется ввести целые беззнаковые числа..." << std::endl;
		exit(0);
	}
	if (!(convert >> convert_num)) {
		std::cout << "Ошибка ввода... Требуется ввести целые беззнаковые числа..." << std::endl;
		exit(0);
	}
	if (convert.peek() != -1){
		std::cout << "Ошибка ввода... Требуется ввести целые беззнаковые числа..." << std::endl;
		exit(0);
	}
	return convert_num;
}
template unsigned long long Type_conversion(char num[]);
template short Type_conversion(char num[]);

void in_binary(unsigned long long digit) {
	std::vector<unsigned short> v;
	unsigned long long d_in_binary;
	d_in_binary = digit;

	while (d_in_binary / 2 != 0) {
		v.push_back(d_in_binary % 2);
		d_in_binary /= 2;
	}
	v.push_back(d_in_binary % 2);
	while (v.size() != 64) v.push_back(0);
	std::reverse(v.begin(), v.end());
	std::cout << "Число " << digit << " в двоичном виде: ";
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i];
		if ((i+1) % 8 == 0) std::cout << " ";
	}
	std::cout << std::endl;
}

void one_task(unsigned long long digit, short one, short two) {
	unsigned long long f_byte, s_byte;
	unsigned long long mask = 0xFF;
	in_binary(digit);

	mask = mask << 8*(one - 1);
	f_byte = mask & digit;
	mask = mask >> 8*(one - 1);
	mask = mask << 8*(two - 1);
	s_byte = mask & digit;
	mask = mask >> 8*(two - 1);
	f_byte = f_byte >> 8 * (one - 1);
	s_byte = s_byte >> 8 * (two - 1);


	if (f_byte == s_byte) {
		std::cout << "Число оcталось прежним: " << digit << std::endl;
	}
	else {
		f_byte = f_byte << 8 * (two - 1);
		mask = ~(mask << 8 * (two - 1));
		digit &= mask;
		digit |= f_byte;
		mask = ~mask;
		mask = mask >> 8 * (two - 1);
		s_byte = s_byte << 8 * (one - 1);
		mask = ~(mask << 8 * (one - 1));
		digit &= mask;
		digit |= s_byte;
		std::cout << "Число было изменено на: " << digit << std::endl;

		in_binary(digit);
	}
}

void two_task(unsigned long long digit, short one, short two) {
	unsigned long long f_bit, s_bit;
	unsigned long long mask = 0x1;
	in_binary(digit);

	mask = mask << one - 1;
	f_bit = mask & digit;
	mask = mask >> one - 1;
	mask = mask << two - 1;
	s_bit = mask & digit;
	mask = mask >> two - 1;

	if ((f_bit >> one - 1) == (s_bit >> two - 1)) {
		std::cout << "Число оcталось прежним: " << digit << std::endl;
	}
	else {
		mask = mask << one - 1;
		digit ^= mask;
		mask = mask >> one - 1;
		mask = mask << two - 1;
		digit ^= mask;
		std::cout << "Число было изменено на: " << digit << std::endl;

		in_binary(digit);
	}
}

void ex(short num_ex, unsigned long long digit, short one, short two) {
	if (num_ex == ONE) {
		if (one > 8 || one < 1 || two > 8 || two < 1) {
			std::cout << "Минимальный номер байта = 1, а максимальный = 8..." << std::endl;
			exit(0);
		}
		if (one == two) {
			std::cout << "Номера байтов должны быть отличными друг от друга..." << std::endl;
			exit(0);
		}
		one_task(digit, one, two);
	}
	else if (num_ex == TWO) {
		if (one > 64 || one < 1 || two > 64 || two < 1) {
			std::cout << "Минимальный номер бита = 1, а максимальный = 64..." << std::endl;
			exit(0);
		}
		if (one == two) {
			std::cout << "Номера байтов должны быть отличными друг от друга..." << std::endl;
			exit(0);
		}
		two_task(digit, one, two);
	}
	else {
		std::cout << "Неверный номер задания (требуется ввести '4' или '5')..." << std::endl;
		exit(0);
	}
}