#pragma once

#include <iostream>
#include <string.h>
#include<string.h>
using namespace std;

struct branch {
	int data;
	branch* left;
	branch* right;
};

struct stack {
	int level = -1;
	branch* data;
	stack* next;
};

branch* Finder(branch* root, int search_data);
void Add_data(branch** root, int data_n);
int input_for_menu(int stat);
void Print_in_order(branch* root, int level);
void Simm_print_1(branch* root, int level);
void Simm_print_2(branch* root, int level);
void Delete(branch* root);
void main_menu();