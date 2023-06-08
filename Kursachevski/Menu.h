#pragma once
#include"Sklad.h"

class Menu {
public:
	void Text_menu();
	void Print_stock_status(Stock* st);
	void Print_section_status(Stock* st);
	void Print_box_status(Stock* st);
	void M_add_sect(Stock* st);
	void M_add_box(Stock* st);
	int Input_for_menu(int stat);
	void M_delete_sect(Stock* st);
	void M_delete_box(Stock* st);
	void M_Fprint_status(Stock* st);
	void M_Fadd_stock(Stock* st);
	void M_destroy(Stock* st);
	void M_add_name(Stock* st);
	void Start();
};