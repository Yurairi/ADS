#include "LinkedList.h"

bool Is_Empty(LinkedList l) {
	return l.count == 0;
}

Node* Finder(LinkedList l, int data) {
	Node* ret = nullptr;
	if (!Is_Empty(l)) {
		Node* i = l.head;
		while (i != nullptr) {
			if (i->data == data) {
				ret = i;
				break;
			}
			i = i->next;
		}
	}
	return ret;
}

void Add_elem(LinkedList* l, int num_data, Node* repl, bool ind) {
	Node* elem = new Node;
	elem->data = num_data;
	elem->next = nullptr;
	if (Is_Empty(*l)) {
		l->head = elem;
	}
	else {
		if (repl == l->head && !ind) {
			elem->next = l->head;
			l->head = elem;
		}
		else {
			if (!ind) {
				Node* i = l->head;
				while (i->next != repl) { i = i->next; }
				repl = i;
			}
			elem->next = repl->next;
			repl->next = elem;
		}
	}
	l->count++;
}

void Delete_elem(LinkedList* l, Node* num) {
	if (num != nullptr) {
		Node* i = l->head;
		Node* r;
		if (num == l->head) {
			l->head = l->head->next;
			free(i);
		}
		else { 
			while (i->next != num) { i = i->next; }
			r = i->next;
			i->next = num->next;
			free(r);
		}
		l->count--;
	}
	else {
		cout << "Заданного элемента нет. Удаление не возможно. \n";
	}
}

void Move_elem(LinkedList* l, LinkedList* extr, Node* num) {
	if (num != nullptr) {
		if (num == l->head) { l->head = l->head->next; }
		else {
			Node* i = l->head;
			while (i->next != num) { i = i->next; }
			i->next = num->next;
		}
		if (Is_Empty(*extr)) {
			extr->head = num;
		}
		else {
			Node* i_2 = extr->head;
			while (i_2->next != nullptr) { i_2 = i_2->next; }
			i_2->next = num;
		}
		num->next = nullptr;
		l->count--;
		extr->count++;
	}
	else {
		cout << "Заданного элемента нет. Удаление не возможно. \n";
	}
}

void List_status(LinkedList l) {
	if (!Is_Empty(l)) {
		Node* i = l.head;
		int co = 1;
		while (i->next != nullptr) {
			cout << co << " элемент = " << i->data << "\n";
			i = i->next;
			co++;
		}
		cout << co << " элемент = " << i->data << "\n";
	}
	else {
		cout << "Список пуст. \n";
	}
}