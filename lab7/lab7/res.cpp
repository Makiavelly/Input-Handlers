#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "space.h"
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

struct list
{
	vector<string> field;
	struct list* ptr;
};

struct list* init(vector<string> a)
{
	struct list* lst;
	lst = new struct list;
	lst->field = a;
	lst->ptr = lst;
	return(lst);
}

struct list* addelem(list* lst, vector<string> s)
{
	struct list* temp, * p;
	temp = new struct list;
	p = lst->ptr;
	lst->ptr = temp;
	temp->field = s;
	temp->ptr = p;
	return(temp);
}

void listprint(list* lst)
{
	struct list* p;
	vector<string> v;

	p = lst;
	do {
		 v = p->field;
		 for (string s : v) {
			 cout << s << " ";
		 }
		 cout << endl;
		p = p->ptr;
	} while (p != lst);
}

void listrecord(list* lst)
{
	struct list* p;
	vector<string> v;

	ofstream out;
	out.open(path::path);
	if (out.is_open()) {
		p = lst;
		do {
			v = p->field;
			for (string s : v) {
				out << s << " ";
			}
			out << endl;
			p = p->ptr;
		} while (p != lst);
	}
	else {
		cout << "Файл не найден..." << endl;
		exit(0);
	}
	out.close();
}

struct list* deletelem(list* lst, string s, short index)
{
	bool res_search{ true }, first_iter{ true };
	struct list* temp;
	struct list* next;
	next = lst;
	temp = lst;
	for (; next->ptr != lst || first_iter; next = next->ptr) {
		first_iter = false;
	}
	do {
		if (temp->field[index] == s) {
			res_search = false;
			break;
		}
		next = temp;
		temp = temp->ptr;
	} while (temp != lst);
	if (res_search) {
		cout << "Объект не найден..." << endl;
		return lst;
	}
	else {
		cout << "\nНайдены следующие данные:" << endl;
		for (string j : temp->field) {
			cout << j << " ";
		}
		cout << endl << endl;
		cout << "Выполнено!" << endl;
		next->ptr = temp->ptr;
		if (temp == lst) {
			if (temp == temp->ptr) {
				lst = NULL;
			} else	lst = temp->ptr;
		}
		free(temp);
		return(lst);
	}
}

short atf(bool num_fun) {
	short ans;
	char in;

	while (true) {
		cin >> in;
		if (cin.peek() == ' ') {
			while (cin.peek() == ' ') cin.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
		}
		if (in != '3' && in != '1' && in != '2' && in != '4' && in != '5' && in != ' ' || std::cin.peek() != '\n') {
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
			else if (in == '5') {
				if (num_fun == FIRST) {
					cout << "Ошибка ввода\nПопробуйте ещё раз: ";
					continue;
				}
				else if (num_fun == SECOND) ans = 4;
			}
			break;
		}
	}

	return ans;
}

string check_corr(short a) {
	string s;
	char symb;
	bool add{ false };

	if (a != AGE) {
		while (cin.peek() != '\n') {
			if (cin.peek() == ' ' && add) {
				while (cin.peek() == ' ') {
					cin.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
				}
				if (cin.peek() == '\n') {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					return s;
				}
				else {
					cout << "Ошибка ввода... Попробуйте ещё раз: ";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					s.clear();
					add = false;
					continue;
				}
			}
			cin >> symb; add = true;
			if (symb < 65 || (symb > 90 && symb < 97) || symb > 122) {
				cout << "Ошибка ввода... Попробуйте ещё раз: ";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				s.clear();
				add = false;
				continue;
			}
			s += symb;
		}
	}
	else if (a == AGE) {
		while (cin.peek() != '\n') {
			if (cin.peek() == ' ' && add) {
				while (cin.peek() == ' ') {
					cin.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
				}
				if (cin.peek() == '\n') {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					return s;
				}
				else {
					cout << "Ошибка ввода... Попробуйте ещё раз: ";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					s.clear();
					add = false;
					continue;
				}
			}
			cin >> symb; add = true;
			if (symb < 48 || symb > 57) {
				cout << "Ошибка ввода... Попробуйте ещё раз: ";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				s.clear();
				add = false;
				continue;
			}
			s += symb;
		}
	}

	return s;
}

void preset_values(struct list* lst)
{
	short i{ 0 };
	string s;
	const char* symb;
	bool err{ false };
	vector<string> v;

	ifstream in;
	in.open(path::defolt);
	if (in.is_open()) {
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
		}
		in.close();

		if (v.empty()) {
			cout << "\nФайл с данными по умолчанию пуст..." << endl << endl;
		}
		else {
			cout << "\nДанные по умолчанию:" << endl;
			for (int j = 0; j < 5; j++) {
				cout << v[j] << " ";
			}
			cout << endl << endl;

			ifstream in;
			in.open(path::path);
			if (in.is_open()) {
				struct list* temp;
				temp = lst;
				do {
					temp->field = v;
					temp = temp->ptr;
				} while (temp != lst);
				listrecord(lst);
				cout << "Выполенено!" << endl;
			}
			else {
				cout << "Файл не найден..." << endl;
				exit(0);
			}
		}
	}
	else {
		cout << "Файл не найден..." << endl;
		exit(0);
	}
}

struct list* dropout(struct list* head) {
	short ans;
	string s;
	bool return_func{ true };

	cout << "Удаление по:\n1. Фамилии\n2. Имени \n\
3. Отчеству \n4. Возрасту \n5. Семейному положению" << endl;
	ans = atf(SECOND);
	if (ans == SURNAME) {
		cout << "Введите фамилию: ";
		s = check_corr(SURNAME);
		return deletelem(head, s, SURNAME);
	}
	else if (ans == NAME) {
		cout << "Введите имя: ";
		s = check_corr(NAME);
		return deletelem(head, s, NAME);
	}
	else if (ans == PATRONYMIC) {
		cout << "Введите отчество: ";
		s = check_corr(PATRONYMIC);
		return deletelem(head, s, PATRONYMIC);

	}
	else if (ans == AGE) {
		cout << "Введите возраст: ";
		s = check_corr(AGE);
		return deletelem(head, s, AGE);

	}
	else if (ans == MARITAL_STATUS) {
		cout << "Введите семейное положение: ";
		s = check_corr(MARITAL_STATUS);
		return deletelem(head, s, MARITAL_STATUS);

	}

}

void ex() {
	string s;
	const char* symb;


	ifstream in;
	in.open(path::path);
	if (in.is_open()) {
		bool err{ false };
		int i;
		struct list* head{nullptr};
		struct list* last{nullptr};
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
				if (head == nullptr) {
					head = init(v);
					v.clear();
					last = head;
				}
				else {
					last = addelem(last, v);
					v.clear();
				}
			}
		}

		cout << "Данные загружены..." << endl; 
		in.close();

		while (true) {
			cout << "Выберите действие:\n1. Удаление элемента по значению \
(будет удалён первый попавшийся, удовл. критерию)\
\n2. Печать всех элементов (вывод на консоль)\n3. Присвоение всем элементам предустановленных значений\n4. Выход" << endl;
			short ans;
			ans = atf(FIRST);
			if (ans == FIRST) {
				if (head == nullptr) {
					cout << "\nФайл пуст..." << endl << endl;
					continue;
				}
				head = dropout(head);
				if (head == NULL) {
					ofstream in;
					in.open(path::path, ofstream::out | ofstream::trunc);
					if (!in.is_open()) {
						cout << "Файл не найден..." << endl;
						exit(0);
					}
					in.close();
				} else	listrecord(head);

			}
			else if (ans == SECOND) {
				if (head == nullptr) {
					cout << "\nФайл пуст..." << endl << endl;
					continue;
				}
				cout << endl;
				listprint(head);
				cout << endl;
			}
			else if (ans == THIRD) {
				if (head == nullptr) {
					cout << "\nФайл пуст..." << endl << endl;
					continue;
				}
				preset_values(head);
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