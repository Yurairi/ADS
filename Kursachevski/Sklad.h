#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

#define MAX 10

class Box {
private:
	int box_id;
	bool occupancy;
	Box* next;
public:
	Box();
	Box(int id, bool oc);
	void Set_id(int id);
	int Get_id();
	void Set_occupancy(bool occupancy);
	bool Get_occupancy();
	void Set_next(Box* nex);
	Box* Get_next();
};

class Section{
private:
	int section_id;
	Box* head;
	Box* tail;
	int count;
public:
	Section();
	Section(int id);
	void Set_section(int id);
	int Get_section_id();
	int Get_box_count();
	bool Is_Empty();
	void Add_box(int box_id, bool box_occupancy);
	void Delete_box();
	void Section_status();
	int Find_box(int bx_id);
	Box* Ret_box(int bx_id);
	Box* Get_section_head();
};

class Stock {
private:
	std::string name;
	Section sect[MAX]{};
	int count;
public:
	Stock();
	bool Is_Empty();
	bool Is_Full();
	void Add_section(int section_id, bool fl);
	int Find_section(int section_id);
	void Set_name(std::string n);
	void Stock_status_F(const std::string filename);
	void Stock_printf(const std::string filename);
	void Delete_stock();
	void Stock_status();
	void Delete_section(int section_id);
	Section* Ret_section(int section_id);
};