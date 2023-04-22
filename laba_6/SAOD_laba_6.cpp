#include "LinkedList.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	LinkedList l;
	LinkedList extr;
	main_menu(l, extr);
	return 0;
}

void main_menu(LinkedList l, LinkedList extr) {
	int choise;

	while (true) {
		cout << "Выберете необходимое действие\n";
		cout << "1. Вывести текущее состояние главного списка\n";
		cout << "2. Добавить элемент в список\n";
		cout << "3. Удалить заданный элемент из списка\n";
		cout << "4. Вывести текущее состояние вспомогательного списка\n";
		cout << "5. Проверить пуст ли список\n";
		cout << "6. Проверить наличие элемента в списке\n";
		cout << "0. Завершить работу программы\n";
		cout << "Ввод: ";
		choise = input_for_menu(1);
		if (choise == 1) {
			cout << "Текущее состояние списка: \n";
			List_status(l);
		}
		if (choise == 2) {
			int fl = 1, ind = 0;
			Node* num_ind = l.head;
			cout << "Введите значение, которое необходимо добавить: \n";
			int num = input_for_menu(0);
			if (!Is_Empty(l)) {
				cout << "Введите значение, после или до которого необходимо добавить: \n";
				int datal = input_for_menu(0);
				if (Finder(l, datal) == nullptr) {
					cout << "Такого значения нет: \n";
					fl = 0;
				}
				else {
					cout << "Добавление до - 0; добавление после - 1\n";
					ind = input_for_menu(2);
					num_ind = Finder(l, datal);
				}
			}
			if (fl) {
				Add_elem(&l, num, num_ind, ind);
			}
		}
		if (choise == 3) {
			if (Is_Empty(l)) cout << "Список пуст. \n";
			else {
				cout << "Удалить элемент - 0; переместить его в вспомогательный список - 1: ";
				int ch = input_for_menu(2);
				if (ch) {
					cout << "Введите значение, которое необходимо переместить: ";
					int num = input_for_menu(0);
					Move_elem(&l, &extr, Finder(l, num));
				}
				else {
					cout << "Введите значение, которое необходимо удалить: ";
					int num = input_for_menu(0);
					Delete_elem(&l, Finder(l, num));
				}
			}
		}
		if (choise == 4) {
			cout << "Текущее состояние списка: \n";
			List_status(extr);
		}
		if (choise == 5) {
			if (Is_Empty(l)) cout << "Список пуст. \n";
			else cout << "Список не пуст. \n";
		}
		if (choise == 6) {
			cout << "Введите значение, которое необходимо найти : ";
			int num = input_for_menu(0);
			if (Finder(l, num) != nullptr) {
				Node* i = l.head;
				int co = 0;
				while (i != Finder(l, num)) { co++; }
				cout << "Элемент найден. Его индекс = " << co << "\n";
			}
			else cout << "Элемент не найден. \n";
		}
		if (choise == 0) {
			break;
		}
	}
}

int input_for_menu(int stat) {
	int choise;
	while (!(cin >> choise))
	{
		cin.clear();
		while (cin.get() != '\n') {
			cout << "Повторите ввод :" << endl;
		}
	}
	if (stat == 1 && (choise > 6 || choise < 0)) {
		cout << "Повторите ввод :" << endl;
		choise = input_for_menu(1);
	}
	if (stat == 2 && choise != 1 && choise != 0) {
		cout << "Повторите ввод :" << endl;
		choise = input_for_menu(2);
	}
	return choise;
}
