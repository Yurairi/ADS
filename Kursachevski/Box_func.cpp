#include"Sklad.h"

Box::Box() {
	box_id = -1;
	occupancy = 0;
	next = nullptr;
}

Box::Box(int id, bool oc) {
	box_id = id;
	occupancy = oc;
	next = nullptr;
}
	
void Box::Set_id(int id) {
	box_id = id;
}

int Box::Get_id() {
	return box_id;
}
void Box::Set_occupancy(bool new_occupancy) {
	occupancy = new_occupancy;
}
bool Box::Get_occupancy() {
	return occupancy;
}
void Box::Set_next(Box* nex) {
	next = nex;
}
Box* Box::Get_next() {
	if (next) return next;
	else return nullptr;
}