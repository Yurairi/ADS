#pragma once

#include <iostream>
#define MAX 5
using namespace std;

struct Elem
{
	int data;
	int next;
};

struct List
{
	int head = 0;
	Elem elem[MAX];
	int count = 0;
};

void Init(List* l);
bool Is_Empty(List l);
bool Is_Full(List l);
void Add_elem(List* l, int num_data, int num_ind, int ind);
int Finder(List l, int num_data);
void List_status(List l);
void Delete_elem(List* l, int num_data);
void main_menu(List l);
int input_for_menu(int stat);
int Mem(List l);
