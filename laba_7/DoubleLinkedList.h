#pragma once

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

struct DLList {
	Node* head = nullptr;
	int count = 0;
};

bool Is_Empty(DLList l);
Node* Finder_head(DLList l, int data);
Node* Finder_tail(DLList l, int data);
void Add_elem(DLList* l, int num_data, Node* repl, bool ind);
void Delete_elem(DLList* l, Node* num);
void List_status_head(DLList l);
void List_status_tail(DLList l);
int input_for_menu(int stat);
void main_menu(DLList l);
int input_for_menu(int stat);