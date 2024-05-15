#include <iostream>
using namespace std;


#include "value_t.h"


int compare_value(value_t c1, value_t c2) {
  return c1 == c2;
}

void print_value(value_t c) {
  cout << c;
}

void copy_value(value_t &dest, value_t src) {
  dest = src;
}