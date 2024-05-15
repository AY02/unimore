#ifndef VALUE_T_H
#define VALUE_T_H


const int MAX_VALUE_SIZE = 256;

typedef char* value_t;

int compare_value(value_t, value_t);
void print_value(value_t);
void copy_value(value_t &, value_t);
value_t input_value();


#endif