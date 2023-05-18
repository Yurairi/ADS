#include"List_stat.h"

bool Is_Empty(List l) {
	return l.count == 0;
}

bool Is_Full(List l) {
	return l.count == MAX;
}

void Add_elem(List* l, int num_data) {
	if (Is_Full(*l)) {
		cout << "Список заполнен. Добавление невозможно. \n";
	}
	if (!Is_Full(*l) && !Is_Empty(*l)) {
		int numb = 0;
		while (num_data > l->data[numb] && numb != l->count) numb++;
		for (int i = l->count; i > numb; i--) l->data[i] = l->data[i - 1];
		l->data[numb] = num_data;
		l->count++;
	}
	if (Is_Empty(*l)) {
		l->data[0] = num_data;
		l->count++;
	}
}

int Finder(List l, int num_data) {
	int i = 0;
	if (Is_Empty(l)) i = -1;
	else {
		while (l.data[i] != num_data && i != MAX) i++;
		if (i == MAX) i = -1;
	}
	return i;
}

void List_status(List l) {
	if (!Is_Empty(l)) {
		for (int i = 0; i < l.count; i++) {
			cout << i + 1 << " элемент = " << l.data[i] << "\n";
		}
	}
	else {
		cout << "Список пуст. \n";
	}
}

void Delete_elem(List* l, int num_data) {
	int num = Finder(*l, num_data);
	if (num != -1) {
		for (int i = num; i < l->count; i++) l->data[i] = l->data[i + 1];
		l->count--;
	}
	else {
		cout << "Заданного элемента нет. Удаление не возможно. \n";
	}
}