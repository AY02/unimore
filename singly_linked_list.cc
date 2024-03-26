#include <iostream>
using namespace std;

struct node_t {
    int value;
    node_t *next;
};

//I use an alias to more intuitively abstract the data structure
typedef node_t* list_t;

//PRIMITIVE FUNCTIONS***************************************************************************************************

//Returns the information content of the head
int head(list_t list) {
    return list->value;
}

//Returns the list itself, excluding the head
list_t tail(list_t list) {
    return list->next;
}

//Inserts an element at the head
list_t insert_elem(list_t list, node_t *node) {
    node->next = list;
    return node;
}

//Delete an item from the list (assuming it is there)
list_t delete_elem(list_t list, node_t *node) {
    if(list == node)
        list = tail(list);
    else {
        list_t tmp = list;
        while(tail(tmp) != node)
            tmp = tail(tmp);
        tmp->next = tail(node);
    }
    delete node;
    return list;
}

//Searches for an element in the list that contains that information and returns the first one it finds
node_t *search(list_t list, int value) {
    while(list != NULL) {
        if(head(list) == value)
            return list;
        list = tail(list);
    }
    return NULL;
}

//Copy a list and return the copy
list_t copy(list_t old_l) {
    list_t new_l = NULL;
    node_t *current;
    node_t *previous = NULL;
    while(old_l != NULL) {
        current = new node_t;
        current->value = head(old_l);
        current->next = NULL;
        if(previous == NULL)
            new_l = current;
        else
            previous->next = current;
        previous = current;
        old_l = tail(old_l);
    }
    return new_l;
}

//**********************************************************************************************************************

void print_list(list_t list) {
    while(list != NULL) {
        cout << head(list) << " ";
        list = tail(list);
    }
    cout << endl;
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

void delete_list(list_t &list) {
    while(list != NULL)
        list = delete_elem(list, list);
}

int count(list_t list, int value) {
    int counter = 0;
    while((list=search(list, value)) != NULL) {
        list = tail(list);
        counter++;
    }
    return counter;
}

list_t delete_occurrences(list_t list, int value) {
    node_t* node;
    while((node=search(list, value)) != NULL)
        list = delete_elem(list, node);
    return list;
}

list_t tail_insert_elem(list_t list, node_t *node) {
    if(list == NULL)
        return node;
    node_t *tmp = list;
    while(tail(tmp) != NULL)
        tmp = tail(tmp);
    tmp->next = node;
    return list;
}

list_t delete_tail_elem(list_t list) {
    if(list != NULL) {
        node_t *node = list;
        if(tail(node) == NULL) {
            delete node;
            list = NULL;
        }
        else {
            while(tail(node)->next != NULL)
                node = tail(node);
            delete tail(node);
            node->next = NULL;
        }
    }
    return list;
}

//PRIMITIVE OF ASD*****************************************************************************************************

list_t new_list() {
    return NULL;
}

bool is_empty_list(list_t list) {
    return list == NULL;
}

void insert_next(node_t *node_before, node_t *node) {
    node->next = node_before->next;
    node_before->next = node;
}

node_t *search_pos(list_t list, int i) {
    list_t tmp = list;
    int j = 0;
    while(j<i && tmp!=NULL) {
        tmp = tmp->next;
        j++;
    }
    return tmp;
}

void insert_pos(list_t list, node_t *node, int i) {
    node_t *p = search_pos(list, i-1);
    if(p == NULL)
        return;
    insert_next(p, node);
}

int main() {
    list_t list = new_list();
    if(is_empty_list(list))
        cout << "La lista è vuota." << endl;
    list = make_list(5);

    /*
    0 1 2 3 4
    9 7 3 8 5
    */

    node_t *node = new node_t;
    node->value = 100;
    node->next = NULL;
    
    insert_pos(list, node, 2);
    print_list(list);

    return 0;

}