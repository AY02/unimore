#include <iostream>
using namespace std;

#include "value_t.h"
#include "list_t.h"
#include "functions.h"

void print_list(list_t list) {
  while(list != NULL) {
    print_value(list->value);
    cout << " ";
    list = tail(list);
  }
  cout << endl;
}