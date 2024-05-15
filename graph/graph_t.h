#ifndef GRAPH_T_H
#define GRAPH_T_H


struct adj_node_t {
    int node;
    float weight;
    adj_node_t *next;
};

typedef adj_node_t* adj_list_t;

struct graph_t {
    int dim;
    adj_list_t *nodes;
};

graph_t new_graph(int);
void add_arc(graph_t &, int, int, float);
void add_edge(graph_t &, int, int, float);

int get_dim(graph_t);
adj_list_t get_adj_list(graph_t, int);
int get_adj_node(adj_node_t*);
float get_adj_weight(adj_node_t*);
adj_list_t get_next_adj(adj_list_t);


#endif