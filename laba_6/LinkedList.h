#pragma once

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

struct LinkedList {
	Node* head = nullptr;
	int count = 0;
};

bool Is_Empty(LinkedList l);
void Add_elem(LinkedList* l, int num_data, Node* repl, bool ind);
Node* Finder(LinkedList l, int data);
void Delete_elem(LinkedList* l, Node* num);
void List_status(LinkedList l);
void Move_elem(LinkedList* l, LinkedList* extr, Node* num);
void main_menu(LinkedList l, LinkedList extr);
int input_for_menu(int stat);
