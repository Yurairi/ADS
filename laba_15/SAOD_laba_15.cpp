#include "Spec_sorts.h"

int main()
{
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
		cout << "3. Сортировка методом пузырька/ быстрая .\n";
		cout << "4. Сортировка вставками/ Шелла.\n";
		cout << "5. Сортировка выбором/ пирамидальная.\n";
		cout << "6. Карманная сортировка.\n";
		cout << "7. Обобщенная карманная сортировка.\n";
		cout << "8. Поразрядная сортировка.\n";
		cout << "9. Очистить массив.\n";
		cout << "0. Завершить работу программы\n";
		cout << "Ввод: ";
		int choice;
		choice = input_for_menu(1);
		if (choice == 1) {
			cout << "Введите размер массива (менее 10 000)\n";
			n = input_for_menu(3);
			arr = new int[n];
			temp = new int[n];
			new_array(arr, n);
			for (int i = 0; i < n; i++) temp[i] = arr[i];
		}
		if (choice == 2) {
			if (arr) output_array(arr, n);
			else cout << "Массив пуст. \n";
		}
		if (choice == 3) {
			if (arr) {
				cout << "Сортировка пузырьком - 1, быстрая - 0 \n";
				int ch = input_for_menu(2);
				if (ch) bubble_sort(arr, n);
				else {
					int reeq = 0, comp = 0;
					cout << "Состояние массива до сортировки: \n";
					output_array(arr, n);
					quick_sort(arr, n, &comp, &reeq);
					cout << "Число выполненных сравнений: " << comp << "\n";
					cout << "Число выполненных пересылок: " << reeq << "\n";
					cout << ":Состояние массива после сортировки: \n";
					output_array(arr, n);
				}
				for (int i = 0; i < n; i++) arr[i] = temp[i];
			}
			else cout << "Массив пуст. \n";
		}
		if (choice == 4) {
			if (arr) {
				cout << "Сортировка вставками - 1, Шелла - 0 \n";
				int ch = input_for_menu(2);
				if (ch) insertion_sort(arr, n);
				else shell_sort(arr, n);
				for (int i = 0; i < n; i++) arr[i] = temp[i];
			}
			else cout << "Массив пуст. \n";
		}
		if (choice == 5) {
			if (arr) {
				cout << "Сортировка выбором - 1, пирамидальная - 0 \n";
				int ch = input_for_menu(2);
				if (ch) selection_sort(arr, n);
				else {
					int reeq = 0, comp = 0;
					cout << "Состояние массива до сортировки: \n";
					output_array(arr, n);
					heap_sort(arr, n, &comp, &reeq);
					cout << "Число выполненных сравнений: " << comp << "\n";
					cout << "Число выполненных пересылок: " << reeq << "\n";
					cout << ":Состояние массива после сортировки: \n";
					output_array(arr, n);
				}
				for (int i = 0; i < n; i++) arr[i] = temp[i];
			}
			else cout << "Массив пуст. \n";
		}
		if (choice == 6)  {
			if (arr) free(arr); arr = NULL;
			if (temp) free(temp); temp = NULL;
			cout << "Введите размер массива\n";
			n = input_for_menu(3);
			arr = new int[n];
			temp = new int[n];
			new_array_2(arr, n);
			for (int i = 0; i < n; i++) temp[i] = arr[i];
			bucket_sort(arr, n);
			for (int i = 0; i < n; i++) arr[i] = temp[i];
		}
		if (choice == 7) {
			if (arr) free(arr); arr = NULL;
			if (temp) free(temp); temp = NULL;
			cout << "Введите размер массива\n";
			n = input_for_menu(3);
			arr = new int[n];
			temp = new int[n];
			new_array_3(arr, n);
			for (int i = 0; i < n; i++) temp[i] = arr[i];
			gener_bucket_sort(arr, n);
			for (int i = 0; i < n; i++) arr[i] = temp[i];
		}
		if (choice == 8) {
			if (arr) free(arr); arr = NULL;
			if (temp) free(temp); temp = NULL;
			cout << "Введите размер массива\n";
			n = input_for_menu(3);
			arr = new int[n];
			temp = new int[n];
			int num = 1;
			if (n > 10) for (int i = n; i > 10; i /= 10) num *= 10;
			else num = 10;
			new_array_3(arr, n);
			for (int i = 0; i < n; i++) temp[i] = arr[i];
			radix_sort(arr, n);
			for (int i = 0; i < n; i++) arr[i] = temp[i];
		}
		if (choice == 9) {
			if (arr) {
				free(arr);
				arr = NULL;
				free(temp);
				temp = NULL;
			}
		}
		if (choice == 0) {
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
	int choice;
	while (!(cin >> choice))
	{
		cin.clear();
		while (cin.get() != '\n') {
			cout << "Повторите ввод :" << endl;
		}
	}
	if (stat == 1 && (choice > 9 || choice < 0)) {
		cout << "Повторите ввод :" << endl;
		choice = input_for_menu(1);
	}
	if (stat == 2 && choice != 1 && choice != 0) {
		cout << "Повторите ввод :" << endl;
		choice = input_for_menu(2);
	}
	if (stat == 3 && (choice <= 0 || choice > 10000)) {
		cout << "Повторите ввод :" << endl;
		choice = input_for_menu(3);
	}
	return choice;
}

