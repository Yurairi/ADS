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

void Make_tree(branch** root, int n, bool fl);
void Print_in_order(branch* root, int level);
void Simm_print_1(branch* root, int level);
void Simm_print_2(branch* root, int level);
void Simm_print_iter(branch* root);
void Delete(branch* root);

void main_menu();
int input_for_menu(int stat);