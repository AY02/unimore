#include <iostream>
using namespace std;

struct node_t {
    int value;
    node_t *next;
    node_t *prev;
};

typedef node_t* list_t;

int head(list_t list) {
    return list->value;
}

list_t tail(list_t list) {
    return list->next;
}

list_t prev(list_t list) {
    return list->prev;
}

void print_list(list_t list) {
    while(list != NULL) {
        cout << head(list) << " ";
        list = tail(list);
    }
    cout << endl;
}

list_t insert_elem(list_t list, node_t *node) {
    node->next = list;
    if(list != NULL)
        list->prev = node;
    node->prev = NULL;
    return node;
}

list_t delete_elem(list_t list, node_t *node) {
    if(list == node)
        list = tail(list);
    else
        node->prev->next = node->next;
    if(node->next != NULL)
        node->next->prev = node->prev;
    delete node;
    return list;
}

node_t *search(list_t list, int value) {
    while(list != NULL) {
        if(head(list) == value)
            return list;
        list = tail(list);
    }
    return NULL;
}

list_t make_list(int n) {
    list_t list = NULL;
    int tmp;
    node_t *node;
    for(int i=0; i<n; i++) {
        cin >> tmp;
        node = new node_t;
        node->value = tmp;
        list = insert_elem(list, node);
    }
    return list;
}

int main() {

    return 0;

}