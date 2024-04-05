#include <iostream>
using namespace std;

const int ERROR = -1;

struct node_t {
    int value;
    node_t *next;
};
typedef node_t* list_t;
list_t new_list() {
    return NULL;
}
bool is_empty_list(list_t list) {
    return (list == NULL);
}
node_t *new_list_node() {
    node_t *node = new node_t;
    return node;
}
void insert_head(list_t &list, node_t *node) {
    node->next = list;
    list = node;
}
void delete_elem(list_t &list, node_t *node) {
    if(list == node)
        list = list->next;
    else {
        list_t tmp = list;
        while(tmp->next != node)
            tmp = tmp->next;
        tmp->next = node->next;
    }
    delete node;
}

typedef list_t stack_t;
stack_t new_stack() {
    return new_list();
}
bool is_empty_stack(stack_t stack) {
    return is_empty_list(stack);
}
void push(stack_t &stack, int value) {
    node_t *node = new_list_node();
    node->value = value;
    node->next = NULL;
    insert_head(stack, node);
}
int top(stack_t stack) {
    if(is_empty_stack(stack))
        return ERROR;
    return stack->value;
}
int pop(stack_t &stack) {
    if(is_empty_stack(stack))
        return ERROR;
    int value = top(stack);
    delete_elem(stack, stack);
    return value;
}

void print_stack(stack_t stack) {
    while(stack != NULL) {
        cout << stack->value << endl;
        stack = stack->next;
    }
}

int main() {
    
    stack_t stack = new_stack();
    
    if(is_empty_stack(stack)) {
        push(stack, 0);
        push(stack, 1);
        push(stack, 2);
        push(stack, 3);
        print_stack(stack);
        cout << endl;
        cout << pop(stack) << endl;
        cout << endl;
        print_stack(stack);
    }
    
    return 0;
}
