#ifndef BINARY_SEARCH_TREE_T_H
#define BINARY_SEARCH_TREE_T_H


typedef int key_t;

struct bst_node_t {

  key_t key;
  value_t value;

  bst_node_t *parent;
  bst_node_t *left;
  bst_node_t *right;

};

typedef bst_node_t* bst_t;


bst_node_t *bst_new_node(key_t, value_t);

key_t get_key(bst_node_t*);
value_t get_value(bst_node_t*);
bst_t get_left(bst_t);
bst_t get_right(bst_t);
bst_node_t *get_parent(bst_node_t*);

void bst_insert(bst_t &, bst_node_t*);
bst_node_t *bst_search(bst_t, key_t);
void bst_delete(bst_t &, bst_node_t*);

void print_key(key_t);


#endif