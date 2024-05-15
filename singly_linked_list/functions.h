#ifndef FUNCTIONS_H
#define FUNCTIONS_H


void print_list(list_t);
list_t make_list(int);
void delete_list(list_t &);
int count_occurrences(list_t, value_t);
list_t delete_occurrences(list_t, value_t);


#endif