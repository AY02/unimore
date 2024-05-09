#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

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

    return 0;

}