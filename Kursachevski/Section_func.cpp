#include"Sklad.h"

Section::Section() {
	head = nullptr;
	tail = nullptr;
	section_id = -1;
	count = 0;
}

Section::Section(int id) {
	head = nullptr;
	tail = nullptr;
	section_id = id;
	count = 0;
}

void Section::Set_section(int id) {
	section_id = id;
	count = 0;
}

int Section::Get_section_id() {
	return section_id;
}

Box* Section::Get_section_head() {
	return head;
}

int Section::Get_box_count() {
	return count;
}

bool Section::Is_Empty() {
	return count == 0;
}

void Section::Add_box(int box_id, bool box_occupancy) {

	if (Find_box(box_id) == -1) {
		Box* new_tail = new Box (box_id, box_occupancy);

		if (count == 0) {
			head = tail = new_tail;
		}
		else {
			tail->Set_next(new_tail);
			tail = new_tail;
		}
		count++;
	}
	else {
		std::cout << "Ячейка с таким номером уже сущетсвует \n";
	}
}

void Section::Delete_box() {
	if (Is_Empty()) {
		std::cout << "Секция пустая. Удаление невозможно. \n";
	}
	else {
		Box* temp = head;
		head = head->Get_next();
		free(temp);
		count--;
	}
}

void Section::Section_status() {
	if (!Is_Empty()) {
		Box* temp = head;

		std::cout <<"Всего ячеек в секции: " << count << "\n";
		for (int i = 1; i < count + 1; i++) {
			std::cout << " ячейка № " << temp->Get_id() << " Состояние = ";
			if (temp->Get_occupancy()) std::cout << "заполнена \n";
			else  std::cout << "не заполнена \n";
			temp = temp->Get_next();
		}
	}
	else {
		std::cout << "Секция пустая. \n";
	}
}

int Section::Find_box(int bx_id) {
	int ret = -1;
	Box* curr = head;
	while (curr != nullptr) {
		if (curr->Get_id() == bx_id) ret = bx_id;
		curr = curr->Get_next();
	}
	return ret;
}

Box* Section::Ret_box(int bx_id) {
	Box* ret = head;
	Box* curr = head;
	while (curr != nullptr) {
		if (curr->Get_id() == bx_id) ret = curr;
		curr = curr->Get_next();
	}
	return ret;
}