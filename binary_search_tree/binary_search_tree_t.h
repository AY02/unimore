typedef int key_t;

struct node_t {

  key_t key;
  value_t value;

  node_t *parent;
  node_t *left;
  node_t *right;

};

typedef node_t* bst_t;


node_t *new_node(key_t, value_t);
key_t get_key(node_t*);
void print_key(key_t);
value_t get_value(node_t*);
bst_t get_left(bst_t);
bst_t get_right(bst_t);
node_t *get_parent(node_t*);
void insert_elem(bst_t &, node_t*);
node_t *search(bst_t, key_t);
void update_parent(node_t*, node_t*);
void delete_elem(bst_t &, node_t*);