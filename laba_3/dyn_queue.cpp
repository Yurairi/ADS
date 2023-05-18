#include "dyn_queue.h"

bool Is_Empty(dyn_que qu) {
	return qu.count == 0;
}

void add_elem(dyn_que* qu, char num_data) {
	que_elem* new_tail = new que_elem;
	new_tail->data = num_data;
	if (qu->count == 0) {
		qu->head = qu->tail = new_tail;
	}
	else {
		qu->tail->next = new_tail;
		qu->tail = new_tail;
	}
	qu->count++;
}

void delete_elem(dyn_que* qu) {
	if (Is_Empty(*qu)) {
		cout << "Очередь пустая. Удаление невозможно. \n";
	}
	else {
		que_elem* temp = qu->head;
		qu->head = qu->head->next;
		free(temp);
		qu->count--;
	}
}

void queue_status(dyn_que qu) {
	if (!Is_Empty(qu)) {
		que_elem* temp = qu.head;
		for (int i = 1; i < qu.count + 1; i++) {
			cout << i << " элменет = " << temp->data << "\n";
			temp = temp->next;
		}
	}
	else {
		cout << "Очередь пустая. \n";
	}
}