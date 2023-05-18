#include "Stack.h"

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
