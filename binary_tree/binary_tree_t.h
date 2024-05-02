struct bt_node_t {
  value_t value;
  bt_node_t *parent;
  bt_node_t *left;
  bt_node_t *right;
};

typedef bt_node_t* binary_tree_t;

bt_node_t *new_node(value_t);
void insert_left(binary_tree_t, binary_tree_t);
void insert_right(binary_tree_t, binary_tree_t);

bt_node_t *get_parent(bt_node_t*);
bt_node_t *get_left(bt_node_t*);
bt_node_t *get_right(bt_node_t*);
value_t get_info(bt_node_t*);