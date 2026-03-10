#include <iostream>
#include <deque>
#include <vector>
#include "space.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std; 

enum Choice_of {
	SURNAME,
	NAME,
	PATRONYMIC,
	AGE,
	MARITAL_STATUS
};

enum Num_task {
	FIRST,
	SECOND,
	THIRD,
	FOURTH
};

struct Node {
	string sname;
	string name;
	string pat;
	int age;
	string marit;
};

short atf() {
	short ans;
	char in;

	while (true) {
		cin >> in;
		if (cin.peek() == ' ') {
			while (cin.peek() == ' ') cin.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
		}
		if (in != '3' && in != '1' && in != '2' && in != '4' && in != ' ' || std::cin.peek() != '\n') {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Ошибка ввода\nПопробуйте ещё раз: ";
		}
		else {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (in == '1') ans = 0;
			else if (in == '2') ans = 1;
			else if (in == '3') ans = 2;
			else if (in == '4') ans = 3;
			break;
		}
	}

	return ans;
}

void listrecord(deque<struct Node>& d)
{
	vector<string> v;

	ofstream out;
	out.open(path::path);
	if (out.is_open()) {
		for (struct Node& e : d) {
			out << e.sname << " " << e.name << " " << e.pat \
				<< " " << e.age << " " << e.marit << "; " << endl;
		}
	}
	else {
		cout << "Файл не найден..." << endl;
		out.close();
		exit(0);
	}
	out.close();
}

void sorting(deque<struct Node>& d) {
	short ans;

	cout << "Сортировать по:\n1. Фамилии\n2. Имени \n\
3. Отчеству \n4. Возрасту" << endl;
	ans = atf();

	if (ans == SURNAME) {
		sort(d.begin(), d.end(), [](Node a, Node b) {
			return a.sname < b.sname;
			});
	}
	else if (ans == NAME) {
		sort(d.begin(), d.end(), [](Node a, Node b) {
			return a.name < b.name;
			});
	}
	else if (ans == PATRONYMIC) {
		sort(d.begin(), d.end(), [](Node a, Node b) {
			return a.pat < b.pat;
			});
	}
	else if (ans == AGE) {
		sort(d.begin(), d.end(), [](Node a, Node b) {
			return a.age < b.age;
			});
	}
	else if (ans == MARITAL_STATUS) {
		sort(d.begin(), d.end(), [](Node a, Node b) {
			return a.marit < b.marit;
			});
	}

	cout << endl;
	for (struct Node& e : d) {
		cout << e.sname << " " << e.name << " " << e.pat \
			<< " " << e.age << " " << e.marit << "; " << endl;
	}
	cout << endl;
	//listrecord(d);
}

struct Node addelem(vector<string> v) {
	struct Node elem;
	elem.sname = v[0];
	elem.name = v[1];
	elem.pat = v[2];
	stringstream s_flow(v[3]);
	int s;
	s_flow >> s;
	elem.age = s;
	elem.marit = v[4];
	return elem;
}

void zanul(deque<struct Node>& d) {
	
	for (struct Node& e : d) {
		e.sname = "NULL";
		e.name = "NULL";
		e.pat = "NULL";
		e.age = 0; 
		e.marit = "NULL";
	}
	cout << "\nЗануление прошло успешно!" << endl << endl;
	//listrecord(d);
}

void check_occ(deque<struct Node>& d) {
	bool err{ false }, val{false};
	vector<string> v;
	short i{ 0 };
	string s;
	const char* symb;
	

	cout << "Введите эдемент по образцу: Lukov Ivan Palych 10 chenat" << endl;
	while (true) {
		i = 0;
		while (cin.peek() != '\n') {
			
			/*if (cin.peek() == '\n') {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}*/

			cin >> s;
			symb = s.c_str();
			i += 1;
			for (int j = 0; j != s.length(); j++) {
				if (i != 4 && (symb[j] < 65 || (symb[j] > 90 && symb[j] < 97) || symb[j] > 122)) {
					err = true;
				}
				if (i == 4 && (symb[j] < 48 || symb[j] > 57)) {
					err = true;
				}
			}
			v.push_back(s);
			while (cin.peek() == ' ') {
				cin.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
			}
		}

		if (i != 5) {
			cout << "Данные должны содержать ФИО, Возраст, Семейное положение (итого 5 слов, разделённых пробелами)" << endl;
			v.clear();
			err = false;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Повторите попытку: " << endl;
		}
		else if (err) {
			cout << "ФИО и Семейное положение должны содержать только буквы, а Возраст только число..." << endl;
			v.clear();
			err = false;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Повторите попытку: " << endl;
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}

	stringstream s_flow(v[3]);
	int digit;
	s_flow >> digit;

	for (struct Node& e : d) {
		if (e.sname == v[0] && e.name == v[1] && e.pat == v[2]\
			&& e.age == digit && e.marit == v[4]) val = true;
	}

	if (val) {
		cout << "\nЭлемент с такими значениями найден!" << endl << endl;
	}
	else {
		cout << "\nЭлемент с такими значениями не найден..." << endl << endl;
	}
	
}

void ex() {
	string s;
	const char* symb;
	deque<Node> d;

	ifstream in;
	in.open(path::path);
	if (in.is_open()) {
		bool err{ false };
		int i;
		struct list* head{ nullptr };
		struct list* last{ nullptr };
		vector<string> v;

		while (!in.eof()) {
			i = 0;
			if (in.peek() == ' ' || in.peek() == '\n' || in.peek() == -1) {
				if (in.peek() == ' ') {
					while (in.peek() == ' ') in.ignore(numeric_limits<streamsize>::max(), ' ');
				}
				if (in.peek() == '\n') {
					in.ignore(numeric_limits<streamsize>::max(), '\n');
					i = 5;
					continue;
				}
				if (in.peek() == -1) {
					i = 5;
					continue;
				}
			}
			getline(in, s);
			stringstream s_flow(s);
			while (s_flow >> s) {
				symb = s.c_str();
				i += 1;
				for (int j = 0; j != s.length(); j++) {
					if (i != 4 && (symb[j] < 65 || (symb[j] > 90 && symb[j] < 97) || symb[j] > 122)) {
						err = true;
					}
					if (i == 4 && (symb[j] < 48 || symb[j] > 57)) {
						err = true;
					}
				}
				v.push_back(s);

			}

			if (i != 5) {
				cout << "Данные должны содержать ФИО, Возраст, Семейное положение (итого 5 слов, разделённых пробелами)" << endl;
				v.clear();
				in.close();
				exit(0);
			}
			else if (err) {
				cout << "ФИО и Семейное положение должны содержать только буквы, а Возраст только число..." << endl;
				v.clear();
				in.close();
				exit(0);
			}
			else {
				d.push_back(addelem(v));
				v.clear();
			}
		}
		cout << "Данные загружены..." << endl;
		in.close();

		while (true) {
			cout << "Выберите действие:\n1. Проверить: \
входит ли заданный элемент в контейнер?\
\n2. Печать всех элементов в отсортированном виде (например по ФИО)\
\n3. Сброс значений всех элементов (например обнуление)\n4. Выход" << endl;
			short ans;
			ans = atf();
			if (ans == FIRST) {
				if (d.empty()) {
					cout << "\nФайл пуст..." << endl << endl;
					continue;
				}
				check_occ(d);
			}
			else if (ans == SECOND) {
				if (d.empty()) {
					cout << "\nФайл пуст..." << endl << endl;
					continue;
				}
				sorting(d);
			}
			else if (ans == THIRD) {
				if (d.empty()) {
					cout << "\nФайл пуст..." << endl << endl;
					continue;
				}
				zanul(d);
			}
			else if (ans == FOURTH) {
				exit(0);
			}
		}
	}
	else {
		cout << "Файл не найден..." << endl;
		exit(0);
	}
}