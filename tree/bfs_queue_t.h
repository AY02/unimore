struct bfs_node_t {
    node_t *value;
    bfs_node_t *next;
};

typedef bfs_node_t* list_t;

struct bfs_queue_t {
    list_t head;
    bfs_node_t *tail;
};

bfs_queue_t enqueue(bfs_queue_t, node_t*);
node_t *dequeue(bfs_queue_t& );
node_t *first(bfs_queue_t);
bool is_bfs_queue_empty(bfs_queue_t);
bfs_queue_t new_queue();

static bfs_node_t *new_elem(node_t*);