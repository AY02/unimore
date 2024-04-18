#include <iostream>
using namespace std;

#include "../../type/int/int_t.h"
#include "../../list/list_t.h"
#include "../../list/functions/functions.h"
#include "../stack_t.h"
#include "functions.h"

void print_stack(stack_t stack) {
  print_list(stack);
}