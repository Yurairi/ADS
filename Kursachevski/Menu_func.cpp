#include"Menu.h"

void Menu::Text_menu() {
	std::cout<< "Выберете необходимое действие\n";
	std::cout<< "1. Вывести состояние склада\n";
	std::cout<< "2. Вывести состояние секции с заданным номером\n";
	std::cout<< "3. Вывести состояние ячейки с заданным номером и заданной секцией\n";
	std::cout<< "4. Добавить секцию\n";
	std::cout<< "5. Добавить ячейку в заданную секцию\n";
	std::cout<< "6. Удалить секцию\n";
	std::cout<< "7. Удалить ячейку в заданной секции\n";
	std::cout<< "0. Завершить работу программы\n";
	std::cout<< "Ввод: ";
}

void Menu::Print_stock_status(Stock* st){
	std::cout << "Текущее состояние склада: \n";
	st->Stock_status();
}

void Menu::Print_section_status(Stock* st) {
	std::cout << "Введите номер секции \n";
	int sect_id = Input_for_menu(0);
	if (st->Find_section(sect_id) != -1) {
		Section* sec = st->Ret_section(sect_id);
		std::cout << "Текущее состояние указанной секции: \n";
		sec->Section_status();
	}
	else {
		std::cout << "Секции с заданным номером не существует \n";
	}
}

void Menu::Print_box_status(Stock* st) {
	std::cout << "Введите номер секции \n";
	int sect_id = Input_for_menu(0);
	if (st->Find_section(sect_id) != -1) {
		Section* sec = st->Ret_section(sect_id);
		std::cout << "Введите номер ячейки\n";
		int bx_id = Input_for_menu(0);
		if (sec->Find_box(bx_id) != 0) {
			Box* bx = sec->Ret_box(bx_id);
			std::cout << "Текущее состояние указанной ячейки: \n";
			if (bx->Get_occupancy()) std::cout << "Ячейка заполнена \n";
			else  std::cout << "Ячейка не заполнена \n";
		}
		else {
			std::cout << "Ячейки с заданным номером не существует \n";
		}
	}
	else {
		std::cout << "Секции с заданным номером не существует \n";
	}

}

void Menu::M_add_sect(Stock* st) {
	std::cout << "Введите номер секции, которую необходимо добавить: \n";
	int new_id = Input_for_menu(0);
	st->Add_section(new_id);
}

void Menu::M_add_box(Stock* st) {
	std::cout << "Введите номер секции, куда необходимо добавить ячейку: \n";
	int sect_id = Input_for_menu(0);
	if (st->Find_section(sect_id) != -1) {
		Section* sec = st->Ret_section(sect_id);
		std::cout << "Введите номер ячейки, которую неоходимо добавить: \n";
		int bx_id = Input_for_menu(0);
		std::cout << "Введите 1, если ячейка заполнена, и 0, если ячейка не заполнена: \n";
		bool bx_oc = Input_for_menu(2);
		sec->Add_box(bx_id, bx_oc);
	}
	else {
		std::cout << "Секции с заданным номером не существует \n";
	}
}

void Menu::M_delete_sect(Stock* st) {
	std::cout << "Введите номер секции, котрую необходимо удалить: \n";
	int sect_id = Input_for_menu(0);
	st->Delete_section(sect_id);
}

void Menu::M_delete_box(Stock* st) {
	std::cout << "Введите номер секции, из которой необходимо удалить ячейку: \n";
	int sect_id = Input_for_menu(0);
	if (st->Find_section(sect_id) != -1) {
		Section* sec = st->Ret_section(sect_id);
		sec->Delete_box();
	}
	else {
		std::cout << "Секции с заданным номером не существует \n";
	}
}
void Menu::Start(){
	Stock st = Stock();
	while (1) {
		Text_menu();
		int ch = Input_for_menu(1);
		if (ch == 1) Print_stock_status(&st);
		else if (ch == 2) Print_section_status(&st);
		else if (ch == 3) Print_box_status(&st);
		else if (ch == 4) M_add_sect(&st);
		else if (ch == 5) M_add_box(&st);
		else if (ch == 6) M_delete_sect(&st);
		else if (ch == 7) M_delete_box(&st);
		else if (ch == 0) break;
	}
}

int Menu::Input_for_menu(int stat) {
	int choice;
	while (!(std::cin >> choice))
	{
		std::cin.clear();
		while (std::cin.get() != '\n') {
			std::cout << "Повторите ввод :" << std::endl;
		}
	}
	if (stat == 1 && (choice > 7 || choice < 0)) {
		std::cout << "Повторите ввод :" << std::endl;
		choice = Input_for_menu(1);
	}
	if (stat == 2 && choice != 1 && choice != 0) {
		std::cout << "Повторите ввод :" << std::endl;
		choice =Input_for_menu(2);
	}
	if (stat == 3 && (choice <= 0 || choice > 10000)) {
		std::cout << "Повторите ввод :" << std::endl;
		choice = Input_for_menu(3);
	}
	return choice;
}
