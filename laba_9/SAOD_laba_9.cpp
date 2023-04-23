#include "Bin_tree.h"

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
		cout << "Выберете необходимое действие\n";
		cout << "1. Создать дерево со случайнами значениями\n";
		cout << "2. Вывести в прямом порядке\n";
		cout << "3. Вывести в симметричном порядке\n";
		cout << "4. Вывести в обратно-симметричном порядке\n";
		cout << "0. Завершить работу программы\n";
		cout << "Ввод: ";
		choise = input_for_menu(1);
		if (choise == 1) {
			cout << "Введите колличество вершин: \n";
			int num = input_for_menu(0);
			Delete(tree);
			Make_tree(&tree, num);
		}
		if (choise == 2) {
			Print_in_order(tree, 0); 
			
		}
		if (choise == 3) {
			Simm_print_1(tree, 0);
		}
		if (choise == 4) {
			Simm_print_2(tree, 0);
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
	if (stat == 1 && (choise > 4 || choise < 0)) {
		cout << "Повторите ввод :" << endl;
		choise = input_for_menu(1);
	}
	if (stat == 2 && choise != 1 && choise != 0) {
		cout << "Повторите ввод :" << endl;
		choise = input_for_menu(2);
	}
	return choise;
}