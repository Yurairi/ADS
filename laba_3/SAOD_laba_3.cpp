#include "dyn_queue.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	dyn_que qu;
	main_menu(qu);
	return 0;
}

void main_menu(dyn_que qu) {
	int choise;

	while (true) {
		cout << "Выберете необходимое действие\n";
		cout << "1. Вывести текущее состояние очереди\n";
		cout << "2. Добавить элемент в конец очереди\n";
		cout << "3. Удалить элемент из начала очереди\n";
		cout << "4. Моделирование работы очереди\n";
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
			char c;
			cin >> c;
			add_elem(&qu, c);
		}
		if (choise == 3) {
			delete_elem(&qu);
		}
		if (choise == 4) {
			modeling(&qu);
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

void modeling(dyn_que* qu) {
	int choice;
	while (1) {
		cout << "Производится моделирование очереди \n";
		Sleep(500);
		if (Is_Empty(*qu)) choice = 1;
		else {
			choice = (rand() % 2 == 0);
		}
		if (choice) {
			int num = rand() % 3;
			char c;
			cout << "Генерация и добавление " << num << " элементов \n";
			Sleep(500);
			for (int i = 0; i < num; i++) {
				c = 65 + rand() % 26;
				add_elem(qu, c);
			}
		}
		else {
			int num = rand() % 3;
			cout << "Удаление " << num << " элементов из очереди \n";
			Sleep(500);
			for (int i = 0; i < num; i++) {
				if (!Is_Empty(*qu)) delete_elem(qu);
			}
		}
		cout << "Состояние очереди: \n";
		queue_status(*qu);
		cout << "Для завершения моделирования нажмите - 0; для продолжения - 1 \n";
		int ch = input_for_menu(2);
		if (!ch) break;
	}
}