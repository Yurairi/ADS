#include "Stack.h"

int main() {
	int perem;
	setlocale(LC_ALL, "Russian");
	stack* fir_stack = init(5);
	stack* sec_stack = init();
	main_menu(fir_stack, sec_stack);
	return 0;
}

void main_menu(stack* fir_stack, stack* sec_stack) {
	int choise;

	while (true) {
		cout << "Выберете необходимое действие\n";
		cout << "1. Вывести текущее состояние стека\n";
		cout << "2. Добавить элемент в начало стека\n";
		cout << "3. Удалить верхний элемент стека\n";
		cout << "4. Добавить несколько произвольных значений в стек\n";
		cout << "5. Вывести состояние вспомогательного стека\n";
		cout << "0. Завершить работу программы\n";
		cout << "Ввод: ";
		choise = input_for_menu(1);
		if (choise == 1) {
			if (Is_empty(fir_stack)) cout << "Стек пуст.\n";
			else {
				cout << "Текущее состояние стека: \n";
				print_state(fir_stack);
			}
		}
		if (choise == 2) {
			int dop_choise;
			cout << "0. Использовать новое значение\n";
			cout << "1. Использовать вершину вспомогательного стека\n";
			cout << "Ввод: ";
			dop_choise = input_for_menu(2);
			if (!dop_choise) {
				cout << "Введите значение, которое необходимо добавить : ";
				int num = input_for_menu(0);
				add_elem(&fir_stack, num);
			}
			else {
				if (Is_empty(sec_stack)) cout << "Вспомогательный стек пуст. Добавление не возможно\n";
				else {
					move_elem(&fir_stack, &sec_stack);
				}
			}
		}
		if (choise == 3) {
			if (Is_empty(fir_stack)) cout << "Стек пуст. Удаление не возможно\n";
			else {
				int dop_choise;
				cout << "0. Окончательно удалить элемент\n";
				cout << "1. Добавить значение в стек удаленных элементов\n";
				cout << "Ввод: ";
				dop_choise = input_for_menu(2);
				if (dop_choise) {
					move_elem(&sec_stack, &fir_stack);
				}
				else {
					delete_elem(&fir_stack);
				}
			}
		}
		if (choise == 4) {
			cout << "Введите количество элементов, которые необходимо добавить : \n";
			int num = input_for_menu(0);
			add_rand_elem(&fir_stack, num);
		}
		if (choise == 5) {
			if (Is_empty(sec_stack)) cout << "Вспомогательный стек пуст.\n";
			else {
				cout << "Текущее состояние вспомогательного стека: \n";
				print_state(sec_stack);
			}
		}
		if (choise == 0) {
			break;
		}
	}
}