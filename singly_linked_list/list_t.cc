#include <iostream>
using namespace std;


#include "value_t.h"
#include "list_t.h"


bool is_empty_list(list_t list) {
  return list == NULL;
}

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
  while(!is_empty_list(list)) {
    if(compare_value(head(list), value) == 0)
      return list;
    list = tail(list);
  }
  return NULL;
}


list_t copy(list_t old_l) {
  list_t new_l = NULL;
  node_t *current;
  node_t *previous = NULL;
  while(!is_empty_list(old_l)) {
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
