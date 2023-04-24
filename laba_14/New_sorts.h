#pragma once
#include <iostream>
using namespace std;

void menu();
int input_for_menu(int stat);
void new_array(int* arr, int n);
void output_array(int* arr, int n);
void bubble_sort(int* arr, int n);
void insertion_sort(int* arr, int n);
void selection_sort(int* arr, int n);
void quick_sort(int* arr, int n, int* comp, int* reeq);
void heap_sort(int* arr, int n, int* comp, int* reeq);
void heapify(int* arr, int n, int i, int* comp, int* reeq);
void shell_sort(int* arr, int n);