#include <iostream>
using namespace std;

#include "int_t.h"
#include "list_t.h"


value_t head(list_t list) {
  return list->value;
}

list_t tail(list_t list) {
  return list->next;
}

node_t *new_elem(value_t value) {
  node_t *node = new node_t;
  copy_value(node->value, value);
  node->next = NULL;
  return node;
}

list_t insert_elem(list_t list, node_t *node) {
  node->next = list;
  return node;
}

list_t delete_elem(list_t list, node_t *node) {
  if(list == node)
    list = tail(list);
  else {
    list_t tmp = list;
    while(tail(tmp) != node)
      tmp = tail(tmp);
    tmp->next = tail(node);
  }
  delete node;
  return list;
}

node_t *search(list_t list, value_t value) {
  while(list != NULL) {
    if(compare_value(head(list), value) == 1)
      return list;
    list = tail(list);
  }
  return NULL;
}

list_t copy(list_t old_l) {
  list_t new_l = NULL;
  node_t *current;
  node_t *previous = NULL;
  while(old_l != NULL) {
    current = new_elem(head(old_l));
    if(previous == NULL)
      new_l = current;
    else
      previous->next = current;
    previous = current;
    old_l = tail(old_l);
  }
  return new_l;
}
