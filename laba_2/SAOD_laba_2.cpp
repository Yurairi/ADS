#include "Stat_queue.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	stat_queue qu;
	main_menu(qu);
	return 0;
}

void main_menu(stat_queue qu) {
	int choise;

	while (true) {
		cout << "Выберете необходимое действие\n";
		cout << "1. Вывести текущее состояние очереди\n";
		cout << "2. Добавить элемент в конец очереди\n";
		cout << "3. Удалить элемент из начала очереди\n";
		cout << "4. Проверить заполнена ли очередь\n";
		cout << "5. Проверить пуста ли очередь\n";
		cout << "0. Завершить работу программы\n";
		cout << "Ввод: ";
		choise = input_for_menu(1);
		if (choise == 1) {
			cout << "Текущее состояние очереди: \n";
			queue_status(qu);
		}
		if (choise == 2) {
			cout << "Введите значение, которое необходимо добавить : ";
			int num = input_for_menu(0);
			add_elem(&qu, num);
		}
		if (choise == 3) {
			delete_elem(&qu);
		}
		if (choise == 4) {
			if (Is_Full(qu)) cout << "Очередь заполнена. \n";
			else cout << "Очередь не заполнена. \n";
		}
		if (choise == 5) {
			if (Is_Empty(qu)) cout << "Очередь пустая. \n";
			else cout << "Очередь не пустая. \n";
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