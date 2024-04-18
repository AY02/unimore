#include <iostream>
using namespace std;

#include "../type/int/int_t.h"
#include "../list/list_t.h"
#include "stack_t.h"

stack_t new_stack() {
  return NULL;
}

bool is_empty_stack(stack_t stack) {
  return stack == NULL;
}

stack_t push(stack_t stack, value_t value) {
  node_t *node = new_elem(value);
  stack = insert_elem(stack, node);
  return stack;
}

value_t top(stack_t stack) {
  return stack->value;
}

value_t pop(stack_t &stack) {
  value_t value;
  copy_value(value, top(stack));
  stack = delete_elem(stack, stack);
  return value;
}