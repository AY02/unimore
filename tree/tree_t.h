struct node_t {
  value_t value;
  node_t *parent;
  node_t *first_child;
  node_t *next_sibling;
};

typedef node_t* tree_t;

node_t *new_node(value_t);
void insert_child(tree_t, tree_t);
void insert_sibling(node_t*, tree_t);

value_t get_info(node_t*);
node_t *get_parent(node_t*);
node_t *get_first_child(node_t*);
node_t *get_next_sibling(node_t*);