#include <iostream>
using namespace std;

#include "value_t.h"

int compare_value(value_t n1, value_t n2) {
  return n1 == n2;
}

void print_value(value_t n) {
  cout << n;
}

void copy_value(value_t &dest, value_t src) {
  dest = src;
}