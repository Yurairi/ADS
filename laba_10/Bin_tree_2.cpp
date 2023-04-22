#include"Bin_tree_2.h"

void Make_tree(branch** root, int n, bool fl) {
	if (n > 0) {
		int data_n = rand() % 100;
		//cout << data_n << "  ";

		int left = n / 2;
		int right = n - left - 1;

		branch* new_b = new branch;
		new_b->data = data_n;
		new_b->left = new_b->right = nullptr;
		Make_tree(&(new_b->left), left, 0);
		Make_tree(&(new_b->right), right, 0);
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

void Simm_print_iter(branch* root) {
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
			if (level == 0) { cout << root->data << "  -------------------------  " << '\n'; }
			else { cout << string(level * 5, ' ') << temp->data << '\n'; }

			stack* del = head;
			head = head->next;
			delete del;

			temp = temp->right;
			level++;
		}
		delete head;
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