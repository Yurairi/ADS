#pragma once

#include <iostream>
#define MAX 5
using namespace std;

struct List
{
	int data[MAX];
	int count = 0;
};

bool Is_Empty(List l);
bool Is_Full(List l);
void Add_elem(List* l, int num_data);
int Finder(List l, int num_data);
void List_status(List l);
void Delete_elem(List* l, int num_data);
void main_menu(List l);
int input_for_menu(int stat);
