#include <iostream>
using namespace std;


#include "string_t.h"
#include "tree_t.h"
#include "functions.h"
#include "bfs_queue_t.h"


void serialize(tree_t tree) {
  cout << "(";
  print_value(get_info(tree));
  tree_t t = get_first_child(tree);
  while(t != NULL) {
    serialize(t);
    t = get_next_sibling(t);
  }
  cout << ")";
}

int get_height(tree_t tree) {
  if(get_first_child(tree) == NULL)
    return 0;
  int max = 0, max_local;
  tree_t t = get_first_child(tree);
  while(t != NULL) {
    max_local = get_height(t);
    if(max_local > max)
      max = max_local;
    t = get_next_sibling(t);
  }
  return max + 1;
}

int get_size(tree_t tree) {
  int count = 0;
  bfs_queue_t c = new_queue();
  c = enqueue(c, tree);
  while(!is_bfs_queue_empty(c)) {
    node_t *n = dequeue(c);
    count++;
    tree_t tmp = get_first_child(n);
    while(tmp != NULL) {
      c = enqueue(c, tmp);
      tmp = get_next_sibling(tmp);
    }
  }
  return count;
}