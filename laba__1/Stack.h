#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;

struct stack {
    int data;
    stack* next;
};

stack* init();
stack* init(int data);
bool Is_empty(stack* head);
void add_elem(stack** head, int data);
void add_rand_elem(stack** head, int num);
void delete_elem(stack** head);
void print_state(stack* head);
void move_elem(stack** fir_head, stack** sec_head);

void main_menu(stack* fir_stack, stack* sec_stack);
int input_for_menu(int stat);