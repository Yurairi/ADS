#include"List.h"

void Init(List* l) {
	for (int i = 0; i < MAX; i++) {
		l->elem[i].next = -1;
	}
}

bool Is_Empty(List l) {
	return l.count == 0;
}

bool Is_Full(List l) {
	return l.count == MAX;
}

int Finder(List l, int data) {
	int ret = -1;
	if (!Is_Empty(l)) {
		int i = l.head;
		while (l.elem[i].next != -1) {
			if (l.elem[i].data == data) {
				ret = i;
				break;
			}
			i = l.elem[i].next;
		}
		if (l.elem[i].data == data) ret = i;
	}
	return ret;
}

void Add_elem(List* l, int num_data, int num_ind, int ind) {
	if (!Is_Full(*l) && !Is_Empty(*l)) {
		int pos = Mem(*l);
		l->elem[pos].data = num_data;
		if (num_ind == l->head && !ind) {
			l->elem[pos].next = num_ind;
			l->head = pos;
		}
		else {
			if (!ind) {
				int i = l->head;
				while (l->elem[i].next != num_ind) { i = l->elem[i].next; }
				num_ind = i;
			}
			l->elem[pos].next = l->elem[num_ind].next;
			l->elem[num_ind].next = pos;
		}
		l->count++;
	}
	if (Is_Empty(*l)) {
		l->elem[l->head].data = num_data;
		l->count++;
	}
}

void Delete_elem(List* l, int num_data) {
	int num = Finder(*l, num_data);
	if (num != -1) {
		if (num == l->head && l->elem[l->head].next != -1) { l->head = l->elem[l->head].next; }
		else {
			int i = l->head;
			while (l->elem[i].next != num) { i = l->elem[i].next; }
			l->elem[i].next = l->elem[num].next;
		}
		l->elem[num].next = -1;
		l->elem[num].data = NULL;
		l->count--;
		if (l->count == 0) { l->head = 0; }
	}
	else {
		cout << "Заданного элемента нет. Удаление не возможно. \n";
	}
}

void List_status(List l) {
	if (!Is_Empty(l)) {
		int i = l.head, co = 1;
		while (l.elem[i].next != -1) {
			cout << co << " элемент = " << l.elem[i].data <<  "\n";
			i = l.elem[i].next;
			co++;
		}
		cout << co << " элемент = " << l.elem[i].data << "\n";
	}
	else {
		cout << "Список пуст. \n";
	}
}

int Mem(List l) {
	int ret = l.count;
	for (int i = 0; i < MAX; i++) {
		if (l.elem[i].data == NULL) {
			ret = i;
			break;
		}
	}
	return ret;
}