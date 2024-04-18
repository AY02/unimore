#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

#include "./modules/type/int/int_t.h"
#include "./modules/list/list_t.h"
#include "./modules/stack/stack_t.h"
#include "./modules/stack/functions/functions.h"

int main() {

  stack_t stack = new_stack();
  
  stack = push(stack, 10);
  stack = push(stack, 20);
  stack = push(stack, 30);

  print_stack(stack);

  cout << pop(stack) << endl;

  print_stack(stack);
  
  return 0;

}