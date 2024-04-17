struct queue_t {
  node_t *head;
  node_t *tail;
};

queue_t new_queue();
bool is_empty_queue(queue_t);
queue_t enqueue(queue_t, value_t);
value_t first(queue_t);
value_t dequeue(queue_t &);