#include <iostream>
using namespace std;

#include <cstring>

#include "string_t.h"
#include "binary_search_tree_t.h"

static void copy_key(key_t &dest, key_t src) {
    dest = src;
}

static key_t compare_key(key_t s1, key_t s2) {
    return s1 - s2;
}

node_t *new_node(key_t key, value_t value) {
    node_t *node = new node_t;
    copy_value(node->value, value);
    copy_key(node->key, key);
    node->parent = node->right = node->left = NULL;
    return node;
}

key_t get_key(node_t *node) {
    return node->key;
}

void print_key(key_t key) {
    cout << key;
}

value_t get_value(node_t *node) {
    return node->value;
}

bst_t get_left(bst_t tree) {
    return tree->left;
}

bst_t get_right(bst_t tree) {
    return tree->right;
}

node_t *get_parent(node_t *node) {
    return node->parent;
}

void insert_elem(bst_t &tree, node_t *node) {
    if(tree == NULL) {
        tree = node;
        return;
    }
    if(compare_key(get_key(node), get_key(tree)) < 0) {
        if(get_left(tree) != NULL)
            insert_elem(tree->left, node);
        else {
            tree->left = node;
            node->parent = tree;
        }
    }
    else {
        if(get_right(tree) != NULL)
            insert_elem(tree->right, node);
        else {
            tree->right = node;
            node->parent = tree;
        }
    }
}

node_t *search(bst_t tree, key_t key) {
    while(tree != NULL) {
        if(compare_key(key, get_key(tree)) == 0)
            return tree;
        if(compare_key(key, get_key(tree)) < 0)
            tree = get_left(tree);
        else
            tree = get_right(tree);
    }
    return NULL;
}

void update_parent(node_t *p, node_t *q) {
    if(p == get_left(get_parent(p)))
        p->parent->left = q;
    else
        p->parent->right = q;
}

void delete_elem(bst_t &tree, node_t *node) {
    node_t *node_to_swap;
    if(get_left(node) == NULL) {
        if(get_right(node) == NULL) //Nodo foglia
            node_to_swap = NULL;
        else //Nodo con solo figlio destro
            node_to_swap = get_right(node);
    }
    else if(get_right(node) == NULL) //Nodo con solo figlio sinistro
        node_to_swap = get_left(node);
    else { //Nodo con due figli
        //Cerco il nodo più grande nel sottoalbero di sinistra
        node_t *tmp = get_left(node);
        while(get_right(tmp) != NULL) //Cerco l'elemento più a destra del sottoalbero di sinistra
            tmp = get_right(tmp);
        if(get_left(tmp) == NULL) //Nodo foglia
            update_parent(tmp, NULL);
        else { //Nodo con solo figlio sinistro
            tmp->parent->right = get_left(tmp);
            tmp->left->parent = get_parent(tmp);
        }
        //Sostituisco tmp a node
        tmp->left = get_left(node);
        tmp->right = get_right(node);
        if(get_right(tmp) != NULL)
            tmp->right->parent = tmp;
        if(get_left(tmp) != NULL)
            tmp->left->parent = tmp;
        node_to_swap = tmp;
    }
    if(node_to_swap != NULL)
        node_to_swap->parent = get_parent(node);
    if(node == tree)
        tree = node_to_swap;
    else
        update_parent(node, node_to_swap);
    delete node;
}