#include "DoubleLinkedList.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	DLList l;
	main_menu(l);
	return 0;
}

void main_menu(DLList l) {
	int choise;

	while (true) {
		cout << "Выберете необходимое действие\n";
		cout << "1. Вывести текущее состояние списка\n";
		cout << "2. Добавить элемент в список\n";
		cout << "3. Удалить заданный элемент из списка\n";
		cout << "4. Проверить пуст ли список\n";
		cout << "5. Проверить наличие элемента в списке\n";
		cout << "0. Завершить работу программы\n";
		cout << "Ввод: ";
		choise = input_for_menu(1);
		if (choise == 1) {
			int r;
			if (!Is_Empty(l)) {
				cout << "Вывести список с начала - 0; с конца - 1: \n";
				r = input_for_menu(2);
				cout << "Текущее состояние списка: \n";
				if (!r) { List_status_head(l); }
				else { List_status_tail(l); }
			}
			else {
				cout << "Список пуст. \n";
			}
		}
		if (choise == 2) {
			int fl = 1, ind = 0;
			Node* num_ind = l.head;
			cout << "Введите значение, которое необходимо добавить: \n";
			int num = input_for_menu(0);
			if (!Is_Empty(l)) {
				cout << "Введите значение, после или до которого необходимо добавить: \n";
				int datal = input_for_menu(0);
				if (Finder_head(l, datal) == nullptr) {
					cout << "Такого значения нет. \n";
					fl = 0;
				}
				else {
					cout << "Добавление до - 0; добавление после - 1\n";
					ind = input_for_menu(2);
					num_ind = Finder_head(l, datal);
				}
			}
			if (fl) {
				Add_elem(&l, num, num_ind, ind);
			}
		}
		if (choise == 3) {
			if (Is_Empty(l)) cout << "Список пуст. \n";
			else {
				cout << "Введите значение, которое необходимо удалить: ";
				int num = input_for_menu(0);
				Delete_elem(&l, Finder_head(l, num));
			}
		}
		if (choise == 4) {
			if (Is_Empty(l)) cout << "Список пуст. \n";
			else cout << "Список не пуст. \n";
		}
		if (choise == 5) {
			cout << "Поиск с начала списка - 0; с конца - 1: \n";
			int b = input_for_menu(2);
			cout << "Введите значение, которое необходимо найти : ";
			int num = input_for_menu(0);
			if (!b) {
				if (Finder_head(l, num) != nullptr) {
					Node* i = l.head;
					int co = 1;
					while (i != Finder_head(l, num)) { 
						i = i->next;
						co++; 
					}
					cout << "Элемент найден. Его индекс = " << co << "\n";
				}
				else cout << "Элемент не найден. \n";
			}
			else {
				if (Finder_tail(l, num) != nullptr) {
					Node* i = l.head;
					int co = 1;
					while (i != Finder_tail(l, num)) {
						i = i->next;
						co++; 
					}
					cout << "Элемент найден. Его индекс = " << co << "\n";
				}
				else cout << "Элемент не найден. \n";
			}
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
	if (stat == 1 && (choise > 5 || choise < 0)) {
		cout << "Повторите ввод :" << endl;
		choise = input_for_menu(1);
	}
	if (stat == 2 && choise != 1 && choise != 0) {
		cout << "Повторите ввод :" << endl;
		choise = input_for_menu(2);
	}
	return choise;
}
