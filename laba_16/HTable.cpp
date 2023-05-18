#include"HTable.h"


namespace key_wr {
	std::string keys[SIZE]{
		"array", //
		"until", //
		"exit", //
		"with", //
		"uses", //
		"const", //
		"var", //
		"virtual", //
		"for", //
		"template" //
	};
}

int hash_func(std::string str) {
	int res = 0;

	for (int i = 0; i < str.size(); i++) {
		int a = str[i];
		res += a;
	}
	res %= SIZE;

	return res;
}

bool norm_key(std::string value) {
	bool ret_num = 0;
	for (int i = 0; i < SIZE; i++) {
		std::string key = key_wr::keys[i];
		if (key == value) {
			ret_num = 1;
			break;
		}
	}
	return ret_num;
}

int find(HashTable table, std::string str) {
	int index = hash_func(str);
	if (str == table.arr[index]) {
		std::cout << "Индекс найденного ключа: " << index << "\n";
		return index;
	}
	return -1;
}

void add_value(HashTable* table, std::string str) {
	if (!norm_key(str)) {
		std::cout << "Ключ не из списка. \n";
	}
	else {
		int index = find(*table, str);
		if (index != -1) {
			std::cout << "Значение уже существует под индексом: " << index << "\n";
		}
		else {
			index = hash_func(str);
			table->arr[index] = str;
		}
	}
}

void remove(HashTable* table, std::string str) {
	if (!norm_key(str)) {
		std::cout << "Ключ не из списка. \n";
	}
	else {
		int index = find(*table, str);
		if (index == -1) {
			std::cout << "Значение не найдено. " << "\n";
		}
		else {
			index = hash_func(str);
			table->arr[index] = "0";
		}
	}
}

void build_table(HashTable* table) {
	for (int i = 0; i < SIZE; i++) {
		std::string key = key_wr::keys[i];
		add_value(table, key);
	}
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