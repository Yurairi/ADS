#include "New_sorts.h"

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
		cout << "�������� ����������� ��������:\n";
		cout << "1. ������� ������.\n";
		cout << "2. ������� ��������� ��������.\n";
		cout << "3. ���������� ������� ��������/ ������� .\n";
		cout << "4. ���������� ���������/ �����.\n";
		cout << "5. ���������� �������/ �������������.\n";
		cout << "6. ������� ������.\n";
		cout << "0. ��������� ������ ���������\n";
		cout << "����: ";
		int choise;
		choise = input_for_menu(1);
		if (choise == 1) {
			cout << "������� ������ ������� (����� 10 000)\n";
			n = input_for_menu(3);
			arr = new int[n];
			temp = new int[n];
			new_array(arr, n);
			for (int i = 0; i < n; i++) temp[i] = arr[i];
		}
		if (choise == 2) {
			if (arr) output_array(arr, n);
			else cout << "������ ����. \n";
		}
		if (choise == 3) {
			if (arr) {
				cout << "���������� ��������� - 1, ������� - 0 \n";
				int ch = input_for_menu(2);
				if (ch) bubble_sort(arr, n);
				else {
					int reeq = 0, comp = 0;
					cout << "��������� ������� �� ����������: \n";
					output_array(arr, n);
					quick_sort(arr, n, &comp, &reeq);
					cout << "����� ����������� ���������: " << comp << "\n";
					cout << "����� ����������� ���������: " << reeq << "\n";
					cout << ":��������� ������� ����� ����������: \n";
					output_array(arr, n);
				}
				for (int i = 0; i < n; i++) arr[i] = temp[i];
			}
			else cout << "������ ����. \n";
		}
		if (choise == 4) {
			if (arr) {
				cout << "���������� ��������� - 1, ����� - 0 \n";
				int ch = input_for_menu(2);
				if (ch) selection_sort(arr, n);
				else shell_sort(arr, n);
				for (int i = 0; i < n; i++) arr[i] = temp[i];
			}
			else cout << "������ ����. \n";
		}
		if (choise == 5) {
			if (arr) {
				cout << "���������� ������� - 1, ������������� - 0 \n";
				int ch = input_for_menu(2);
				if (ch) insertion_sort(arr, n);
				else {
					int reeq = 0, comp = 0;
					cout << "��������� ������� �� ����������: \n";
					output_array(arr, n);
					heap_sort(arr, n, &comp, &reeq);
					cout << "����� ����������� ���������: " << comp << "\n";
					cout << "����� ����������� ���������: " << reeq << "\n";
					cout << ":��������� ������� ����� ����������: \n";
					output_array(arr, n);
				}
				for (int i = 0; i < n; i++) arr[i] = temp[i];
			}
			else cout << "������ ����. \n";
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
			cout << "��������� ���� :" << endl;
		}
	}
	if (stat == 1 && (choise > 6 || choise < 0)) {
		cout << "��������� ���� :" << endl;
		choise = input_for_menu(1);
	}
	if (stat == 2 && choise != 1 && choise != 0) {
		cout << "��������� ���� :" << endl;
		choise = input_for_menu(2);
	}
	if (stat == 3 && (choise <= 0 || choise > 10000)) {
		cout << "��������� ���� :" << endl;
		choise = input_for_menu(3);
	}
	return choise;
}