#include "Sort_for_arr.h"

int main()
{
	system("UTF");
	setlocale(LC_ALL, "Russian");
	menu();
	return 0;
}

void menu() {
	int* arr = { 0 };
	int* temp = { 0 };
	int n;
	while (true) {
		cout << "Выберете необходимое действие:\n";
		cout << "1. Создать массив.\n";
		cout << "2. Вывести состояние масссива.\n";
		cout << "3. Сортировка методом пузырька.\n";
		cout << "4. Сортировка выбором.\n";
		cout << "5. Сортировка вставками.\n";
		cout << "6. Удалить массив.\n";
		cout << "0. Завершить работу программы\n";
		cout << "Ввод: ";
		int choise;
		choise = input_for_menu(1);
		if (choise == 1) {
			cout << "Введите размер массива (менее 10 000)\n";
			n = input_for_menu(3);
			arr = new int[n];
			temp = new int[n];
			new_array(arr, n);
			for (int i = 0; i < n; i++) temp[i] = arr[i];
		}
		if (choise == 2) {
			if (arr) output_array(arr, n);
			else cout << "Массив пуст. \n";
		}
		if (choise == 3) {
			if (arr) {
				bubble_sort(arr, n);
				for (int i = 0; i < n; i++) arr[i] = temp[i];
			}
			else cout << "Массив пуст. \n";
		}
		if (choise == 4) {
			if (arr) {
				selection_sort(arr, n);
				for (int i = 0; i < n; i++) arr[i] = temp[i];
			}
			else cout << "Массив пуст. \n";	
		}
		if (choise == 5) {
			if (arr) {
				insertion_sort(arr, n);
				for (int i = 0; i < n; i++) arr[i] = temp[i];
			}
			else cout << "Массив пуст. \n";
		}
		if (choise == 6) {
			if (arr) {
				free(arr);
				arr = NULL;
				free(temp);
				temp = NULL;
			}
		}
		if (choise == 0) {
			if (arr) {
				free(arr);
				arr = NULL;
				free(temp);
				temp = NULL;
			}
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
	if (stat == 3 && (choise <= 0 || choise > 10000)) {
		cout << "Повторите ввод :" << endl;
		choise = input_for_menu(3);
	}
	return choise;
}
