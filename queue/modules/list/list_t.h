struct node_t {
  value_t value;
  node_t *next;
};

typedef node_t* list_t;

value_t head(list_t);
list_t tail(list_t);
node_t *new_elem(value_t);
list_t insert_elem(list_t, node_t*);
list_t delete_elem(list_t, node_t*);
node_t *search(list_t, value_t);
list_t copy(list_t);