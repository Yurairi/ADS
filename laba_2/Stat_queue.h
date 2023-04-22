#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 5

struct stat_queue {
	int data[MAX];
	int count = 0;
	int head = 0;
	int tail = 0;
};

bool Is_Empty(stat_queue queue);
bool Is_Full(stat_queue queue);
void add_elem(stat_queue* queue, int num_data);
void delete_elem(stat_queue* queue);
void queue_status(stat_queue queue);
void main_menu(stat_queue qu);
int input_for_menu(int stat);