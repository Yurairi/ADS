#include"Htable_2.h"

namespace key_wr {
	const int size_of_table = 10;

	std::string keys[key_wr::size_of_table]{
		"Ivanov",
		"Petrov",
		"Yakovenko",
		"Trifonov",
		"Yunusov",
		"Yusupov",
		"Dmitrenko",
		"Sharapova",
		"Chernih",
		"Kotamova"
	};
}

int hash_func(std::string str) {
	int res = 0;

	for (int i = 0; i < str.size(); i++) {
		int a = str[i];
		res += a;
	}
	res %= SIZE;

	return abs(res);
}

int find(HashTable table, std::string str, int *counter) {
	int ret = -1;
	int index = hash_func(str);
	int count = 0, fl = 1;
	*counter += 1;
	if (table.arr[index] == "\0") { fl = 0; }
	else if (table.arr[index] != str) {
		*counter += 1;
		while (table.arr[index] != str && count != SIZE) {
			index = (index + 1) % SIZE;
			count++;
		}
		*counter += count;
	}
	if (count != SIZE && fl) {
		std::cout << "Индекс найденного ключа: " << index << "\n";
		ret = index;
	}
	return ret;
}

void add_value(HashTable* table, std::string str, int* counter) {
	if (full(*table)) std::cout << "Таблица заполнена. \n";
	else {
		int index = find(*table, str, counter);
		if (index != -1) {
			std::cout << "Значение уже существует под индексом: " << index << "\n";
		}
		else {
			index = hash_func(str);
			*counter += 1;
			if (table->arr[index] != "\0" && index != SIZE) {
				*counter += 1;
				while (table->arr[index] != "\0") {
					*counter += 1;
					index = (index + 1) % SIZE;
				}
			}
			table->arr[index] = str;
		}
	}
}

void remove(HashTable* table, std::string str) {
	int index = find(*table, str, &index);
	if (index == -1) {
		std::cout << "Значение не найдено. " << "\n";
	}
	else {
		table->arr[index] = "\0";
	}
}

void build_table(HashTable* table) {
	int c = 0;
	for (int i = 0; i < key_wr::size_of_table; i++) {
		std::string key = key_wr::keys[i];
		add_value(table, key, &c);
	}
	std::cout << "Кол-во выполненных сравнений при добавлении: " << c << "\n";
}

void output(HashTable table) {
	for (int i = 0; i < SIZE; i++) {
		if (table.arr[i] != "0") std::cout << i << ". " << table.arr[i] << "\n";
		else  std::cout << i << ". " << "\n";
	}
}

bool empty(HashTable table) {
	bool ret = 0;
	for (int i = 0; i < SIZE; i++) {
		if (table.arr[i] != "\0") {
			ret = 1;
			break;
		}
	}
	return ret;
}

bool full(HashTable table) {
	bool ret = 1;
	for (int i = 0; i < SIZE; i++) {
		if (table.arr[i] == "\0") {
			ret = 0;
			break;
		}
	}
	return ret;
}