#include <iostream>
using namespace std;

#include "../type/int/int_t.h"
#include "../list/list_t.h"
#include "queue_t.h"

queue_t new_queue() {
  return {NULL, NULL};
}

bool is_empty_queue(queue_t queue) {
  return queue.head == NULL;
}

queue_t enqueue(queue_t queue, value_t value) {
  node_t *node = new_elem(value);
  if(queue.tail != NULL)
    queue.tail->next = node;
  queue.tail = node;
  if(queue.head == NULL)
    queue.head = queue.tail;
  return queue;
}

value_t first(queue_t queue) {
  return head(queue.head);
}

value_t dequeue(queue_t &queue) {
  value_t x;
  copy_value(x, first(queue));
  queue.head = tail(queue.head);
  if(queue.head == NULL)
    queue.tail = NULL;
  return x;
}