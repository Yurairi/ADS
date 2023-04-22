#pragma once

#include <iostream>
#include <string.h>
#include<string.h>
using namespace std;

struct branch {
	int data;
	int count;
	branch* parent;
	branch* left;
	branch* right;
};

struct stack {
	int level = -1;
	branch* data;
	stack* next;
};


branch* Finder(branch* root, int search_data);
void Add_data_rec(branch** root, int data_n, int fl);
void Add_data_iter(branch** root, int data_n);
void Remove_key(branch** root, int key);
void Rand_build(branch** root, int num);
void In_order(const branch* root);
void Simm_print_2(branch* root, int level);
void Delete(branch* root);
int input_for_menu(int stat);
void main_menu();