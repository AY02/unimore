struct node_t {
  value_t value;
  node_t *parent;
  node_t *left;
  node_t *right;
};

typedef node_t* binary_tree_t;

node_t *new_node(value_t);
void insert_left(binary_tree_t, binary_tree_t);
void insert_right(binary_tree_t, binary_tree_t);

node_t *get_parent(node_t*);
node_t *get_left(node_t*);
node_t *get_right(node_t*);
value_t get_info(node_t*);