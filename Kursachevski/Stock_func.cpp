#include"Sklad.h"


Stock::Stock() {
	count = 0;
}

bool Stock::Is_Empty() {
	return count == 0;
}

bool Stock::Is_Full() {
	return count == MAX;
}

void Stock::Add_section(int section_id) {
	if (Is_Full()) {
		std::cout << "Склад заполнен. Добавление невозможно. \n";
	}
	if (!Is_Full() && !Is_Empty()) {
		if (Find_section(section_id) != -1) {
			std::cout << "Секция с заданным номером уже существует \n";
		}
		else {
			Section s = Section(section_id);
			sect[count] = s;
			count++;
		}
	}
	if (Is_Empty()) {
		Section s = Section(section_id);
		sect[0] = s;
		count++;
	}
}

int Stock::Find_section(int section_id) {
	int i = 0;
	if (Is_Empty()) i = -1;
	else {
		while (sect[i].Get_section_id() != section_id && i != MAX) i++;
		if (i == MAX) i = -1;
	}
	return i;
}

void Stock::Stock_status() {
	if (!Is_Empty()) {
		for (int i = 0; i < count; i++) {
			std::cout << i + 1 << " id секции = " << sect[i].Get_section_id() << "\n";
			sect[i].Section_status();
		}
	}
	else {
		std::cout << "Склад пуст. \n";
	}
}

void Stock::Delete_section(int section_id) {
	int num = Find_section(section_id);
	if (num != -1) {
		while (sect[num].Get_section_head() != nullptr) sect[num].Delete_box();
		for (int i = num; i < count; i++) sect[i] = sect[i + 1];
		count--;
	}
	else {
		std::cout << "Заданной секции нет. Удаление не возможно. \n";
	}
}

Section* Stock::Ret_section(int section_id) {
	int i = -1;
	if (!Is_Empty()) {
		while (sect[i].Get_section_id() != section_id && i != MAX) i++;
	}
	return &sect[i];
}