#ifndef BFS_QUEUE_T_H
#define BFS_QUEUE_T_H


struct bfs_node_t {
    int value;
    bfs_node_t *next;
};

typedef bfs_node_t* list_t;

struct bfs_queue_t {
    list_t head;
    bfs_node_t *tail;
};

bfs_queue_t enqueue(bfs_queue_t, int);
int dequeue(bfs_queue_t& );
int first(bfs_queue_t);
bool is_bfs_queue_empty(bfs_queue_t);
bfs_queue_t new_queue();


#endif