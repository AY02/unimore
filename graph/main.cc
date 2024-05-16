#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;


#include "graph_t.h"
#include "graph_functions.h"


enum option_t {
    INPUT_FROM_FILE = 1,
    SHOW_GRAPH = 2,
    SHOW_CONNECTED_COMPONENTS = 3,
    CONNECTED_CHECK = 4,
    SHOW_SPANNING_TREE = 5,
    DIJKISTRA = 6,
    PRIM = 7,
    EXIT_PROGRAM = 8
};

int main(int argc, char *argv[]) {

    if(argc != 4) {
        cerr << "Il numero di argomenti non e' corretto." << endl;
        return ERROR_ARGC;
    }

    ifstream f_in(argv[1]);
    if(!f_in.is_open()) {
        cerr << "Errore durante l'apertura del file." << endl;
        return ERROR_FILE;
    }

    bool is_directed = static_cast<bool>(atoi(argv[2]));
    bool is_weighted = static_cast<bool>(atoi(argv[3]));

    int choice;
    graph_t graph;

    while(true) {
        cout << "Menu':" << endl
             << INPUT_FROM_FILE << ": Costruzione grafo da file." << endl
             << SHOW_GRAPH << ": Stampa le liste di adiacenza." << endl
             << SHOW_CONNECTED_COMPONENTS << ": Stampa le componenti connesse." << endl
             << CONNECTED_CHECK << ": Controlla se il grafo e' connesso." << endl
             << SHOW_SPANNING_TREE << ": Stampa l'albero di copertura." << endl
             << DIJKISTRA << ": Stampa l'albero dei cammini minimi con Dijkistra." << endl
             << PRIM << ": Stampa il Minimum Spanning Tree con Prim." << endl
             << EXIT_PROGRAM << ": Esci dal programma." << endl
             << "--> ";
        cin >> choice;
        switch(choice) {
            case INPUT_FROM_FILE:
                if(!f_in.is_open()) {
                    cerr << "Lo stream del file e' stato chiuso e quindi non puoi effettuare l'input." << endl;
                    break;
                }
                cout << "Creo il grafo..." << endl;
                graph = g_build(f_in, is_directed, is_weighted);
                f_in.close();
                cout << "Hai creato un grafo ";
                if(!is_directed)
                    cout << "non ";
                cout << "orientato e ";
                if(!is_weighted)
                    cout << "non ";
                cout << "pesato." << endl;
                break;
            case SHOW_GRAPH:
                cout << "Grafo:" << endl;
                print_adj(graph);
                break;
            case SHOW_CONNECTED_COMPONENTS:
                cout << "Componenti connesse:" << endl;
                print_connected_component(graph);
                break;
            case CONNECTED_CHECK:
                if(is_connected(graph))
                    cout << "Il grafo e' connesso." << endl;
                else
                    cout << "Il grafo non e' connesso." << endl;
                break;
            case SHOW_SPANNING_TREE:
                if(!is_connected(graph)) {
                    cerr << "Il grafo non e' connesso e quindi non ha un albero di copertura." << endl;
                    break;
                }
                {
                    int src;
                    cout << "Inserisci una sorgente da 1 a " << get_dim(graph) << ": ";
                    cin >> src;
                    connected(graph, src, true);
                }
                break;
            case DIJKISTRA:
                {
                    int src;
                    cout << "Inserisci una sorgente da 1 a " << get_dim(graph) << ": ";
                    cin >> src;
                    int *parent = dijkistra(graph, src);
                    cout << "Albero dei cammini minimi del grafo radicato in " << src << ":" << endl;
                    print_parent(parent, get_dim(graph));
                }
                break;
            case PRIM:
                {
                    int src;
                    cout << "Inserisci una sorgente da 1 a " << get_dim(graph) << ": ";
                    cin >> src;
                    int *parent = prim(graph, src);
                    cout << "Minimum Spanning Tree radicato in " << src << ":" << endl;
                    print_parent(parent, get_dim(graph));
                }
                break;
            case EXIT_PROGRAM:
                cout << "Esco dal programma..." << endl;
                return 0;
                break;
            default:
                cerr << "Opzione non disponibile. Scegline un altro." << endl;
                break;
        }
    }
    
    return 0;

}