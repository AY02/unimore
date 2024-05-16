#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cfloat>
using namespace std;


#include "bfs_queue_t.h"
#include "priority_queue_t.h"
#include "graph_t.h"
#include "graph_functions.h"


static const int ROOT = -1;

static void dijkistra_init(graph_t graph, int src, float *dist, int *parent) {
	for(int i=0; i<get_dim(graph); i++) {
		dist[i] = FLT_MAX;
		parent[i] = ROOT;
	}
	dist[src-1] = 0;
}

static void prim_init(graph_t graph, int src, float *cost, int *parent) {
    dijkistra_init(graph, src, cost, parent);
}

static void dijkistra_relax(int u, int v, int weight, float *dist, int *parent) {
    if(dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        parent[v] = u + 1;
    }
}

static void prim_relax(int u, int v, int weight, float *cost, int *parent) {
    if(cost[v] > weight) {
        cost[v] = weight;
        parent[v] = u + 1;
    }
}

static int *dijkistra_prim_body(
    graph_t graph,
    int src,
    void (*init)(graph_t, int, float*, int*),
    void (*relax)(int, int, int, float*, int*)
    ) {
    int size = get_dim(graph);
    float *dist = new float[size];
    int *parent = new int[size];
    init(graph, src, dist, parent);

    pq_t pq = NULL;
    for(int i=0; i<size; i++)
        pq = pq_enqueue(pq, i, dist[i]);

    while(!is_pq_empty(pq)) {
        int u = pq_dequeue(pq);
        adj_list_t neighbors = get_adj_list(graph, u+1);
        while(neighbors != NULL) {
            int v = get_adj_node(neighbors);
            float weight = get_adj_weight(neighbors);
            relax(u, v-1, weight, dist, parent);
            pq = decrease_priority(pq, v-1, dist[v-1]);
            neighbors = get_next_adj(neighbors);
        }
    }

    return parent;
}

//Costruisce e ritorna il grafo a partire da un file di testo.
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

//Ritorna true se il grafo e' connesso, falso altrimenti.
bool is_connected(graph_t graph) {
    bool *arrived = connected(graph, 1, false);
    for(int i=0; i<get_dim(graph); i++)
        if(!arrived[i])
            return false;
    return true;
}

//Ritorna un array di bool che indica se un nodo e' stato raggiunto oppure no.
//Se show_spanning_tree e' true e il grafo e' connesso, allora stampa anche l'albero di copertura.
bool *connected(graph_t graph, int src, bool show_spanning_tree) {

    int size = get_dim(graph);
    
    bool *arrived = new bool[size];
    int *parent = new int[size];

    for(int i=0; i<size; i++) {
        arrived[i] = false;
        parent[i] = ROOT;
    }

    bfs_queue_t queue = new_bfs_queue();
    arrived[src-1] = true;
    queue = bfs_enqueue(queue, src);
    while(!is_bfs_queue_empty(queue)) {
        int tmp = bfs_dequeue(queue);
        for(
            adj_node_t *node = get_adj_list(graph, tmp);
            node != NULL;
            node = get_next_adj(node)
        ) {
            int i = get_adj_node(node);
            if(!arrived[i-1]) {
                arrived[i-1] = true;
                parent[i-1] = tmp;
                queue = bfs_enqueue(queue, i);
            }
        }
    }
    
    for(int i=0; i<size; i++)
        if(!arrived[i])
            return arrived;

    if(show_spanning_tree) {
        cout << "Spanning Tree del nodo " << src << ":" << endl;
        print_parent(parent, size);
    }

    return arrived;

}

//Stampa le componenti connesse del grafo (deve essere non orientato).
void print_connected_component(graph_t graph) {

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

        bool *local_arrived = connected(graph, local_src+1, false);
        for(int i=0; i<size; i++) {
            if(local_arrived[i])
                cout << i+1 << " ";
            global_arrived[i] |= local_arrived[i];
        }
        cout << endl;
    }

}

//Stampa le liste di adiacenza del grafo.
void print_adj(graph_t graph) {
    for(int i=1; i<=get_dim(graph); i++) {
        cout << i << ": ";
        adj_list_t list = get_adj_list(graph, i);
        while(list != NULL) {
            cout << "(" << get_adj_node(list) << ", " << get_adj_weight(list) << ")" << " -> ";
            list = get_next_adj(list);
        }
        cout << "NULL" << endl;
    }
}

//Stampa un vettore dei padri.
void print_parent(int *parent, int size) {
    for(int i=1; i<=size; i++)
        if(parent[i-1] != -1)
            cout << "Il padre del nodo " << i << " e' il nodo " << parent[i-1] << endl;
}

//Algoritmo di Dijkistra che ritorna l'albero dei cammini minimi radicato in src.
int *dijkistra(graph_t graph, int src) {
    return dijkistra_prim_body(graph, src, dijkistra_init, dijkistra_relax);
}

//Algoritmo di Prim che ritorna il minimum spanning tree radicato in src.
int *prim(graph_t graph, int src) {
    return dijkistra_prim_body(graph, src, prim_init, prim_relax);
}