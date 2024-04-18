#include <iostream>
using namespace std;

#include "string_t.h"
#include "binary_search_tree_t.h"
#include "functions.h"

void print_bst(bst_t tree) {
    if(tree == NULL)
        return;
    if(get_left(tree) != NULL)
        print_bst(get_left(tree));
    print_key(get_key(tree));
    cout << " ";
    print_value(get_value(tree));
    cout << endl;
    if(get_right(tree) != NULL)
        print_bst(get_right(tree));
}