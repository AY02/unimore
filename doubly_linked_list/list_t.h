#ifndef LIST_T_H
#define LIST_T_H


struct node_t {
  value_t value;
  node_t *next;
  node_t *prev;
};

typedef node_t* list_t;

value_t head(list_t);
list_t tail(list_t);
list_t prev(list_t);
node_t *new_elem(value_t);
list_t insert_elem(list_t, node_t*);
list_t delete_elem(list_t, node_t*);
node_t *search(list_t, value_t);
list_t copy(list_t);


#endif