#include "Spec_sorts.h"

void new_array(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
}

void new_array_2(int* arr, int n) {
	for (int i = 0; i < n; ++i)
		arr[i] = i;
	random_shuffle(&arr[0], &arr[n - 1]);
}

void new_array_3(int* arr, int n) {
	for (int i = 0; i < n - 20; ++i)
		arr[i] = i;
	for (int i = n - 20; i < n; ++i)
		arr[i] = rand() % n ;
	random_shuffle(&arr[0], &arr[n - 1]);
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

void quick_sort(int* arr, int n, int* comp, int* reeq) {
	int i = 0;
	int j = n - 1;

	*reeq += 1;
	int mid = arr[n / 2];

	do {
		while (arr[i] < mid) {
			*comp += 1;
			i++;
		}
		*comp += 1;
		while (arr[j] > mid) {
			*comp += 1;
			j--;
		}
		*comp += 1;

		*comp += 1;
		if (i <= j) {
			*reeq += 3;
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) {
		quick_sort(arr, j + 1, comp, reeq);
	}
	if (i < n) {
		quick_sort(&arr[i], n - i, comp, reeq);
	}
}

void heapify(int* arr, int n, int i, int* comp, int* reeq)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	*comp += 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		*reeq += 3;
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest, comp, reeq);
	}
}


void heap_sort(int* arr, int n, int* comp, int* reeq)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i, comp, reeq);

	for (int i = n - 1; i >= 0; i--)
	{
		*reeq += 3;
		swap(arr[0], arr[i]);
		heapify(arr, i, 0, comp, reeq);
	}
}

void shell_sort(int* arr, int n) {
	cout << "Состояние массива до сортировки: \n";
	output_array(arr, n);
	int comp = 0;
	int reeq = 0;

	int i, j, step;
	int tmp;
	for (step = n / 2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			reeq++;
			tmp = arr[i];
			for (j = i; j >= step; j -= step)
			{
				comp++;
				if (tmp < arr[j - step]) { arr[j] = arr[j - step]; reeq++; }
				else break;
			}
			arr[j] = tmp;
			reeq++;
		}

	cout << "Число выполненных сравнений: " << comp << "\n";
	cout << "Число выполненных пересылок: " << reeq << "\n";
	cout << ":Состояние массива после сортировки: \n";
	output_array(arr, n);
}

void bucket_sort(int* arr, int n) {
	cout << "Состояние массива до сортировки: \n";
	output_array(arr, n);
	int* dop = new int[n];

	cout << "Выберите нужно ли использовать второй массив:\n0 - не использовать\n1 - использовать\n";
	int choice = input_for_menu(2);
	if (choice == 0) {
		for (int i = 0; i < n; i++)
		{
			while (arr[i] != i)
			{
				int temp{ arr[arr[i]] };
				arr[arr[i]] = arr[i];
				arr[i] = temp;
			}
		}
	}
	else if (choice == 1) {
		for (int i = 0; i < n; i++) dop[i] = i;

		for (int i = 0; i < n; i++) {
			dop[arr[i]] = arr[i];
		}
	}

	cout << ":Состояние массива после сортировки: \n";
	if (choice) { output_array(dop, n); free(dop); dop = NULL; }
	else output_array(arr, n);
}


void gener_bucket_sort(int* arr, int n) {
	cout << "Состояние массива до сортировки: \n";
	output_array(arr, n);

	int max = arr[0];
	for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];

	Node** dop = new Node * [max + 1] {nullptr};

	for (int i = 0; i < n; i++) {
		Node* current = new Node;
		current->data = arr[i];
		current->next = nullptr;
		if (!dop[arr[i]]) {
			dop[arr[i]] = current;
		}
		else {
			current->next = dop[arr[i]];
			dop[arr[i]] = current;
		}
	}

	int j = 0;
	for (int i = 0; i < max + 1; i++) {
		Node* curr = dop[i];
		while (curr)
		{
			arr[j] = curr->data;
			curr = curr->next;
			j++;
		}
	}

	cout << ":Состояние массива после сортировки: \n";
	output_array(arr, n);
	free(dop);
}

void radix_sort(int* arr, int n) {
	cout << "Состояние массива до сортировки: \n";
	output_array(arr, n);

	int max = arr[0];
	
	for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];

	for (int posit = 1; max / posit > 0; posit *= 10) {
		int* count = new int[10] {0};
		int* result = new int[n];

		for (int i = 0; i < n; i++)
			count[(arr[i] / posit) % 10]++;

		for (int i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (int i = n - 1; i >= 0; i--)
		{
			result[count[(arr[i] / posit) % 10] - 1] = arr[i];
			count[(arr[i] / posit) % 10]--;
		}
		free(count);
		for (int i = 0; i < n; i++) arr[i] = result[i];

		free(result);
	}

	cout << ":Состояние массива после сортировки: \n";
	output_array(arr, n);
	
}