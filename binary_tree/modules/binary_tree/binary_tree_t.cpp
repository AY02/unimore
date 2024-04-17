#include <iostream>
using namespace std;

#include "../type/char/char_t.h"
#include "binary_tree_t.h"

node_t *new_node(value_t value) {
  node_t *node = new node_t;
  copy_value(node->value, value);
  node->parent = node->right = node->left = NULL;
  return node;
}

void insert_left(binary_tree_t parent, binary_tree_t left) {
  parent->left = left;
  left->parent = parent;
}

void insert_right(binary_tree_t parent, binary_tree_t right) {
  parent->right = right;
  right->parent = parent;
}

node_t *get_parent(node_t *node) {
  return node->parent;
}

node_t *get_left(node_t *node) {
  return node->left;
}

node_t *get_right(node_t *node) {
  return node->right;
}

value_t get_info(node_t *node) {
  return node->value;
}