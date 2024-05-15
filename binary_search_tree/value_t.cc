#include <iostream>
#include <cstring>
using namespace std;


#include "value_t.h"


int compare_value(value_t str1, value_t str2) {
  return strcmp(str1, str2);
}

void print_value(value_t str) {
  cout << str;
}

void copy_value(value_t &dest, value_t src) {
  dest = new char[strlen(src)];
  strcpy(dest, src);
}