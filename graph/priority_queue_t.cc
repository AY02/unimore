#include <iostream>
using namespace std;


#include "priority_queue_t.h"


static pq_node_t* pq_new_elem(int value, float weight) {
    pq_node_t *node = new pq_node_t;
    node->value = value;
    node->weight = weight;
    node->next = NULL;
    return node;
}

static pq_t pq_tail(pq_t pq) {
	return pq->next;
}

pq_t pq_enqueue(pq_t pq, int value, float weight) {
    pq_node_t *node = pq_new_elem(value, weight);
    if(is_pq_empty(pq) || node->weight < pq->weight) {
        node->next = pq;
        return node;
    }
    pq_t tmp = pq;
    while(pq_tail(tmp) != NULL && pq_tail(tmp)->weight < node->weight)
        tmp = pq_tail(tmp);
    node->next = pq_tail(tmp);
    tmp->next = node;
    return pq;
}

int pq_dequeue(pq_t &pq) {
    int value = pq->value;
    pq_node_t *node = pq;
    pq = pq_tail(pq);
    delete node;
    return value;
}

int min_queue(pq_t pq) {
    return pq->value;
}

pq_t decrease_priority(pq_t pq, int value, float weight) {
    if(is_pq_empty(pq))
        return pq;
    if(pq->value == value) {
        pq->weight = weight;
        return pq;
    }
    pq_t tmp = pq;
    while(pq_tail(tmp) != NULL) {
        if(pq_tail(tmp)->value == value) {
            pq_tail(tmp)->weight = weight;
            if(tmp->weight > pq_tail(tmp)->weight) {
                pq_node_t *node = pq_tail(tmp);
                tmp->next = pq_tail(tmp)->next;
                pq = pq_enqueue(pq, node->value, node->weight);
                delete node;
                return pq;
            }
        }
        tmp = pq_tail(tmp);
    }
    return pq;
}

bool is_pq_empty(pq_t pq) {
    return pq == NULL;
}