#include <iostream>
using namespace std;


#include "value_t.h"
#include "list_t.h"
#include "functions.h"


void print_list(list_t list) {
  while(!is_empty_list(list)) {
    print_value(head(list));
    cout << " -> ";
    list = tail(list);
  }
  cout << " NULL" << endl;
}

list_t make_list(int n) {
  list_t list = NULL;
  for(int i=1; i<=n; i++) {
    cout << i << " -> ";
    value_t value = input_value();
    node_t *node = new_elem(value);
    list = insert_elem(list, node);
  }
  return list;
}

void delete_list(list_t &list) {
  while(!is_empty_list(list))
    list = delete_elem(list, list);
}

int count_occurrences(list_t list, value_t value) {
  int n = 0;
  while(search(list, value) != NULL) {
    list = search(list, value);
    list = tail(list);
    n++;
  }
  return n;
}

list_t delete_occurrences(list_t list, value_t value) {
  while(search(list, value) != NULL) {
    node_t *node = search(list, value);
    list = delete_elem(list, node);
  }
  return list;
}