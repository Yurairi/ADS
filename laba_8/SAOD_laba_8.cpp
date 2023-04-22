#include "ListList.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	LinkedList l;
	main_menu(l);
	return 0;
}

void main_menu(LinkedList l) {
	int choise;

	while (true) {
		cout << "Выберете необходимое действие\n";
		cout << "1. Вывести текущее состояние списка\n";
		cout << "2. Добавить элемент в список\n";
		cout << "3. Удалить заданный элемент из списка\n";
		cout << "4. Удалить заданный список\n";
		cout << "5. Проверить пуст ли список\n";
		cout << "6. Проверить наличие элемента в списке\n";
		cout << "0. Завершить работу программы\n";
		cout << "Ввод: ";
		choise = input_for_menu(1);
		if (choise == 1) {
			int r;
			if (!Is_Empty(l)) {
				List_status(l);
			}
			else {
				cout << "Список списков пуст. \n";
			}
		}
		if (choise == 2) {
			Add_node(&l);
		}
		if (choise == 3) {
			if (Is_Empty(l)) cout << "Список списков пуст. \n";
			else {
				Delete_elem_1(&l);
			}
		}
		if (choise == 4) {
			if (Is_Empty(l)) cout << "Список списков пуст. \n";
			else {
				cout << "Введите id списка, который необходимо удалить\n";
				int co = input_for_menu(0);
				Delete_node(&l, co);
			}
		}
		if (choise == 5) {
			if (Is_Empty(l)) cout << "Список списков пуст. \n";
			else cout << "Список списков не пуст. \n";
		}
		if (choise == 6) {
			cout << "Введите значение, которое необходимо найти: ";
			int num = input_for_menu(0);
			if (Finder(l, num, 0)) {
				int r = Finder(l, num, 1);
				r++;
			}
			else cout << "Элемент не найден. \n";
		}
		if (choise == 0) {
			break;
		}
	}
}
