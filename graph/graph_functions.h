#ifndef GRAPH_FUNCTIONS_H
#define GRAPH_FUNCTIONS_H


const int ERROR_ARGC = -1;
const int ERROR_FILE = -2;

graph_t g_build(ifstream &, bool, bool);
int g_build_main(int, char*[]);
//bool connected(graph_t, int); //BFS
bool *connected(graph_t, int, bool);
void connected_component(graph_t);


#endif