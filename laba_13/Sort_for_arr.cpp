#include "Sort_for_arr.h"

void new_array(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
}

void output_array(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void bubble_sort(int* arr, int n) {
	cout << "Состояние массива до сортировки: \n";
	output_array(arr, n);
	int comp = 0;
	int reeq = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			comp++;
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				reeq += 3;
			}
		}
	}

	cout << "Число выполненных сравнений: " << comp << "\n";
	cout << "Число выполненных пересылок: " << reeq << "\n";
	cout << ":Состояние массива после сортировки: \n";
	output_array(arr, n);
}

void selection_sort(int* arr, int n) {
	cout << "Состояние массива до сортировки: \n";
	output_array(arr, n);
	int comp = 0;
	int reeq = 0;

	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			comp++;
			if (arr[j] < arr[min]) min = j;
		}
		if (min != i) {
			reeq += 3;
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}

	cout << "Число выполненных сравнений: " << comp << "\n";
	cout << "Число выполненных пересылок: " << reeq << "\n";
	cout << ":Состояние массива после сортировки: \n";
	output_array(arr, n);
}


void insertion_sort(int* arr, int n) {
	cout << "Состояние массива до сортировки: \n";
	output_array(arr, n);
	int comp = 0;
	int reeq = 0;
		
	for (int i = 1; i < n; i++) {
		reeq++;
		int temp = arr[i];
		int j = i - 1;
		comp++;
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j = j - 1;
			comp++;
			reeq++;
		}
		comp++;
		if (arr[j + 1] != temp) {
			arr[j + 1] = temp;
			reeq++;
		}
	}

	cout << "Число выполненных сравнений: " << comp << "\n";
	cout << "Число выполненных пересылок: " << reeq << "\n";
	cout << ":Состояние массива после сортировки: \n";
	output_array(arr, n);
}