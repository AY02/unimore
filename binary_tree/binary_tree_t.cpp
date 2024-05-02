#include <iostream>
using namespace std;

#include "char_t.h"
#include "binary_tree_t.h"

bt_node_t *new_node(value_t value) {
  bt_node_t *node = new bt_node_t;
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

bt_node_t *get_parent(bt_node_t *node) {
  return node->parent;
}

bt_node_t *get_left(bt_node_t *node) {
  return node->left;
}

bt_node_t *get_right(bt_node_t *node) {
  return node->right;
}

value_t get_info(bt_node_t *node) {
  return node->value;
}