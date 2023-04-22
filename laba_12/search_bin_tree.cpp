#include"search_bin_tree.h"

branch* Finder(branch* root, int key) {
	branch* temp = root;
	while (temp != nullptr && temp->data != key) {
		if (key < temp->data) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	return temp;
}

void Rand_build(branch** root, int num) {
	while (num) {
		int data_n = rand() % 100;
		Add_data_rec(root, data_n, 0);
		num--;
	}
}

void Add_data_rec(branch** root, int data_n, int fl) {
	if (*root == nullptr && fl) return;
	branch* new_b = new branch;
	new_b->data = data_n;
	new_b->left = new_b->right = new_b->parent = nullptr;
	new_b->count = 1;
	if (*root == nullptr && !fl) { *root = new_b; }
	else if (data_n > (*root)->data) {
		if ((*root)->right == nullptr) {
			(*root)->right = new_b;
			new_b->parent = (*root);
		}
		else {
			Add_data_rec(&((*root)->right), data_n, 1);
		}
	}
	else if (data_n < (*root)->data) {
		if ((*root)->left == nullptr) {
			(*root)->left = new_b;
			new_b->parent = (*root);
		}
		else {
			Add_data_rec(&((*root)->left), data_n, 1);
		}
	}
	else if (data_n == (*root)->data){
		(*root)->count++;
	}
	
}

void Add_data_iter(branch** root, int data_n) {
	branch* new_b = new branch;
	new_b->data = data_n;
	new_b->left = new_b->right = new_b->parent = nullptr;
	new_b->count = 1;

	branch* curr = *root;
	int fl = 1;

	while (curr != nullptr && fl)
	if (data_n > curr->data) {
		if (curr->right == nullptr) {
			curr->right = new_b;
			new_b->parent = curr;
			fl = 0;
		}
		else {
			curr = curr->right;
		}
	}
	else if (data_n < curr->data) {
		if (curr->left == nullptr) {
			curr->left = new_b;
			new_b->parent = curr;
			fl = 0;
		}
		else {
			curr = curr->left;
		}
	}
	else {
		curr->count++;
		fl = 0;
	}
}

void Remove_key(branch** root, int key) {
	branch* curr = Finder((*root), key);
	if (curr == nullptr) {
		cout << "Такого ключа не существует." << "\n";
	}
	else {
		branch* cur_l = curr->left;
		branch* cur_r = curr->right;
		if (curr->left == nullptr && curr->right == nullptr) {
			if (curr != *root) {
				branch* parent = curr->parent; 
				if (parent->left == curr) { parent->left = nullptr; }
				else { parent->right = nullptr; }
			}
			delete curr;
		}
		else if (curr->left != nullptr && curr->right == nullptr) {
			if (curr != *root) {
				branch* parent = curr->parent;
				if (parent->left == curr) { parent->left = cur_l; cur_l->parent = parent; }
				else { parent->right = cur_l; cur_l->parent = parent; }
			}
			delete curr;
		}
		else if (curr->left == nullptr && curr->right != nullptr) {
			if (curr != *root) {
				branch* parent = curr->parent;
				if (parent->left == curr) { parent->left = cur_r; cur_r->parent = parent; }
				else { parent->right = cur_r; cur_r->parent = parent; }
			}
			delete curr;
		}
		else {
			branch* chan = curr->right;
			while (chan->left != nullptr) { chan = chan->left; }
			int rt = chan->data;
			Remove_key(root, chan->data);
			curr->data = rt;
		}
	}
}

void Simm_print_2(branch* root, int level) {
	if (root != nullptr) {
		Simm_print_2(root->right, level + 5);
		if (level == 0) { cout << root->data <<"(" << root->count << ")  " << "  -------------------------  " << '\n'; }
		else { cout << string(level, ' ') << root->data << "(" << root->count << ")  " << '\n'; }
		Simm_print_2(root->left, level + 5);
	}
}

void In_order(const branch* root) {
	if (root == nullptr) return;

	In_order(root->left);
	cout << root->data << '(' << root->count << ")  ";
	In_order(root->right);
}

void Delete(branch* root) {
	if (root != nullptr) {
		Delete(root->right);
		Delete(root->left);
		delete root;
	}
}