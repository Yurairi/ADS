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

struct Node_2 {
	int id;
	DLList* data;
	Node_2* next;
};

struct LinkedList {
	Node_2* head = nullptr;
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
void main_menu(LinkedList l);
int input_for_menu(int stat);
bool Is_Empty(LinkedList l);
int Finder(LinkedList l, int data, int fl);
void Add_elem_1(DLList* l);
void Add_node(LinkedList* list);
void Delete_node(LinkedList* list, int id_2);
void Delete_elem_1(LinkedList* list);
void List_status(LinkedList l);
