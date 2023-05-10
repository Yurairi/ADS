#include "Stack.h"

stack* init() {
    stack* head = nullptr;
    return head;
}

stack* init(int data) {
    stack* new_stack = new stack;
    new_stack->data = data;
    new_stack->next = nullptr;
    return new_stack;
}

bool Is_empty(stack* head) {
    bool ret_num = 0;
    if (head == nullptr) ret_num = 1;
    return ret_num;
}

void add_elem(stack** head, int data) {
    stack* new_head = init(data);
    new_head->next = *head;
    *head = new_head;
}
void add_rand_elem(stack** head, int num) {
    for (int i = 0; i < num; i++) {
        add_elem(head, rand() % 10);
    }
}

void move_elem(stack** fir_head, stack** sec_head) {
    if (!Is_empty(*sec_head)) {
        stack* perem = (*sec_head)->next;
        (*sec_head)->next = *fir_head;
        *fir_head = *sec_head;
        *sec_head = perem;
    }
}


void delete_elem(stack** head) {
    stack* per;
    if (!Is_empty(*head)) {
        per = (*head);
        (*head) = (*head)->next;
        free(per);
    }
}

void print_state(stack* head) {
    stack* per = head;
    int n = 1;
    while (per) {
        cout << "Значение " << n << " элемента: ";
        cout << per->data << "\n";
        per = per->next;
        n++;
    }
}

