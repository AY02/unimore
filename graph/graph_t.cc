#include <iostream>
using namespace std;


#include "graph_t.h"


graph_t new_graph(int dim) {
    adj_list_t *nodes = new adj_list_t[dim];
    for(int i=0; i<dim; i++)
        nodes[i] = NULL;
    return {dim, nodes};
}

void add_arc(graph_t &graph, int src, int dest, float weight) {
    adj_node_t *adj_node = new adj_node_t;
    adj_node->node = dest - 1;
    adj_node->weight = weight;
    adj_node->next = get_adj_list(graph, src);
    graph.nodes[src-1] = adj_node;
}

void add_edge(graph_t &graph, int src, int dest, float weight) {
    add_arc(graph, src, dest, weight);
    add_arc(graph, dest, src, weight);
}

int get_dim(graph_t graph) {
    return graph.dim;
}

adj_list_t get_adj_list(graph_t graph, int node) {
    return graph.nodes[node-1];
}

int get_adj_node(adj_node_t *adj_node) {
    return adj_node->node + 1;
}

float get_adj_weight(adj_node_t *adj_node) {
	return adj_node->weight;
}

adj_list_t get_next_adj(adj_list_t adj_list) {
    return adj_list->next;
}