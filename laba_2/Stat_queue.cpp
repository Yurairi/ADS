#include "Stat_queue.h"

bool Is_Empty(stat_queue queue) {
	return queue.count == 0;
}

bool Is_Full(stat_queue queue) {
	return queue.count == MAX;
}

void add_elem(stat_queue *queue, int num_data) {
	if (!Is_Full(*queue)) {
		queue->data[queue->tail] = num_data;
		queue->tail = (queue->tail + 1) % MAX;
		queue->count++;
	}
	else {
		cout << "Очередь заполнена. Добавление невозможно. \n";
	}
}

void delete_elem(stat_queue *queue) {
	if (!Is_Empty(*queue)) {
		queue->head = (queue->head + 1) % MAX;
		queue->count--;
	}
	else {
		cout << "Очередь пустая. Удаление невозможно. \n";
	}
}

void queue_status(stat_queue queue) {
	if (!Is_Empty(queue)) {
		int num = 1;
		int i = queue.head;
		cout << num << " элменет = " << queue.data[i] << "\n";
		num++;
		i = (i + 1) % MAX;
		while (i != queue.tail) {
			cout << num << " элменет = " << queue.data[i] << "\n";
			num++;
			i = (i + 1) % MAX;
		}
	}
	else {
		cout << "Очередь пустая. \n";
	}
}