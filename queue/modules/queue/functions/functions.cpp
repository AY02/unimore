#include <iostream>
using namespace std;

#include "../../type/int/int_t.h"
#include "../../list/list_t.h"
#include "../../list/functions/functions.h"
#include "../queue_t.h"
#include "functions.h"

void print_queue(queue_t queue) {
  print_list(queue.head);
}