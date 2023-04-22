#include "ListList.h"

bool Is_Empty(LinkedList l) {
	return l.count == 0;
}

int Finder(LinkedList l, int data, int fl) {
	int rett = 0;
	Node* ret = nullptr;
	int cnt = 1;
	if (!Is_Empty(l)) {
		Node_2* i = l.head;
		while (i != nullptr) {
			ret = Finder_head(*(i->data), data);
			if (ret != nullptr) {
				if (fl) {
					Node* ii = i->data->head;
					int co = 1;
					while (ii != Finder_head(*(i->data), data)) {
						ii = ii->next;
						co++;
					}
					cout << "Элемент найден в списке " << cnt << ". Его индекс = " << co << "\n";
				}
				rett = 1;
				break; 
			}
			i = i->next;
			cnt++;
		}
	}
	return rett;
}

void Add_elem_1(DLList *l) {
	int fl = 1, ind = 0;
	Node* num_ind = l->head;
	cout << "Введите значение, которое необходимо добавить: \n";
	int num = input_for_menu(0);
	if (!Is_Empty(*l)) {
		cout << "Введите значение, после или до которого необходимо добавить: \n";
		int datal = input_for_menu(0);
		if (Finder_head(*l, datal) == nullptr) {
			cout << "Такого значения нет: \n";
			fl = 0;
		}
		else {
			cout << "Добавление до - 0; добавление после - 1\n";
			ind = input_for_menu(2);
			num_ind = Finder_head(*l, datal);
		}
	}
	if (fl) {
		Add_elem(l, num, num_ind, ind);
	}
}

void Add_node(LinkedList* list) {
	int ch = 1;
	if (!Is_Empty(*list)) {
		cout << "Создать список - 1; добавить элемент в сущетсвующий список - 0:\n";
		ch = input_for_menu(2);
	}
	if (ch) {
		Node_2* elem = new Node_2;
		cout << "Введите id списка:\n";
		int id = input_for_menu(0);
		elem->id = id;
		elem->next = nullptr;
		DLList* l = new DLList;
		elem->data = l;
		if (Is_Empty(*list)) {
			list->head = elem;
		}
		else {
			cout << "Введите id списка после или до которого необходимо добавить новый список:\n";
			int id_2 = input_for_menu(0);
			Node_2* repl_1 = list->head;
			Node_2* repl = nullptr;
			while (repl_1 != nullptr) {
				if (repl_1->id == id_2) {
					repl = repl_1;
					break;
				}
				repl_1 = repl_1->next; 
			}
			if (repl != nullptr) {
				cout << "Добавление до - 0; добавление после - 1\n";
				int ind = input_for_menu(2);
				if (repl == list->head && !ind) {
					elem->next = list->head;
					list->head = elem;
				}
				else {
					if (!ind) {
						Node_2* ii = list->head;
						while (ii->next != repl) { ii = ii->next; }
						repl = ii;
					}
					elem->next = repl->next;
					repl->next = elem;
				}
			}
			else {
				cout << "Списка с таким id нет.\n";
			}
		}
		list->count++;
	}
	else {
		cout << "Введите id списка в который необходимо добавить элемент:\n";
		int id_2 = input_for_menu(0);
		Node_2* repl_1 = list->head;
		Node_2* repl = nullptr;
		while (repl_1 != nullptr) {
			if (repl_1->id == id_2) {
				repl = repl_1;
				break;
			}
			repl_1 = repl_1->next;
		}
		if (repl == nullptr) {
			cout << "Списка с таким id нет.\n";
		}
		else {
			Add_elem_1(repl->data);
		}
	}
}

void Delete_node(LinkedList* list, int id_2) {
	Node_2* repl_1 = list->head;
	Node_2* num = nullptr;
	while (repl_1 != nullptr) {
		if (repl_1->id == id_2) {
			num = repl_1;
			break;
		}
		repl_1 = repl_1->next;
	}
	if (repl_1 != nullptr) {
		if (repl_1->id == id_2) {
			num = repl_1;
		}
	}
	if (num != nullptr) {
		Node_2* i = list->head;
		Node_2* r;
		if (num == list->head) {
			list->head = list->head->next;
			DLList* tr = i->data;
			Node* Fir = nullptr;
			Node* Sec = tr->head;
			while (Fir != nullptr) { Fir = Sec->next; Delete_elem(tr, Sec); Sec = Fir; }
			free(i);
		}
		else {
			while (i->next != num) { i = i->next; }
			r = i->next;
			i->next = num->next;
			DLList* tr = i->data;
			Node* Fir = nullptr;
			Node* Sec = tr->head;
			while (Fir != nullptr) { Fir = Sec->next; Delete_elem(tr, Sec); Sec = Fir; }
			free(r);
		}
		list->count--;
	}
	else {
		cout << "Списка с таким номером нет. Удаление не возможно. \n";
	}
}

void Delete_elem_1(LinkedList* list) {
	cout << "Введите номер списка из которого необходимо удалить элемент\n";
	int id_2 = input_for_menu(0);
	Node_2* num = list->head;
	while (num->next != nullptr) {
		if (num->id == id_2) { break; }
		num = num->next;
	}
	if (Is_Empty(*(num->data))) { cout << "Список пуст. \n"; }
	else {
		cout << "Введите значение, которое необходимо удалить: ";
		int nu = input_for_menu(0);
		Delete_elem(num->data, Finder_head(*(num->data), nu));
	}
}

void List_status(LinkedList l) {
	if (!Is_Empty(l)) {
		Node_2* i = l.head;
		while (i != nullptr) {
			cout << "Список " << i->id << '\n';
			List_status_head(*(i->data));
			i = i->next;
		}
	}
	else {
		cout << "Список списков пуст. \n";
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
	return choise;
}
