#include <iostream>
using namespace std;

#include "string_t.h"
#include "binary_search_tree_t.h"
#include "functions.h"

int main() {
  
  const int MAX_SIZE_VALUE = 50;

  bst_t tree = NULL;
  bool not_done = true;
  int key;
  char value[MAX_SIZE_VALUE+1];

  while(not_done) {
    cout << "Inserisci la chiave: ";
    cin >> key;
    cout << "Inserisci il valore informativo: ";
    cin >> value;
    bst_node_t *node = bst_new_node(key, value);
    cout << "Nodo creato: (" << key << ", " << value << ")" << endl;
    bst_insert(tree, node);
    cout << "Vuoi continuare?(Si: 1, No: 0): ";
    cin >> not_done;
  }

  print_bst(tree);

  bst_delete(tree, bst_search(tree, 12));

  print_bst(tree);

  return 0;

}