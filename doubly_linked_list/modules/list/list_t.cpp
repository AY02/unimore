#include <iostream>
using namespace std;

#include "../type/int/int_t.h"
#include "list_t.h"


value_t head(list_t list) {
  return list->value;
}

list_t tail(list_t list) {
  return list->next;
}

list_t prev(list_t list) {
  return list->prev;
}

node_t *new_elem(value_t value) {
  node_t *node = new node_t;
  copy_value(node->value, value);
  node->next = node->prev = NULL;
  return node;
}

list_t insert_elem(list_t list, node_t *node) {
  node->next = list;
  if(list != NULL)
    list->prev = node;
  node->prev = NULL;
  return node;
}

list_t delete_elem(list_t list, node_t *node) {
  if(list == node)
    list = tail(list);
  else
    node->prev->next = node->next;
  if(node->next != NULL)
    node->next->prev = node->prev;
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
    else {
      previous->next = current;
      current->prev = previous;
    }
    previous = current;
    old_l = tail(old_l);
  }
  return new_l;
}