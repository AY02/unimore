#include <iostream>
using namespace std;


#include "bfs_queue_t.h"


static bfs_node_t *bfs_new_elem(int n) {
    bfs_node_t *p = new bfs_node_t;
    p->value = n;
    p->next = NULL;
    return p;
}

bfs_queue_t bfs_enqueue(bfs_queue_t c, int i) {
	bfs_node_t *e = bfs_new_elem(i);
	if(c.tail != NULL)
		c.tail->next = e;
	c.tail = e;
	if(c.head == NULL)
		c.head = c.tail;
	return c;
}

int bfs_dequeue(bfs_queue_t &c) {
	int ris = c.head->value;
	c.head = c.head->next;
	return ris;
}

int bfs_first(bfs_queue_t c) {
	return c.head->value;
}

bool is_bfs_queue_empty(bfs_queue_t c) {
	if(c.head == NULL)
		return true;
	return false;
}

bfs_queue_t new_bfs_queue() {
	bfs_queue_t c = {NULL, NULL};
	return c;
}