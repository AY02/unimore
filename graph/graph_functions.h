#ifndef GRAPH_FUNCTIONS_H
#define GRAPH_FUNCTIONS_H


const int ERROR_ARGC = -1;
const int ERROR_FILE = -2;

graph_t g_build(ifstream &, bool, bool);
bool is_connected(graph_t);
bool *connected(graph_t, int, bool); //BFS
void print_connected_component(graph_t);
void print_adj(graph_t);
void print_parent(int *, int);
int *dijkistra(graph_t, int);
int *prim(graph_t, int);


#endif