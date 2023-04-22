#pragma once

#include <iostream>
#include <stdlib.h>
#include "windows.h"
using namespace std;

struct que_elem {
	char data;
	que_elem* next;
};

struct dyn_que {
	que_elem* head = new que_elem;
	que_elem* tail = nullptr;
	int count = 0;
};

bool Is_Empty(dyn_que qu);
void add_elem(dyn_que* qu, char num_data);
void delete_elem(dyn_que* qu);
void queue_status(dyn_que qu);
void main_menu(dyn_que qu);
int input_for_menu(int stat);
void modeling(dyn_que* qu);