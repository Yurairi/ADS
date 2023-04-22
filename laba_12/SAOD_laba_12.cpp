#include"search_bin_tree.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	main_menu();
	return 0;
}

void main_menu() {
	int choise;
	branch* tree = nullptr;
	while (true) {
		cout << "Выберете необходимое действие:\n";
		cout << "1. Добавить новый ключ.\n";
		cout << "2. Добавить заданное количество вершин.\n";
		cout << "3. Вывести в порядке ключей.\n";
		cout << "4. Вывести в обратно-симметричном порядкею\n";
		cout << "5. Удалить заданный ключ.\n";
		cout << "6. Вывести счетчик для заданного ключа.\n";
		cout << "0. Завершить работу программы\n";
		cout << "Ввод: ";
		choise = input_for_menu(1);
		if (choise == 1) {
			cout << "Использовать рекурсивный алгоритм - 1, не-рекурсивный- 0: \n";
			int ch = input_for_menu(2);
			cout << "Введите значение: \n";
			int num = input_for_menu(0);
			if (ch) { Add_data_rec(&tree, num, 0); }
			else { Add_data_iter(&tree, num); }

		}
		if (choise == 2) {
			cout << "Введите количество вершин: \n";
			int num = input_for_menu(0);
			Rand_build(&tree, num);
		}
		if (choise == 3) {
			In_order(tree);
		}
		if (choise == 4) {
			Simm_print_2(tree, 0);
		}
		if (choise == 5) {
			cout << "Введите значение: \n";
			int num = input_for_menu(0);
			Remove_key(&tree, num);
		}
		if (choise == 6) {
			cout << "Введите значение для ключа: \n";
			int num = input_for_menu(0);
			branch* temp = Finder(tree, num);
			if (temp == nullptr) { cout << "Данного ключа нет. \n"; }
			else { cout << "Значение счетчика:" << temp->count << "\n"; }
		}
		if (choise == 0) {
			Delete(tree);
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