#pragma once
#include <iostream>
#include <random>
using namespace std;

struct Node
{
	int data{ -1 };
	Node* next{ nullptr };
};

void menu();
int input_for_menu(int stat);
void new_array(int* arr, int n);
void new_array_2(int* arr, int n);
void new_array_3(int* arr, int n);
void output_array(int* arr, int n);
void bubble_sort(int* arr, int n);
void insertion_sort(int* arr, int n);
void selection_sort(int* arr, int n);
void quick_sort(int* arr, int n, int* comp, int* reeq);
void heap_sort(int* arr, int n, int* comp, int* reeq);
void heapify(int* arr, int n, int i, int* comp, int* reeq);
void shell_sort(int* arr, int n);
void bucket_sort(int* arr, int n);
void gener_bucket_sort(int* arr, int n);
void radix_sort(int* arr, int n);