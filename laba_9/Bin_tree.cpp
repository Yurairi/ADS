#include"Bin_tree.h"

void Make_tree(branch** root, int n) {
	if (n > 0) {
		int data_n = rand() % 100;

		int left = n / 2;
		int right = n - left - 1;

		branch* new_b = new branch;
		new_b->data = data_n;
		new_b->left = new_b->right = nullptr;
		Make_tree(&(new_b->left), left);
		Make_tree(&(new_b->right), right);
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