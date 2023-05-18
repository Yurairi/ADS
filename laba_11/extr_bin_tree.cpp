#include "extr_bin_tree.h"

branch* Finder(branch* root, int search_data) {
	branch* ret = nullptr;
	if (root != nullptr) {
		int level = 0;
		stack* head = new stack;
		head->data = root;
		branch* temp = root;
		while (temp != nullptr || head->level >= 0) {
			while (temp) {
				stack* cur = new stack;
				cur->next = head;
				cur->level = level;
				cur->data = temp;
				head = cur;
				temp = temp->left;
				level++;
			}

			level = head->level;
			temp = head->data;
			if (temp->data == search_data) { ret = temp; break; }

			stack* del = head;
			head = head->next;
			delete del;

			temp = temp->right;
			level++;
		}
		delete head;
		return ret;
	}
}

void Add_data(branch** root, int data_n) {
	branch* new_b = new branch;
	new_b->data = data_n;
	new_b->left = new_b->right = nullptr;
	
	if (*root != nullptr) {
		cout << "Введите значение, после которого необходимо произвести добавление:" << '\n';
		int f_data = input_for_menu(0);
		branch* node = Finder(*root, f_data);
		if (node != nullptr) {
			branch* right = node->right;
			branch* left = node->left;
			if (right != nullptr && left != nullptr) {
				cout << "Добавление не возможно. Дерево имеет максимальное число потомков." << '\n';
			}
			else if (right == nullptr && left != nullptr) {
				node->right = new_b;
			}
			else if (left == nullptr && right != nullptr) {
				node->left = new_b;
			}
			else if (left == nullptr && right == nullptr) {
				cout << "Добавить правого потомка - 1, левого - 0" << '\n';
				int num = input_for_menu(2);
				if (num) { node->right = new_b; }
				else { node->left = new_b; }
			}
		}
		else {
			cout << "Такого значения нет." << '\n';
		}	
	}
	else {
		*root = new_b;
	}
}

void Print_in_order(branch* root, int level) {
	if (root != nullptr) {
		cout << string(level, ' ') << root->data << '\n';
		Print_in_order(root->left, level + 5);
		Print_in_order(root->right, level + 5);
	}
}

void Simm_print_1(branch* root, int level) {
	if (root != nullptr) {
		Simm_print_1(root->left, level + 5);
		if (level == 0) { cout << root->data << "  -------------------------  " << '\n'; }
		else { cout << string(level, ' ') << root->data << '\n'; }
		Simm_print_1(root->right, level + 5);
	}
}

void Simm_print_2(branch* root, int level) {
	if (root != nullptr) {
		Simm_print_2(root->right, level + 5);
		if (level == 0) { cout << root->data << "  -------------------------  " << '\n'; }
		else { cout << string(level, ' ') << root->data << '\n'; }
		Simm_print_2(root->left, level + 5);
	}
}

void Delete(branch* root) {
	if (root != nullptr) {
		Delete(root->right);
		Delete(root->left);
		delete root;
	}
}