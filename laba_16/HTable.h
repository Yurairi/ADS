#pragma once
#include <string>
#include <iostream>

#define SIZE 10

struct HashTable {
	std::string arr[SIZE];
};

int hash_func(std::string str);
bool norm_key(std::string value);
int find(HashTable table, std::string str);
void add_value(HashTable* table, std::string str);
void remove(HashTable* table, std::string str);
void build_table(HashTable* table);
void output(HashTable table);
bool empty(HashTable table);
void menu();
int input_for_menu(int stat);