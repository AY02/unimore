typedef list_t stack_t;

stack_t new_stack();
bool is_empty_stack(stack_t);
stack_t push(stack_t, value_t);
value_t top(stack_t);
value_t pop(stack_t &);