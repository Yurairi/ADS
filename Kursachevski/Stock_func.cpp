#include"Sklad.h"

Stock::Stock() {
	count = 0;
}

void Stock::Set_name(std::string n) {
	name = n;
}

bool Stock::Is_Empty() {
	return count == 0;
}

bool Stock::Is_Full() {
	return count == MAX;
}

void Stock::Add_section(int section_id, bool fl) {
	if (Is_Full()) {
		std::cout << "Склад заполнен. Добавление невозможно. \n";
	}
	if (!Is_Full() && !Is_Empty()) {
		if (Find_section(section_id) != -1) {
			std::cout << "Секция с заданным номером уже существует \n";
		}
		else {
			if (!fl) {
				std::cout << "Введите номер секции до или после которой необходимо произвести добавление: \n";
				int id_n;
				std::cin >> id_n;
				std::cout << "Произвести добавление до - 0, 1 - после: \n";
				bool ff;
				std::cin >> ff;
				Section s = Section(section_id);
				int id_f = Find_section(id_n);
				if (id_f != -1) {
					if (ff == 1) {
						for (int i = count; i > id_f; i--) sect[i] = sect[i - 1];
						sect[id_f + 1] = s;
						count++;
					}
					else {
						for (int i = count; i > id_f - 1; i--) sect[i] = sect[i - 1];
						sect[id_f] = s;
						count++;
					}
				}
				else {
					std::cout << "Заданной секции нет. Добавление не возможно. \n";
				}
			}
			else {
				Section s = Section(section_id);
				sect[count] = s;
				count++;
			}
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
		std::cout << "Наименование склада: " << name << "\n";
		for (int i = 0; i < count; i++) {
			std::cout << " id секции = " << sect[i].Get_section_id() << "\n";
			sect[i].Section_status();
		}
	}
	else {
		std::cout << "Склад " << name << " пуст. \n";
	}
}

void Stock::Delete_section(int section_id) {
	int num = Find_section(section_id);
	if (num != -1) {
		int i;
		while (sect[num].Get_section_head() != nullptr) sect[num].Delete_box();
		for (i = num; i < count; i++) sect[i] = sect[i + 1];
		sect[i] = NULL;
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

void Stock::Delete_stock() {
	int num = 0;
	while (count != 0) {
		while (sect[num].Get_section_head() != nullptr) sect[num].Delete_box();
		sect[num] = NULL;
		count--;
		num++;
	}
}

void Stock::Stock_status_F(std::string filename) {
	Delete_stock();
	std::string line;
	std::ifstream fl(filename);
	if (fl.is_open())
	{
		std::getline(fl, line);
		while (true)
		{
			if (fl.eof()) break;
			int num = 0;
			std::string kod_name = "";
			while (line[num] != ':' && num != line.length() && !isdigit(line[num])) {
				kod_name += line[num];
				num++;
			}
			num += 2;
			if (kod_name == "Stock name") {
				while (num != line.length()) {
					name += line[num];
					num++;
				}
			}
			else if (kod_name == "Section numbers") {
				while (num < line.length()) {
					std::string sec_n = "";
					while (line[num] != ' ' && num != line.length()) {
						sec_n += line[num];
						num++;
					}
					Add_section(std::stoi(sec_n), 1);
					num++;
				}
			}
			else if (kod_name == "Box numbers and status for ") {
				std::string sec_n = "";
				num = 27;
				while (line[num] != ':' && num != line.length()) {
					sec_n += line[num];
					num++;
				}
				num += 2;
				while (num < line.length()) {
					std::string box_n = "";
					std::string box_stat = "";
					while (line[num] != '-' && num != line.length()) {
						box_n += line[num];
						num++;
					}
					while (line[num] != ' ' && num != line.length()) {
						box_stat += line[num];
						num++;
					}
					Section* reter = Ret_section(std::stoi(sec_n));
					reter->Add_box(std::stoi(box_n), std::stoi(box_stat));
					num++;
				}
			}
			std::getline(fl, line);
		}
	}
	else {
		std::cerr << "Не удалось открыть файл ввода. \n";
	}
	fl.close();
}

void  Stock::Stock_printf(const std::string filename) {
	std::string line;
	std::ofstream fl(filename);
	if (fl.is_open())
	{
		fl << "Stock name: " << name << "\n";
		fl << "Section count: " << count << "\n";
		fl << "Section numbers: ";
		for (int i = 0; i < count; i++) {
			fl << sect[i].Get_section_id() << " ";
		}
		fl << "\n";
		for (int i = 0; i < count; i++) {
			fl << "Box count for " << sect[i].Get_section_id() << ": ";
			fl << sect[i].Get_box_count() << "\n";
			fl << "Box numbers and status for " << sect[i].Get_section_id() << ": ";
			Box* bb = sect[i].Get_section_head();
			while(bb != nullptr) {
				
				fl << bb->Get_id() << "-" << bb->Get_occupancy() << " ";
				bb = bb->Get_next();
			}
			fl << "\n";
		}
	}
	else {
		std::cerr << "Не удалось открыть файл вывода. \n";
	}
	fl.close();
}