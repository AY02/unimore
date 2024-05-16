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

bfs_queue_t bfs_enqueue(bfs_queue_t, int);
int bfs_dequeue(bfs_queue_t& );
int bfs_first(bfs_queue_t);
bool is_bfs_queue_empty(bfs_queue_t);
bfs_queue_t new_bfs_queue();


#endif