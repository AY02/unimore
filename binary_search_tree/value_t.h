#ifndef VALUE_T_H
#define VALUE_T_H


typedef char* value_t;

int compare_value(value_t, value_t);
void print_value(value_t);
void copy_value(value_t &, value_t);


#endif