#include <iostream>
using namespace std;

#include <cstring>

#include "string_t.h"
#include "binary_search_tree_t.h"

static key_t copy_key(key_t &dest, key_t src) {
    dest = src;
    return dest;
}

static key_t compare_key(key_t s1, key_t s2) {
    return s1 - s2;
}

bst_node_t *bst_new_node(key_t key, value_t value) {
    bst_node_t *node = new bst_node_t;
    copy_value(node->value, value);
    copy_key(node->key, key);
    node->parent = node->right = node->left = NULL;
    return node;
}

key_t get_key(bst_node_t *node) {
    return node->key;
}

value_t get_value(bst_node_t *node) {
    return node->value;
}

bst_t get_left(bst_t tree) {
    return tree->left;
}

bst_t get_right(bst_t tree) {
    return tree->right;
}

bst_node_t *get_parent(bst_node_t *node) {
    return node->parent;
}

void bst_insert(bst_t &tree, bst_node_t *node) {
    if(tree == NULL) {
        tree = node;
        return;
    }
    if(compare_key(get_key(node), get_key(tree)) < 0) {
        if(get_left(tree) != NULL)
            bst_insert(tree->left, node);
        else {
            tree->left = node;
            node->parent = tree;
        }
    }
    else {
        if(get_right(tree) != NULL)
            bst_insert(tree->right, node);
        else {
            tree->right = node;
            node->parent = tree;
        }
    }
}

bst_node_t *bst_search(bst_t tree, key_t key) {
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

static void update_parent_child(bst_node_t *old_child, bst_node_t *new_child) {
    if(old_child == get_left(get_parent(old_child))) //il vecchio figlio e' il figlio sinistro
        old_child->parent->left = new_child;
    else //Il vecchio figlio e' il figlio destro
        old_child->parent->right = new_child;
}

void bst_delete(bst_t &tree, bst_node_t *node) {

    if(tree == NULL || node == NULL)
        return;

    bst_node_t *new_child;

    if(get_left(node) == NULL && get_right(node) == NULL) //Il nodo e' una foglia
        new_child = NULL;
    else if(get_left(node) == NULL && get_right(node) != NULL) //Il nodo ha solo il figlio destro
        new_child = get_right(node);
    else if(get_left(node) != NULL && get_right(node) == NULL) //Il nodo ha solo il figlio sinistro
        new_child = get_left(node);
    else {
        //Il nodo ha due figli: Cerco il nodo più grande nel sottoalbero di sinistra
        //Tale nodo è quello piu' a destra nel sottoalbero di sinistra
        bst_node_t *max_left_node = get_left(node);
        while(get_right(max_left_node) != NULL)
            max_left_node = get_right(max_left_node);
        if(get_left(max_left_node) == NULL) //Il nodo e' una foglia
            update_parent_child(max_left_node, NULL);
        else { //Il nodo ha solo il figlio sinistro
            max_left_node->parent->right = get_left(max_left_node);
            max_left_node->left->parent = get_parent(max_left_node);
        }
        //Sostituisco il nuovo nodo con quello vecchio
        max_left_node->left = get_left(node);
        max_left_node->right = get_right(node);
        max_left_node->left->parent = max_left_node;
        max_left_node->right->parent = max_left_node;
        new_child = max_left_node;
    }

    if(new_child != NULL)
        new_child->parent = get_parent(node);

    if(node == tree)
        tree = new_child;
    else
        update_parent_child(node, new_child);

    delete node;

}

void print_key(key_t key) {
    cout << key;
}