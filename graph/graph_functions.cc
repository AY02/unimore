#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


#include "bfs_queue_t.h"
#include "graph_t.h"
#include "graph_functions.h"


graph_t g_build(ifstream &f_in, bool is_directed, bool is_weighted) {

    int dim;
    f_in >> dim;
    graph_t graph = new_graph(dim);

    int tmp_src, tmp_dest;
    float weight;

    if(is_weighted)
        while(f_in >> tmp_src >> tmp_dest >> weight) {
            if(is_directed)
                add_arc(graph, tmp_src, tmp_dest, weight);
            else
                add_edge(graph, tmp_src, tmp_dest, weight);
        }
    else
        while(f_in >> tmp_src >> tmp_dest) {
            if(is_directed)
                add_arc(graph, tmp_src, tmp_dest, 1.0);
            else
                add_edge(graph, tmp_src, tmp_dest, 1.0);
        }

    return graph;

}

int g_build_main(int argc, char *argv[]) {

    if(argc != 4)
        return ERROR_ARGC;

    ifstream f_in(argv[1]);
    if(!f_in.is_open()) {
        cerr << "Errore durante l'apertura del file." << endl;
        return ERROR_FILE;
    }

    int is_directed = atoi(argv[2]);
    int is_weighted = atoi(argv[3]);

    graph_t graph = g_build(f_in, is_directed, is_weighted);

    int dim = get_dim(graph);
    cout << dim << endl;

    for(int i=1; i<=dim; i++) {

        cout << i << ": ";
        adj_list_t list = get_adj_list(graph, i);

        while(list != NULL) {
            cout << "(" << get_adj_node(list) << ", " << get_adj_weight(list) << ")" << " -> ";
            list = get_next_adj(list);
        }

        cout << "NULL" << endl;
        
    }

    f_in.close();

    bool *arrived = connected(graph, 1);
    bool is_connected = true;
    for(int i=0; i<dim; i++)
        if(!arrived[i]) {
            is_connected = false;
            break;
        }
    if(is_connected)
        cout << "Il grafo e' connesso." << endl;
    else
        cout << "Il grafo non e' connesso." << endl;
        
    connected_component(graph);

    return 0;

}

//bool connected(graph_t graph, int src) {
bool *connected(graph_t graph, int src) {

    int size = get_dim(graph);
    
    bool *arrived = new bool[size];
    for(int i=0; i<size; i++)
        arrived[i] = false;

    bfs_queue_t queue = new_queue();
    arrived[src-1] = true;
    queue = enqueue(queue, src);
    while(!is_bfs_queue_empty(queue)) {
        int tmp = dequeue(queue);
        for(
            adj_node_t *node = get_adj_list(graph, tmp);
            node != NULL;
            node = get_next_adj(node)
        ) {
            int i = get_adj_node(node);
            if(!arrived[i-1]) {
                arrived[i-1] = true;
                queue = enqueue(queue, i);
            }
        }
    }

    /*
    for(int i=0; i<size; i++)
        if(!arrived[i])
            return false;
    return true;
    */
    return arrived;

}

void connected_component(graph_t graph) {

    int size = get_dim(graph);

    bool *global_arrived = new bool[size];
    for(int i=0; i<size; i++)
        global_arrived[i] = false;
    
    while(true) {
        int local_src = -1;
        for(int i=0; i<size; i++)
            if(!global_arrived[i]) {
                local_src = i;
                break;
            }
        if(local_src == -1)
            break;

        bool *local_arrived = connected(graph, local_src+1);
        cout << "Componente connessa trovata: ";
        for(int i=0; i<size; i++) {
            if(local_arrived[i])
                cout << i+1 << " ";
            global_arrived[i] |= local_arrived[i];
        }
        cout << endl;
    }

}