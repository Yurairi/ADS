#include "DoubleLinkedList.h"

bool Is_Empty(DLList l) {
	return l.count == 0;
}

Node* Finder_head(DLList l, int data) {
	Node* ret = nullptr;
	int co = 0;
	if (!Is_Empty(l)) {
		Node* i = l.head;
		while (co < l.count) {
			if (i->data == data) {
				ret = i;
				break;
			}
			i = i->next;
			co++;
		}
	}
	return ret;
}

Node* Finder_tail(DLList l, int data) {
	Node* ret = nullptr;
	int co = 0;
	if (!Is_Empty(l)) {
		Node* i = l.head->prev;
		while (co < l.count) {
			if (i->data == data) {
				ret = i;
				break;
			}
			i = i->prev;
			co++;
		}
	}
	return ret;
}

void Add_elem(DLList* l, int num_data, Node* repl, bool ind) {
	Node* elem = new Node;
	elem->data = num_data;
	elem->next = nullptr;
	elem->prev = nullptr;
	if (Is_Empty(*l)) {
		l->head = elem;
		l->head->prev = elem;
		l->head->next = elem;
	}
	else {
		if (ind) {
			elem->next = repl->next;
			elem->prev = repl;
			if (repl->next->prev != nullptr) repl->next->prev = elem;
			repl->next = elem;
		}
		else {
			elem->next = repl;
			elem->prev = repl->prev;
			if (repl->prev->next != nullptr) repl->prev->next = elem;
			repl->prev = elem;
			if (repl == l->head) {
				l->head = elem; 
			}
		}
	}
	l->count++;
}

void Delete_elem(DLList* l, Node* num) {
	if (num != nullptr) {
		num->prev->next = num->next;
		num->next->prev = num->prev;
		if (num == l->head) {
			l->head = num->next;
		}
		free(num);
		l->count--;
	}
	else {
		cout << "Заданного элемента нет. Удаление не возможно. \n";
	}
}

void List_status_head(DLList l) {
	if (!Is_Empty(l)) {
		Node* i = l.head;
		int co = 1;
		while (co - 1 != l.count) {
			cout << co << " элемент = " << i->data << "\n";
			i = i->next;
			co++;
		}
	}
}

void List_status_tail(DLList l) {
	if (!Is_Empty(l)) {
		Node* i = l.head->prev;
		int co = 1;
		while (co - 1 != l.count) {
			cout << co << " элемент = " << i->data << "\n";
			i = i->prev;
			co++;
		}
	}
}