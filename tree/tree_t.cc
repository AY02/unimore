#include <iostream>
using namespace std;


#include "value_t.h"
#include "tree_t.h"


node_t *new_node(value_t value) {
  node_t *node = new node_t;
  copy_value(node->value, value);
  node->first_child = node->next_sibling = NULL;
  return node;
}

void insert_child(tree_t parent, tree_t child) {
  child->parent = parent;
  child->next_sibling = get_first_child(parent);
  parent->first_child = child;
}

void insert_sibling(node_t *node, tree_t tree) {
  tree->parent = get_parent(node);
  tree->next_sibling = get_next_sibling(node);
  node->next_sibling = tree;
}

value_t get_info(node_t *node) {
  return node->value;
}

node_t *get_parent(node_t *node) {
  return node->parent;
}

node_t *get_first_child(node_t *node) {
  return node->first_child;
}

node_t *get_next_sibling(node_t *node) {
  return node->next_sibling;
}