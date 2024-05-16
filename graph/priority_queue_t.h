#ifndef PRIORITY_QUEUE_T_H
#define PRIORITY_QUEUE_T_H


struct pq_node_t {
    int value;
    float weight;
    pq_node_t *next;
};

typedef pq_node_t* pq_t;

pq_t pq_enqueue(pq_t, int, float);
int pq_dequeue(pq_t &);
int min_queue(pq_t);
pq_t decrease_priority(pq_t, int, float);
bool is_pq_empty(pq_t);


#endif