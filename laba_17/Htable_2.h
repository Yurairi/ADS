#pragma once
#include <string>
#include <iostream>
#include<math.h>

#define SIZE 10

struct HashTable {
	std::string arr[SIZE]{"\0"};
};

int hash_func(std::string str);
bool norm_key(std::string value);
int find(HashTable table, std::string str, int* counter);
void add_value(HashTable* table, std::string str, int* counter);
void remove(HashTable* table, std::string str);
void build_table(HashTable* table);
void output(HashTable table);
bool empty(HashTable table);
bool full(HashTable table);
void menu();
int input_for_menu(int stat);